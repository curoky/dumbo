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

#include <gen-cpp2/mock_types.h>   // for MockRequest (ptr only), MockResponse
#include <glog/logging.h>          // for COMPACT_GOOGLE_LOG_INFO, LOG, LogMessage
#include <thrift/lib/cpp2/server/ThriftServer.h>
#include <thrift/lib/cpp2/transport/core/ThriftProcessor.h>
#include <atomic>                  // for atomic, __atomic_base
#include <memory>                  // for unique_ptr
#include <ostream>                 // for basic_ostream::operator<<, operator<<, basic_ostream
#include <utility>                 // for forward

#include "gen-cpp2/EchoService.h"  // for EchoServiceSvIf

class EchoServiceHandler : public idl::thrift::cpp2::EchoServiceSvIf {
 public:
  void echo(::idl::thrift::cpp2::MockResponse& _return,
            std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) override {
    _return.set_req(*req);
    LOG(INFO) << "[echo]: counter->" << echo_counter++;
  }
  void oneway_echo(std::unique_ptr<::idl::thrift::cpp2::MockRequest> req) override {
    // oneway_echo
    LOG(INFO) << "[oneway_echo]: oneway_echo_counter->" << oneway_echo_counter++;
  }

 private:
  std::atomic<int> echo_counter{0};
  std::atomic<int> oneway_echo_counter{0};
};
