/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef THRIFT_ASYNC_REQUESTCHANNEL_H_
#define THRIFT_ASYNC_REQUESTCHANNEL_H_ 1

#include <chrono>
#include <functional>
#include <memory>

#include <glog/logging.h>

#include <folly/ExceptionWrapper.h>
#include <folly/Function.h>
#include <folly/String.h>
#include <folly/fibers/FiberManager.h>
#include <folly/io/IOBufQueue.h>
#include <folly/io/async/EventBase.h>
#include <folly/io/async/Request.h>
#include <thrift/lib/cpp/EventHandlerBase.h>
#include <thrift/lib/cpp/Thrift.h>
#include <thrift/lib/cpp/concurrency/Thread.h>
#include <thrift/lib/cpp2/async/MessageChannel.h>
#include <thrift/lib/cpp2/async/RequestCallback.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>
#include <thrift/lib/cpp2/transport/core/EnvelopeUtil.h>
#include <thrift/lib/cpp2/transport/core/RpcMetadataUtil.h>
#include <thrift/lib/cpp2/util/Checksum.h>
#include <thrift/lib/thrift/gen-cpp2/RpcMetadata_types.h>

namespace folly {
class IOBuf;
}

namespace apache {
namespace thrift {

class StreamClientCallback;
class SinkClientCallback;

struct SerializedRequest {
  explicit SerializedRequest(std::unique_ptr<folly::IOBuf> buffer_)
      : buffer(std::move(buffer_)) {}

  std::unique_ptr<folly::IOBuf> buffer;
};

struct LegacySerializedRequest {
  /* implicit */ LegacySerializedRequest(std::unique_ptr<folly::IOBuf> buffer_)
      : buffer(std::move(buffer_)) {}

  LegacySerializedRequest(
      uint16_t protocolId,
      folly::StringPiece methodName,
      SerializedRequest&& serializedRequest);

  std::unique_ptr<folly::IOBuf> buffer;
};

/**
 * RequestChannel defines an asynchronous API for request-based I/O.
 */
class RequestChannel : virtual public folly::DelayedDestruction {
 protected:
  ~RequestChannel() override {}

 public:
  /**
   * ReplyCallback will be invoked when the reply to this request is
   * received.  TRequestChannel is responsible for associating requests with
   * responses, and invoking the correct ReplyCallback when a response
   * message is received.
   *
   * cb must not be null.
   */
  void sendRequestAsync(
      apache::thrift::RpcOptions&,
      folly::StringPiece methodName,
      SerializedRequest&&,
      std::shared_ptr<apache::thrift::transport::THeader>,
      RequestClientCallback::Ptr,
      RpcKind kind);

  void sendRequestAsync(
      apache::thrift::RpcOptions&,
      folly::StringPiece methodName,
      SerializedRequest&&,
      std::shared_ptr<apache::thrift::transport::THeader>,
      SinkClientCallback*);
  /**
   * ReplyCallback will be invoked when the reply to this request is
   * received.  TRequestChannel is responsible for associating requests with
   * responses, and invoking the correct ReplyCallback when a response
   * message is received.
   *
   * cb must not be null.
   */
  virtual void sendRequestResponse(
      RpcOptions&,
      folly::StringPiece methodName,
      SerializedRequest&&,
      std::shared_ptr<apache::thrift::transport::THeader>,
      RequestClientCallback::Ptr) = 0;

  void sendRequestResponse(
      RpcOptions&,
      LegacySerializedRequest&&,
      std::shared_ptr<apache::thrift::transport::THeader>,
      RequestClientCallback::Ptr);

  /* Similar to sendRequest, although replyReceived will never be called
   *
   * Null RequestCallback is allowed for oneway requests
   */
  virtual void sendRequestNoResponse(
      RpcOptions&,
      folly::StringPiece methodName,
      SerializedRequest&&,
      std::shared_ptr<apache::thrift::transport::THeader>,
      RequestClientCallback::Ptr) = 0;

  void sendRequestNoResponse(
      RpcOptions&,
      LegacySerializedRequest&&,
      std::shared_ptr<apache::thrift::transport::THeader>,
      RequestClientCallback::Ptr);

  /**
   * ReplyCallback will be invoked when the reply to this request is
   * received.  RequestChannel is responsible for associating requests with
   * responses, and invoking the correct ReplyCallback when a response
   * message is received. A response to this request may contain a stream.
   *
   * cb must not be null.
   */
  virtual void sendRequestStream(
      RpcOptions& rpcOptions,
      folly::StringPiece methodName,
      SerializedRequest&&,
      std::shared_ptr<transport::THeader> header,
      StreamClientCallback* clientCallback);

  virtual void sendRequestSink(
      RpcOptions& rpcOptions,
      folly::StringPiece methodName,
      SerializedRequest&&,
      std::shared_ptr<transport::THeader> header,
      SinkClientCallback* clientCallback);

  virtual void setCloseCallback(CloseCallback*) = 0;

  virtual folly::EventBase* getEventBase() const = 0;

  virtual uint16_t getProtocolId() = 0;
};

template <bool oneWay>
class ClientSyncCallback : public RequestClientCallback {
 public:
  explicit ClientSyncCallback(ClientReceiveState* rs) : rs_(rs) {}

  void waitUntilDone(folly::EventBase* evb) {
    if (evb) {
      if (!evb->inRunningEventBaseThread() || !folly::fibers::onFiber()) {
        while (!doneBaton_.ready()) {
          evb->drive();
        }
      }
    }
    doneBaton_.wait();
  }

  void onRequestSent() noexcept override {
    if (oneWay) {
      doneBaton_.post();
    }
  }
  void onResponse(ClientReceiveState&& rs) noexcept override {
    assert(rs.buf());
    assert(!oneWay);
    *rs_ = std::move(rs);
    doneBaton_.post();
  }
  void onResponseError(folly::exception_wrapper ex) noexcept override {
    *rs_ = ClientReceiveState(std::move(ex), nullptr);
    doneBaton_.post();
  }

  bool isInlineSafe() const override {
    return true;
  }

  bool isSync() const override {
    return true;
  }

 private:
  ClientReceiveState* rs_;
  folly::fibers::Baton doneBaton_;
};

inline StreamClientCallback* createStreamClientCallback(
    RequestClientCallback::Ptr requestCallback,
    int32_t bufferSize) {
  DCHECK(requestCallback->isInlineSafe());
  class RequestClientCallbackWrapper
      : public detail::ClientStreamBridge::FirstResponseCallback {
   public:
    RequestClientCallbackWrapper(
        RequestClientCallback::Ptr requestCallback,
        int32_t bufferSize)
        : requestCallback_(std::move(requestCallback)),
          bufferSize_(bufferSize) {}

    void onFirstResponse(
        FirstResponsePayload&& firstResponse,
        detail::ClientStreamBridge::ClientPtr clientStreamBridge) override {
      auto tHeader = std::make_unique<transport::THeader>();
      tHeader->setClientType(THRIFT_HTTP_CLIENT_TYPE);
      detail::fillTHeaderFromResponseRpcMetadata(
          firstResponse.metadata, *tHeader);
      requestCallback_.release()->onResponse(ClientReceiveState(
          static_cast<uint16_t>(-1),
          std::move(firstResponse.payload),
          std::move(tHeader),
          nullptr,
          std::move(clientStreamBridge),
          bufferSize_));
      delete this;
    }

    void onFirstResponseError(folly::exception_wrapper ew) override {
      requestCallback_.release()->onResponseError(std::move(ew));
      delete this;
    }

   private:
    RequestClientCallback::Ptr requestCallback_;
    const int32_t bufferSize_;
  };

  return detail::ClientStreamBridge::create(
      new RequestClientCallbackWrapper(std::move(requestCallback), bufferSize));
}

template <class Protocol>
SerializedRequest preprocessSendT(
    Protocol* prot,
    apache::thrift::RpcOptions& rpcOptions,
    apache::thrift::ContextStack& ctx,
    apache::thrift::transport::THeader& header,
    folly::FunctionRef<void(Protocol*)> writefunc,
    folly::FunctionRef<size_t(Protocol*)> sizefunc) {
  return folly::fibers::runInMainContext([&] {
    size_t bufSize = sizefunc(prot);
    folly::IOBufQueue queue(folly::IOBufQueue::cacheChainLength());

    // Preallocate small buffer headroom for transports metadata & framing.
    constexpr size_t kHeadroomBytes = 128;
    auto buf = folly::IOBuf::create(kHeadroomBytes + bufSize);
    buf->advance(kHeadroomBytes);
    queue.append(std::move(buf));

    prot->setOutput(&queue, bufSize);
    auto guard = folly::makeGuard([&] { prot->setOutput(nullptr); });
    try {
      ctx.preWrite();
      writefunc(prot);
      ::apache::thrift::SerializedMessage smsg;
      smsg.protocolType = prot->protocolType();
      smsg.buffer = queue.front();
      ctx.onWriteData(smsg);
      ctx.postWrite(queue.chainLength());
    } catch (const apache::thrift::TException& ex) {
      ctx.handlerErrorWrapped(
          folly::exception_wrapper(std::current_exception(), ex));
      throw;
    }

    if (rpcOptions.getEnableChecksum()) {
      header.setCrc32c(apache::thrift::checksum::crc32c(*queue.front()));
    }

    return SerializedRequest(queue.move());
  });
}

template <class Protocol>
void clientSendT(
    Protocol* prot,
    apache::thrift::RpcOptions& rpcOptions,
    RequestClientCallback::Ptr callback,
    apache::thrift::ContextStack& ctx,
    std::shared_ptr<apache::thrift::transport::THeader> header,
    RequestChannel* channel,
    const char* methodName,
    folly::FunctionRef<void(Protocol*)> writefunc,
    folly::FunctionRef<size_t(Protocol*)> sizefunc,
    RpcKind kind) {
  auto request =
      preprocessSendT(prot, rpcOptions, ctx, *header, writefunc, sizefunc);
  channel->sendRequestAsync(
      rpcOptions,
      methodName,
      std::move(request),
      std::move(header),
      std::move(callback),
      kind);
}

template <class Protocol>
void clientSendT(
    Protocol* prot,
    apache::thrift::RpcOptions& rpcOptions,
    SinkClientCallback* callback,
    apache::thrift::ContextStack& ctx,
    std::shared_ptr<apache::thrift::transport::THeader> header,
    RequestChannel* channel,
    const char* methodName,
    folly::FunctionRef<void(Protocol*)> writefunc,
    folly::FunctionRef<size_t(Protocol*)> sizefunc) {
  auto request =
      preprocessSendT(prot, rpcOptions, ctx, *header, writefunc, sizefunc);
  channel->sendRequestAsync(
      rpcOptions,
      methodName,
      std::move(request),
      std::move(header),
      std::move(callback));
}

} // namespace thrift
} // namespace apache

#endif // #ifndef THRIFT_ASYNC_REQUESTCHANNEL_H_
