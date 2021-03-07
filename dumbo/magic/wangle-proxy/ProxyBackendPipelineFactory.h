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
#include <wangle/channel/AsyncSocketHandler.h>
#include <memory>

class ProxyBackendHandler : public wangle::InboundBytesToBytesHandler {
 public:
  explicit ProxyBackendHandler(wangle::DefaultPipeline* frontendPipeline)
      : frontendPipeline_(frontendPipeline) {}

  void read(Context*, folly::IOBufQueue& q) override { frontendPipeline_->write(q.move()); }

  void readEOF(Context*) override { LOG(INFO) << "Connection closed by remote host"; }

  void readException(Context*, folly::exception_wrapper e) override {
    LOG(ERROR) << "Remote error: " << exceptionStr(e);
    frontendPipeline_->close();
  }

 private:
  wangle::DefaultPipeline* frontendPipeline_;
};

class ProxyBackendPipelineFactory : public wangle::PipelineFactory<wangle::DefaultPipeline> {
 public:
  explicit ProxyBackendPipelineFactory(wangle::DefaultPipeline* frontendPipeline)
      : frontendPipeline_(frontendPipeline) {}

  wangle::DefaultPipeline::Ptr newPipeline(
      std::shared_ptr<folly::AsyncTransportWrapper> sock) override {
    auto pipeline = wangle::DefaultPipeline::create();
    pipeline->addBack(wangle::AsyncSocketHandler(sock));
    // pipeline->addBack(wangle::EventBaseHandler());
    pipeline->addBack(ProxyBackendHandler(frontendPipeline_));
    pipeline->finalize();
    return pipeline;
  }

 private:
  wangle::DefaultPipeline* frontendPipeline_;
};
