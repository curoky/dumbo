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

#include <catch2/catch.hpp>  // for operator""_catch_sr, SourceLineInfo, MessageBuilder, AssertionHandler, StringRef, INFO, REQUIRE
#include <folly/io/async/DelayedDestruction.h>  // for DelayedDestruction, DelayedDestruction::Destructor
#include <folly/io/async/DelayedDestructionBase.h>  // for DelayedDestructionBase::DestructorGuard

#include <chrono>  // for milliseconds
#include <memory>  // for unique_ptr, make_unique
#include <thread>  // for thread, sleep_for

namespace {
static int destruct_counter = 0;

class DeleteGuarder : public folly::DelayedDestruction {
 public:
  void doFoo() {
    DestructorGuard dg(this);
    INFO("in doFoo: start sleep");
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    INFO("in doFoo: finish sleep");
  }

 private:
  ~DeleteGuarder() override { destruct_counter++; }
};
}  // namespace

TEST_CASE("[DelayedDestruction]: basic usage") {
  //
}

TEST_CASE("[DelayedDestruction]: async destruct protect") {
  std::unique_ptr<std::thread> th;
  destruct_counter = 0;
  {
    auto dg_ptr =
        std::unique_ptr<DeleteGuarder, folly::DelayedDestruction::Destructor>(new DeleteGuarder());
    // dg_ptr->doFoo();
    th = std::make_unique<std::thread>(&DeleteGuarder::doFoo, dg_ptr.get());
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  REQUIRE(destruct_counter == 0);
  INFO("wait for thread join");
  th->join();
  REQUIRE(destruct_counter == 1);
}
