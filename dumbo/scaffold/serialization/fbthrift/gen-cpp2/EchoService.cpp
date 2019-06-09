/**
 * Autogenerated by Thrift for /home/curoky/repos/cpp/dumbo/dumbo/scaffold/serialization/fbthrift/mock.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/EchoService.h"
#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/EchoService.tcc"
#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/mock_metadata.h"
#include <thrift/lib/cpp2/gen/service_cpp.h>

namespace idl { namespace thrift { namespace cpp2 {
std::unique_ptr<apache::thrift::AsyncProcessor> EchoServiceSvIf::getProcessor() {
  return std::make_unique<EchoServiceAsyncProcessor>(this);
}


void EchoServiceSvIf::echo( ::idl::thrift::cpp2::MockResponse& /*_return*/, std::unique_ptr< ::idl::thrift::cpp2::MockRequest> /*req*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("echo");
}

folly::SemiFuture<std::unique_ptr< ::idl::thrift::cpp2::MockResponse>> EchoServiceSvIf::semifuture_echo(std::unique_ptr< ::idl::thrift::cpp2::MockRequest> req) {
  return apache::thrift::detail::si::semifuture_returning_uptr([&]( ::idl::thrift::cpp2::MockResponse& _return) { echo(_return, std::move(req)); });
}

folly::Future<std::unique_ptr< ::idl::thrift::cpp2::MockResponse>> EchoServiceSvIf::future_echo(std::unique_ptr< ::idl::thrift::cpp2::MockRequest> req) {
  return apache::thrift::detail::si::future(semifuture_echo(std::move(req)), getThreadManager());
}

void EchoServiceSvIf::async_tm_echo(std::unique_ptr<apache::thrift::HandlerCallback<std::unique_ptr< ::idl::thrift::cpp2::MockResponse>>> callback, std::unique_ptr< ::idl::thrift::cpp2::MockRequest> req) {
  apache::thrift::detail::si::async_tm(this, std::move(callback), [&] {
    return future_echo(std::move(req));
  });
}

void EchoServiceSvIf::oneway_echo(std::unique_ptr< ::idl::thrift::cpp2::MockRequest> /*req*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("oneway_echo");
}

folly::SemiFuture<folly::Unit> EchoServiceSvIf::semifuture_oneway_echo(std::unique_ptr< ::idl::thrift::cpp2::MockRequest> req) {
  return apache::thrift::detail::si::semifuture([&] {
    return oneway_echo(std::move(req));
  });
}

folly::Future<folly::Unit> EchoServiceSvIf::future_oneway_echo(std::unique_ptr< ::idl::thrift::cpp2::MockRequest> req) {
  return apache::thrift::detail::si::future(semifuture_oneway_echo(std::move(req)), getThreadManager());
}

void EchoServiceSvIf::async_tm_oneway_echo(std::unique_ptr<apache::thrift::HandlerCallbackBase> callback, std::unique_ptr< ::idl::thrift::cpp2::MockRequest> req) {
  apache::thrift::detail::si::async_tm_oneway(this, std::move(callback), [&] {
    return future_oneway_echo(std::move(req));
  });
}

void EchoServiceSvNull::echo( ::idl::thrift::cpp2::MockResponse& /*_return*/, std::unique_ptr< ::idl::thrift::cpp2::MockRequest> /*req*/) {}

void EchoServiceSvNull::oneway_echo(std::unique_ptr< ::idl::thrift::cpp2::MockRequest> /*req*/) {
  return;
}



const char* EchoServiceAsyncProcessor::getServiceName() {
  return "EchoService";
}

void EchoServiceAsyncProcessor::getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) {
  ::apache::thrift::detail::md::ServiceMetadata<EchoServiceSvIf>::gen(*response.metadata_ref(), *response.context_ref());
}

void EchoServiceAsyncProcessor::processSerializedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(serializedRequest), protType, context, eb, tm);
}

std::shared_ptr<folly::RequestContext> EchoServiceAsyncProcessor::getBaseContextForRequest() {
  return iface_->getBaseContextForRequest();
}

const EchoServiceAsyncProcessor::ProcessMap& EchoServiceAsyncProcessor::getBinaryProtocolProcessMap() {
  return binaryProcessMap_;
}

const EchoServiceAsyncProcessor::ProcessMap EchoServiceAsyncProcessor::binaryProcessMap_ {
  {"echo", &EchoServiceAsyncProcessor::_processInThread_echo<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
  {"oneway_echo", &EchoServiceAsyncProcessor::_processInThread_oneway_echo<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>},
};

const EchoServiceAsyncProcessor::ProcessMap& EchoServiceAsyncProcessor::getCompactProtocolProcessMap() {
  return compactProcessMap_;
}

const EchoServiceAsyncProcessor::ProcessMap EchoServiceAsyncProcessor::compactProcessMap_ {
  {"echo", &EchoServiceAsyncProcessor::_processInThread_echo<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
  {"oneway_echo", &EchoServiceAsyncProcessor::_processInThread_oneway_echo<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>},
};

}}} // idl::thrift::cpp2
