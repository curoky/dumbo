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

#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>  // for Session
#include <folly/Singleton.h>
// #include <folly/init/Init.h>                              // for SingletonVault
#include <folly/init/Phase.h>  // for set_process_phases
// #include <folly/logging/Init.h>
#include <folly/synchronization/HazptrThreadPoolExecutor.h>  // for enable_hazptr_thread_pool_executor
#include <gflags/gflags.h>                                   // for DEFINE_string
#include <glog/logging.h>                                    // for InitGoogleLogging

// Just for vscode test plugin
DEFINE_string(catch2, "Catch v2.12.2", "Catch v2.12.2");

int main(int argc, char* argv[]) {
  // google::AllowCommandLineReparsing();

  // folly::init(&argc, &argv, false);
  // copy from folly init
  // google::InstallFailureSignalHandler();
  folly::set_process_phases();
  // folly::initLoggingOrDie(true);

  folly::SingletonVault::singleton()->registrationComplete();
  folly::enable_hazptr_thread_pool_executor();

  // google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);
  int result = Catch::Session().run(argc, argv);
  return result;
}
