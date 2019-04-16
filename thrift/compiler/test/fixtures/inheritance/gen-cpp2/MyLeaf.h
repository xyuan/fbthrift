/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <folly/futures/Future.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp2/ServiceIncludes.h>
#include <thrift/lib/cpp2/async/FutureRequest.h>
#include <thrift/lib/cpp2/async/HeaderChannel.h>
#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/MyLeafAsyncClient.h"
#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/MyNode.h"

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace cpp2 {

class MyLeafSvAsyncIf {
 public:
  virtual ~MyLeafSvAsyncIf() {}
  virtual void async_tm_do_leaf(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) = 0;
  virtual folly::Future<folly::Unit> future_do_leaf() = 0;
  virtual folly::SemiFuture<folly::Unit> semifuture_do_leaf() = 0;
};

class MyLeafAsyncProcessor;

class MyLeafSvIf : public MyLeafSvAsyncIf, virtual public  ::cpp2::MyNodeSvIf {
 public:
  typedef MyLeafAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;
  virtual void do_leaf();
  folly::Future<folly::Unit> future_do_leaf() override;
  folly::SemiFuture<folly::Unit> semifuture_do_leaf() override;
  void async_tm_do_leaf(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) override;
};

class MyLeafSvNull : public MyLeafSvIf, virtual public  ::cpp2::MyNodeSvIf {
 public:
  void do_leaf() override;
};

class MyLeafAsyncProcessor : public  ::cpp2::MyNodeAsyncProcessor {
 public:
  const char* getServiceName() override;
  using BaseAsyncProcessor =  ::cpp2::MyNodeAsyncProcessor;
 protected:
  MyLeafSvIf* iface_;
  folly::Optional<std::string> getCacheKey(folly::IOBuf* buf, apache::thrift::protocol::PROTOCOL_TYPES protType) override;
 public:
  void process(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
 protected:
  bool isOnewayMethod(const folly::IOBuf* buf, const apache::thrift::transport::THeader* header) override;
 private:
  static std::unordered_set<std::string> onewayMethods_;
  static std::unordered_map<std::string, int16_t> cacheKeyMap_;
 public:
  using BinaryProtocolProcessFunc = ProcessFunc<MyLeafAsyncProcessor, apache::thrift::BinaryProtocolReader>;
  using BinaryProtocolProcessMap = ProcessMap<BinaryProtocolProcessFunc>;
  static const MyLeafAsyncProcessor::BinaryProtocolProcessMap& getBinaryProtocolProcessMap();
 private:
  static const MyLeafAsyncProcessor::BinaryProtocolProcessMap binaryProcessMap_;
 public:
  using CompactProtocolProcessFunc = ProcessFunc<MyLeafAsyncProcessor, apache::thrift::CompactProtocolReader>;
  using CompactProtocolProcessMap = ProcessMap<CompactProtocolProcessFunc>;
  static const MyLeafAsyncProcessor::CompactProtocolProcessMap& getCompactProtocolProcessMap();
 private:
  static const MyLeafAsyncProcessor::CompactProtocolProcessMap compactProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_do_leaf(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_do_leaf(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_do_leaf(int32_t protoSeqId, apache::thrift::ContextStack* ctx);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_do_leaf(std::unique_ptr<apache::thrift::ResponseChannelRequest> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  MyLeafAsyncProcessor(MyLeafSvIf* iface) :
       ::cpp2::MyNodeAsyncProcessor(iface),
      iface_(iface) {}

  virtual ~MyLeafAsyncProcessor() {}
};

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
