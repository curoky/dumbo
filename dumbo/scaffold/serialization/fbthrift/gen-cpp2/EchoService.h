/**
 * Copyright 2020 curoky(cccuroky@gmail.com).
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
 *
 */

#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/EchoServiceAsyncClient.h"
#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/mock_types.h"

namespace folly {
class IOBuf;
class IOBufQueue;
}  // namespace folly
namespace apache {
namespace thrift {
class Cpp2RequestContext;
class BinaryProtocolReader;
class CompactProtocolReader;
namespace transport {
class THeader;
}
}  // namespace thrift
}  // namespace apache

namespace idl {
namespace thrift {
namespace cpp2 {

class EchoServiceSvAsyncIf {
 public:
  virtual ~EchoServiceSvAsyncIf() {}
  virtual void async_tm_echo(
      std::unique_ptr<
          apache::thrift::HandlerCallback<std::unique_ptr<::idl::thrift::cpp2::MockResponse>>>
          callback,
      std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) = 0;
  virtual folly::Future<std::unique_ptr<::idl::thrift::cpp2::MockResponse>> future_echo(
      std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) = 0;
  virtual folly::SemiFuture<std::unique_ptr<::idl::thrift::cpp2::MockResponse>> semifuture_echo(
      std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) = 0;
  virtual void async_tm_oneway_echo(std::unique_ptr<apache::thrift::HandlerCallbackBase> callback,
                                    std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) = 0;
  virtual folly::Future<folly::Unit> future_oneway_echo(
      std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) = 0;
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_echo(
      std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) = 0;
};

class EchoServiceAsyncProcessor;

class EchoServiceSvIf : public EchoServiceSvAsyncIf, public apache::thrift::ServerInterface {
 public:
  typedef EchoServiceAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;

  virtual void echo(::idl::thrift::cpp2::MockResponse& /*_return*/,
                    std::unique_ptr<::idl::thrift::cpp2::MockRequest> /*req*/);
  folly::Future<std::unique_ptr<::idl::thrift::cpp2::MockResponse>> future_echo(
      std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) override;
  folly::SemiFuture<std::unique_ptr<::idl::thrift::cpp2::MockResponse>> semifuture_echo(
      std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) override;
  void async_tm_echo(
      std::unique_ptr<
          apache::thrift::HandlerCallback<std::unique_ptr<::idl::thrift::cpp2::MockResponse>>>
          callback,
      std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) override;
  virtual void oneway_echo(std::unique_ptr<::idl::thrift::cpp2::MockRequest> /*req*/);
  folly::Future<folly::Unit> future_oneway_echo(
      std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) override;
  folly::SemiFuture<folly::Unit> semifuture_oneway_echo(
      std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) override;
  void async_tm_oneway_echo(std::unique_ptr<apache::thrift::HandlerCallbackBase> callback,
                            std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) override;
};

class EchoServiceSvNull : public EchoServiceSvIf {
 public:
  void echo(::idl::thrift::cpp2::MockResponse& /*_return*/,
            std::unique_ptr<::idl::thrift::cpp2::MockRequest> /*req*/) override;
  void oneway_echo(std::unique_ptr<::idl::thrift::cpp2::MockRequest> /*req*/) override;
};

class EchoServiceAsyncProcessor : public ::apache::thrift::GeneratedAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(
      apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = void;

 protected:
  EchoServiceSvIf* iface_;

 public:
  void processSerializedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req,
                                apache::thrift::SerializedRequest&& serializedRequest,
                                apache::thrift::protocol::PROTOCOL_TYPES protType,
                                apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb,
                                apache::thrift::concurrency::ThreadManager* tm) override;

 protected:
  std::shared_ptr<folly::RequestContext> getBaseContextForRequest() override;

 public:
  using ProcessFunc = GeneratedAsyncProcessor::ProcessFunc<EchoServiceAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessor::ProcessMap<ProcessFunc>;
  static const EchoServiceAsyncProcessor::ProcessMap& getBinaryProtocolProcessMap();
  static const EchoServiceAsyncProcessor::ProcessMap& getCompactProtocolProcessMap();

 private:
  static const EchoServiceAsyncProcessor::ProcessMap binaryProcessMap_;
  static const EchoServiceAsyncProcessor::ProcessMap compactProcessMap_;

 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_echo(apache::thrift::ResponseChannelRequest::UniquePtr req,
                             apache::thrift::SerializedRequest&& serializedRequest,
                             apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb,
                             apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_echo(apache::thrift::ResponseChannelRequest::UniquePtr req,
                    apache::thrift::SerializedRequest&& serializedRequest,
                    apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb,
                    apache::thrift::concurrency::ThreadManager* tm);
  template <class ProtocolIn_, class ProtocolOut_>
  static folly::IOBufQueue return_echo(int32_t protoSeqId, apache::thrift::ContextStack* ctx,
                                       ::idl::thrift::cpp2::MockResponse const& _return);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_echo(apache::thrift::ResponseChannelRequest::UniquePtr req,
                                 int32_t protoSeqId, apache::thrift::ContextStack* ctx,
                                 folly::exception_wrapper ew,
                                 apache::thrift::Cpp2RequestContext* reqCtx);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void _processInThread_oneway_echo(apache::thrift::ResponseChannelRequest::UniquePtr req,
                                    apache::thrift::SerializedRequest&& serializedRequest,
                                    apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb,
                                    apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void process_oneway_echo(apache::thrift::ResponseChannelRequest::UniquePtr req,
                           apache::thrift::SerializedRequest&& serializedRequest,
                           apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb,
                           apache::thrift::concurrency::ThreadManager* tm);

 public:
  EchoServiceAsyncProcessor(EchoServiceSvIf* iface) : iface_(iface) {}

  virtual ~EchoServiceAsyncProcessor() {}
};

}  // namespace cpp2
}  // namespace thrift
}  // namespace idl