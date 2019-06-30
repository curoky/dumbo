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
 */

#pragma once

#include <thrift/lib/cpp2/gen/client_h.h>

#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/mock_types.h"

namespace apache {
namespace thrift {
class Cpp2RequestContext;
namespace detail {
namespace ac {
struct ClientRequestContext;
}
}  // namespace detail
namespace transport {
class THeader;
}
}  // namespace thrift
}  // namespace apache

namespace idl {
namespace thrift {
namespace cpp2 {

class EchoServiceAsyncClient : public apache::thrift::GeneratedAsyncClient {
 public:
  using apache::thrift::GeneratedAsyncClient::GeneratedAsyncClient;

  char const* getServiceName() const noexcept override { return "EchoService"; }

  virtual void echo(std::unique_ptr<apache::thrift::RequestCallback> callback,
                    const ::idl::thrift::cpp2::MockRequest& req);
  virtual void echo(apache::thrift::RpcOptions& rpcOptions,
                    std::unique_ptr<apache::thrift::RequestCallback> callback,
                    const ::idl::thrift::cpp2::MockRequest& req);

 protected:
  void echoImpl(apache::thrift::RpcOptions& rpcOptions,
                std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx,
                apache::thrift::RequestClientCallback::Ptr callback,
                const ::idl::thrift::cpp2::MockRequest& req);

 public:
  virtual void sync_echo(::idl::thrift::cpp2::MockResponse& _return,
                         const ::idl::thrift::cpp2::MockRequest& req);
  virtual void sync_echo(apache::thrift::RpcOptions& rpcOptions,
                         ::idl::thrift::cpp2::MockResponse& _return,
                         const ::idl::thrift::cpp2::MockRequest& req);

  virtual folly::Future<::idl::thrift::cpp2::MockResponse> future_echo(
      const ::idl::thrift::cpp2::MockRequest& req);
  virtual folly::SemiFuture<::idl::thrift::cpp2::MockResponse> semifuture_echo(
      const ::idl::thrift::cpp2::MockRequest& req);
  virtual folly::Future<::idl::thrift::cpp2::MockResponse> future_echo(
      apache::thrift::RpcOptions& rpcOptions, const ::idl::thrift::cpp2::MockRequest& req);
  virtual folly::SemiFuture<::idl::thrift::cpp2::MockResponse> semifuture_echo(
      apache::thrift::RpcOptions& rpcOptions, const ::idl::thrift::cpp2::MockRequest& req);
  virtual folly::Future<std::pair<::idl::thrift::cpp2::MockResponse,
                                  std::unique_ptr<apache::thrift::transport::THeader>>>
  header_future_echo(apache::thrift::RpcOptions& rpcOptions,
                     const ::idl::thrift::cpp2::MockRequest& req);
  virtual folly::SemiFuture<std::pair<::idl::thrift::cpp2::MockResponse,
                                      std::unique_ptr<apache::thrift::transport::THeader>>>
  header_semifuture_echo(apache::thrift::RpcOptions& rpcOptions,
                         const ::idl::thrift::cpp2::MockRequest& req);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<::idl::thrift::cpp2::MockResponse> co_echo(
      const ::idl::thrift::cpp2::MockRequest& req) {
    auto _task = semifuture_echo(req);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(
          co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
  template <int = 0>
  folly::coro::Task<::idl::thrift::cpp2::MockResponse> co_echo(
      apache::thrift::RpcOptions& rpcOptions, const ::idl::thrift::cpp2::MockRequest& req) {
    auto _task = semifuture_echo(rpcOptions, req);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(
          co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
  template <int = 0>
  folly::coro::Task<std::pair<::idl::thrift::cpp2::MockResponse,
                              std::unique_ptr<apache::thrift::transport::THeader>>>
  header_co_echo(apache::thrift::RpcOptions& rpcOptions,
                 const ::idl::thrift::cpp2::MockRequest& req) {
    auto _task = header_semifuture_echo(rpcOptions, req);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(
          co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
#endif  // FOLLY_HAS_COROUTINES

  virtual void echo(folly::Function<void(::apache::thrift::ClientReceiveState&&)> callback,
                    const ::idl::thrift::cpp2::MockRequest& req);

  static folly::exception_wrapper recv_wrapped_echo(::idl::thrift::cpp2::MockResponse& _return,
                                                    ::apache::thrift::ClientReceiveState& state);
  static void recv_echo(::idl::thrift::cpp2::MockResponse& _return,
                        ::apache::thrift::ClientReceiveState& state);
  // Mock friendly virtual instance method
  virtual void recv_instance_echo(::idl::thrift::cpp2::MockResponse& _return,
                                  ::apache::thrift::ClientReceiveState& state);
  virtual folly::exception_wrapper recv_instance_wrapped_echo(
      ::idl::thrift::cpp2::MockResponse& _return, ::apache::thrift::ClientReceiveState& state);

 private:
  template <typename Protocol_>
  void echoT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions,
             std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx,
             apache::thrift::RequestClientCallback::Ptr callback,
             const ::idl::thrift::cpp2::MockRequest& req);

 public:
  virtual void oneway_echo(std::unique_ptr<apache::thrift::RequestCallback> callback,
                           const ::idl::thrift::cpp2::MockRequest& req);
  virtual void oneway_echo(apache::thrift::RpcOptions& rpcOptions,
                           std::unique_ptr<apache::thrift::RequestCallback> callback,
                           const ::idl::thrift::cpp2::MockRequest& req);

 protected:
  void oneway_echoImpl(apache::thrift::RpcOptions& rpcOptions,
                       std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx,
                       apache::thrift::RequestClientCallback::Ptr callback,
                       const ::idl::thrift::cpp2::MockRequest& req);

 public:
  virtual void sync_oneway_echo(const ::idl::thrift::cpp2::MockRequest& req);
  virtual void sync_oneway_echo(apache::thrift::RpcOptions& rpcOptions,
                                const ::idl::thrift::cpp2::MockRequest& req);

  virtual folly::Future<folly::Unit> future_oneway_echo(
      const ::idl::thrift::cpp2::MockRequest& req);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_echo(
      const ::idl::thrift::cpp2::MockRequest& req);
  virtual folly::Future<folly::Unit> future_oneway_echo(
      apache::thrift::RpcOptions& rpcOptions, const ::idl::thrift::cpp2::MockRequest& req);
  virtual folly::SemiFuture<folly::Unit> semifuture_oneway_echo(
      apache::thrift::RpcOptions& rpcOptions, const ::idl::thrift::cpp2::MockRequest& req);

#if FOLLY_HAS_COROUTINES
  template <int = 0>
  folly::coro::Task<void> co_oneway_echo(const ::idl::thrift::cpp2::MockRequest& req) {
    auto _task = semifuture_oneway_echo(req);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(
          co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
  template <int = 0>
  folly::coro::Task<void> co_oneway_echo(apache::thrift::RpcOptions& rpcOptions,
                                         const ::idl::thrift::cpp2::MockRequest& req) {
    auto _task = semifuture_oneway_echo(rpcOptions, req);
    const folly::CancellationToken& cancelToken =
        co_await folly::coro::co_current_cancellation_token;
    if (cancelToken.canBeCancelled()) {
      co_yield folly::coro::co_result(
          co_await folly::coro::co_awaitTry(folly::coro::detachOnCancel(std::move(_task))));
    } else {
      co_yield folly::coro::co_result(co_await folly::coro::co_awaitTry(std::move(_task)));
    }
  }
#endif  // FOLLY_HAS_COROUTINES

  virtual void oneway_echo(folly::Function<void(::apache::thrift::ClientReceiveState&&)> callback,
                           const ::idl::thrift::cpp2::MockRequest& req);

 private:
  template <typename Protocol_>
  void oneway_echoT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions,
                    std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx,
                    apache::thrift::RequestClientCallback::Ptr callback,
                    const ::idl::thrift::cpp2::MockRequest& req);

 public:
};

}  // namespace cpp2
}  // namespace thrift
}  // namespace idl
