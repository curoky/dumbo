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

#include <catch2/catch.hpp>      // for SourceLineInfo, StringRef, TEST_CASE
#include <folly/fibers/Baton.h>  // for Baton
#include <folly/fibers/Fiber.h>
#include <folly/fibers/FiberManager.h>     // for FiberManager
#include <folly/fibers/FiberManagerMap.h>  // for getFiberManager
#include <folly/io/async/EventBase.h>      // for EventBase

#include <iostream>  // for operator<<, endl, basic_ostream, cout, ostream

TEST_CASE("[Fibers]: basic usage") {
  folly::EventBase evb;
  auto& fiberManager = folly::fibers::getFiberManager(evb);
  folly::fibers::Baton baton;
  fiberManager.addTask([&]() {
    std::cout << "Task 1: start" << std::endl;
    baton.wait();
    std::cout << "Task 1: after baton.wait()" << std::endl;
  });

  fiberManager.addTask([&]() {
    std::cout << "Task 2: start" << std::endl;
    baton.post();
    std::cout << "Task 2: after baton.post()" << std::endl;
  });

  evb.loop();
}
