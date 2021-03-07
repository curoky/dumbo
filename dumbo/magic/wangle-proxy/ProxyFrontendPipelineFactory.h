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

#include <wangle/bootstrap/ClientBootstrap.h>
#include <wangle/channel/AsyncSocketHandler.h>
#include <wangle/channel/EventBaseHandler.h>

#include <memory>
#include <string>

#include "ProxyBackendPipelineFactory.h"
#include "ShadowsocksDecoder.h"
#include "util.h"

class ProxyFrontendHandler : public wangle::BytesToBytesHandler {
 public:
  explicit ProxyFrontendHandler() {}

  void read(Context* ctx, folly::IOBufQueue& q) override {
    LOG(INFO) << "receive length: " << q.chainLength();

    // folly::io::Cursor c(q.front());
    int header_len = 0;
    if (is_first_recv_ == true) {
      is_first_recv_ = false;
      LOG(INFO) << "is_first_recv_";

      // get remoteaddr;
      std::string message;
      q.appendToString(message);
      folly::SocketAddress remoteAddress;
      // debugchar(message.data(), 10);
      parseHeader(message, remoteAddress, header_len);
      LOG(INFO) << "remote" << remoteAddress.describe();
      q.split(header_len);
      buffer_.append(q);

      // Pause reading from the socket until remote connection succeeds
      auto frontendPipeline = dynamic_cast<wangle::DefaultPipeline*>(ctx->getPipeline());
      frontendPipeline->transportInactive();

      client_.pipelineFactory(std::make_shared<ProxyBackendPipelineFactory>(frontendPipeline));

      client_.connect(remoteAddress)
          .thenValue([this, frontendPipeline](wangle::DefaultPipeline* pipeline) {
            LOG(INFO) << "success connect";
            backendPipeline_ = pipeline;
            // Resume read
            frontendPipeline->transportActive();
            if (buffer_.chainLength()) {
              backendPipeline_->write(buffer_.move());
            }
          })
          .thenError(folly::tag_t<std::exception>{}, [this, ctx](const std::exception& e) {
            LOG(ERROR) << "Connect error: " << folly::exceptionStr(e);
            this->close(ctx);
          });
      return;
    }

    if (!backendPipeline_) {
      LOG(ERROR) << " not have backendPipeline_";
      return;
    }
    LOG(INFO) << "have backendPipeline_";

    buffer_.append(q);
    backendPipeline_->write(buffer_.move());
  }

  void readEOF(Context* ctx) override {
    LOG(INFO) << "Connection closed by local host";
    if (!backendPipeline_) {
      return;
    }
    backendPipeline_->close().thenValue([this, ctx](auto&&) { this->close(ctx); });
  }

  void readException(Context* ctx, folly::exception_wrapper e) override {
    LOG(ERROR) << "Local error: " << folly::exceptionStr(e);
    if (!backendPipeline_) {
      return;
    }
    backendPipeline_->close().thenValue([this, ctx](auto&&) { this->close(ctx); });
  }

 private:
  wangle::ClientBootstrap<wangle::DefaultPipeline> client_;
  wangle::DefaultPipeline* backendPipeline_{nullptr};
  folly::IOBufQueue buffer_{folly::IOBufQueue::cacheChainLength()};
  bool is_first_recv_ = true;
};

class ProxyFrontendPipelineFactory : public wangle::PipelineFactory<wangle::DefaultPipeline> {
 public:
  explicit ProxyFrontendPipelineFactory(const std::string& key) : key_(key) {}

  wangle::DefaultPipeline::Ptr newPipeline(
      std::shared_ptr<folly::AsyncTransportWrapper> sock) override {
    auto pipeline = wangle::DefaultPipeline::create();
    pipeline->addBack(wangle::AsyncSocketHandler(sock));
    // pipeline->addBack(wangle::EventBaseHandler());
    pipeline->addBack(ShadowsocksDecoder(key_));
    pipeline->addBack(std::make_shared<ProxyFrontendHandler>());
    pipeline->finalize();
    return pipeline;
  }

 private:
  std::string key_;
};
