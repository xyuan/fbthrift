/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/fatal/gen-cpp2/service2.h"
#include "thrift/compiler/test/fixtures/fatal/gen-cpp2/service2.tcc"

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>

namespace test_cpp2 { namespace cpp_reflection {
std::unique_ptr<apache::thrift::AsyncProcessor> service2SvIf::getProcessor() {
  return std::make_unique<service2AsyncProcessor>(this);
}

void service2SvIf::methodA() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodA");
}

folly::SemiFuture<folly::Unit> service2SvIf::semifuture_methodA() {
  return apache::thrift::detail::si::semifuture([&] { return methodA(); });
}

folly::Future<folly::Unit> service2SvIf::future_methodA() {
  return apache::thrift::detail::si::future(semifuture_methodA(), getThreadManager());
}


void service2SvIf::async_tm_methodA(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] { return future_methodA(); });
}

void service2SvIf::methodB(int32_t /*x*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*y*/, double /*z*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodB");
}

folly::SemiFuture<folly::Unit> service2SvIf::semifuture_methodB(int32_t x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> y, double z) {
  return apache::thrift::detail::si::semifuture([&] { return methodB(x, std::move(y), z); });
}

folly::Future<folly::Unit> service2SvIf::future_methodB(int32_t x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> y, double z) {
  return apache::thrift::detail::si::future(semifuture_methodB(x, std::move(y), z), getThreadManager());
}


void service2SvIf::async_tm_methodB(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback, int32_t x, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> y, double z) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] { return future_methodB(x, std::move(y), z); });
}

int32_t service2SvIf::methodC() {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodC");
}

folly::SemiFuture<int32_t> service2SvIf::semifuture_methodC() {
  return apache::thrift::detail::si::semifuture([&] { return methodC(); });
}

folly::Future<int32_t> service2SvIf::future_methodC() {
  return apache::thrift::detail::si::future(semifuture_methodC(), getThreadManager());
}


void service2SvIf::async_tm_methodC(std::unique_ptr<apache::thrift::HandlerCallback<int32_t>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] { return future_methodC(); });
}

int32_t service2SvIf::methodD(int32_t /*i*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*j*/, double /*k*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodD");
}

folly::SemiFuture<int32_t> service2SvIf::semifuture_methodD(int32_t i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> j, double k) {
  return apache::thrift::detail::si::semifuture([&] { return methodD(i, std::move(j), k); });
}

folly::Future<int32_t> service2SvIf::future_methodD(int32_t i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> j, double k) {
  return apache::thrift::detail::si::future(semifuture_methodD(i, std::move(j), k), getThreadManager());
}


void service2SvIf::async_tm_methodD(std::unique_ptr<apache::thrift::HandlerCallback<int32_t>> callback, int32_t i, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> j, double k) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] { return future_methodD(i, std::move(j), k); });
}

void service2SvIf::methodE( ::test_cpp2::cpp_reflection::struct2& /*_return*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodE");
}

folly::SemiFuture<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> service2SvIf::semifuture_methodE() {
  return apache::thrift::detail::si::semifuture_returning_uptr([&]( ::test_cpp2::cpp_reflection::struct2& _return) { methodE(_return); });
}

folly::Future<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> service2SvIf::future_methodE() {
  return apache::thrift::detail::si::future(semifuture_methodE(), getThreadManager());
}


void service2SvIf::async_tm_methodE(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>>> callback) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] { return future_methodE(); });
}


void service2SvIf::methodF( ::test_cpp2::cpp_reflection::struct2& /*_return*/, int32_t /*l*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*m*/, double /*n*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("methodF");
}

folly::SemiFuture<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> service2SvIf::semifuture_methodF(int32_t l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> m, double n) {
  return apache::thrift::detail::si::semifuture_returning_uptr([&]( ::test_cpp2::cpp_reflection::struct2& _return) { methodF(_return, l, std::move(m), n); });
}

folly::Future<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>> service2SvIf::future_methodF(int32_t l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> m, double n) {
  return apache::thrift::detail::si::future(semifuture_methodF(l, std::move(m), n), getThreadManager());
}


void service2SvIf::async_tm_methodF(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::test_cpp2::cpp_reflection::struct2>>> callback, int32_t l, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> m, double n) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] { return future_methodF(l, std::move(m), n); });
}


void service2SvNull::methodA() {
  return;
}

void service2SvNull::methodB(int32_t /*x*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*y*/, double /*z*/) {
  return;
}

int32_t service2SvNull::methodC() {
  return 0;
}

int32_t service2SvNull::methodD(int32_t /*i*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*j*/, double /*k*/) {
  return 0;
}

void service2SvNull::methodE( ::test_cpp2::cpp_reflection::struct2& /*_return*/) {}

void service2SvNull::methodF( ::test_cpp2::cpp_reflection::struct2& /*_return*/, int32_t /*l*/, std::unique_ptr< ::test_cpp2::cpp_reflection::struct1> /*m*/, double /*n*/) {}

const char* service2AsyncProcessor::getServiceName() {
  return "service2";
}

folly::Optional<std::string> service2AsyncProcessor::getCacheKey(folly::IOBuf* buf, apache::thrift::protocol::PROTOCOL_TYPES protType) {
  return apache::thrift::detail::ap::get_cache_key(buf, protType, cacheKeyMap_);
}

void service2AsyncProcessor::process(std::unique_ptr<apache::thrift::ResponseChannelRequest> req, std::unique_ptr<folly::IOBuf> buf, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(buf), protType, context, eb, tm);
}

bool service2AsyncProcessor::isOnewayMethod(const folly::IOBuf* buf, const apache::thrift::transport::THeader* header) {
  return apache::thrift::detail::ap::is_oneway_method(buf, header, onewayMethods_);
}

std::unordered_set<std::string> service2AsyncProcessor::onewayMethods_ {};
std::unordered_map<std::string, int16_t> service2AsyncProcessor::cacheKeyMap_ {};
const service2AsyncProcessor::BinaryProtocolProcessMap& service2AsyncProcessor::getBinaryProtocolProcessMap() {
  return binaryProcessMap_;
}

const service2AsyncProcessor::BinaryProtocolProcessMap service2AsyncProcessor::binaryProcessMap_ {
  {"methodA", &service2AsyncProcessor::_processInThread_methodA<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodB", &service2AsyncProcessor::_processInThread_methodB<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodC", &service2AsyncProcessor::_processInThread_methodC<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodD", &service2AsyncProcessor::_processInThread_methodD<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodE", &service2AsyncProcessor::_processInThread_methodE<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"methodF", &service2AsyncProcessor::_processInThread_methodF<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
};

const service2AsyncProcessor::CompactProtocolProcessMap& service2AsyncProcessor::getCompactProtocolProcessMap() {
  return compactProcessMap_;
}

const service2AsyncProcessor::CompactProtocolProcessMap service2AsyncProcessor::compactProcessMap_ {
  {"methodA", &service2AsyncProcessor::_processInThread_methodA<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodB", &service2AsyncProcessor::_processInThread_methodB<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodC", &service2AsyncProcessor::_processInThread_methodC<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodD", &service2AsyncProcessor::_processInThread_methodD<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodE", &service2AsyncProcessor::_processInThread_methodE<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"methodF", &service2AsyncProcessor::_processInThread_methodF<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
};

}} // test_cpp2::cpp_reflection
namespace apache { namespace thrift {

}} // apache::thrift
