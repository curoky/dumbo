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

#include <folly/executors/IOThreadPoolExecutor.h>  // for IOThreadPoolExecutor
#include <gflags/gflags.h>                         // for ParseCommandLineFlags, DEFINE_int32
#include <openssl/ssl.h>                           // for EVP_BytesToKey, EVP_md5, EVP_rc4
#include <stddef.h>                                // for NULL
#include <wangle/bootstrap/ServerBootstrap.h>      // for ServerBootstrap
#include <wangle/channel/Pipeline.h>               // for Pipeline, DefaultPipeline

#include <memory>  // for make_shared, allocator, __shared_ptr_access<>::element_type
#include <string>  // for string
#include <vector>  // for vector

#include "ProxyFrontendPipelineFactory.h"  // for ProxyFrontendPipelineFactory

DEFINE_int32(port, 2323, "proxy server port");
DEFINE_int32(io, 1, "io thread num");

int main(int argc, char** argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  // folly::Init init(&argc, &argv);

  unsigned char key[100];
  std::string password = "123";
  EVP_BytesToKey(EVP_rc4(), EVP_md5(), NULL, (const unsigned char*)password.data(), password.size(),
                 1, key, NULL);

  wangle::ServerBootstrap<wangle::DefaultPipeline> server;
  server.childPipeline(std::make_shared<ProxyFrontendPipelineFactory>(std::string((char*)key, 16)));
  server.group(std::make_shared<folly::IOThreadPoolExecutor>(FLAGS_io));
  server.bind(FLAGS_port);
  server.waitForStop();
  return 0;
}
