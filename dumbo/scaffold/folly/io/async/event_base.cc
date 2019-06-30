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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <folly/Optional.h>                   // for Optional
#include <folly/Range.h>                      // for StringPiece
#include <folly/io/async/EventBase.h>         // for EventBase
#include <folly/io/async/EventBaseManager.h>  // for EventBaseManager
#include <folly/io/async/EventBaseThread.h>   // for EventBaseThread
#include <folly/synchronization/Baton.h>      // for Baton
#include <folly/system/ThreadName.h>          // for getCurrentThreadName
#include <stdint.h>                           // for uintptr_t, uint32_t
#include <stdio.h>                            // for printf

#include <chrono>  // for seconds
#include <string>  // for operator==, basic_string, string
#include <thread>  // for thread

TEST_CASE("[EventBase]: simple test") {
  folly::EventBase base;
  auto thread1 = std::thread([&] { base.loopForever(); });
  base.runInEventBaseThread([&] { printf(" this will be printed in thread1!"); });
  base.terminateLoopSoon();
  thread1.join();
}

// EventBaseThread 将 EventBase 与 Thread 封装在一起

TEST_CASE("[EventBase]: EventBaseThread") {
  folly::EventBaseThread ebt(/*autostart =*/true, /*ebm =*/nullptr, /*threadName =*/"monkey");

  folly::Baton<> done;
  ebt.getEventBase()->runInEventBaseThread([&] {
    REQUIRE(folly::getCurrentThreadName().value() == "monkey");
    done.post();
  });
  REQUIRE(done.try_wait_for(std::chrono::seconds(1)));
}

TEST_CASE("[EventBase]: EventBaseThread start stop") {
  folly::EventBaseThread ebt(false);

  REQUIRE(ebt.getEventBase() == nullptr);
  ebt.start();
  REQUIRE(ebt.getEventBase() != nullptr);
  folly::Baton<> done;
  ebt.getEventBase()->runInEventBaseThread([&] { done.post(); });
  REQUIRE(done.try_wait_for(std::chrono::seconds(1)));
  ebt.stop();
  REQUIRE(ebt.getEventBase() == nullptr);
}

// EventBaseManager 管理线程级别的 EventBase 对象。
// 该类将为当前线程找到或创建一个 EventBase 对象，并与当前线程绑定。
// 通常情况下 EventBaseManager 作为单例存在，但并不限制多实例。
// 不同 EventBaseManager 实例持有的 EventBase 是隔离的。
TEST_CASE("[EventBase]: global evb manager") {
  auto ebm = folly::EventBaseManager::get();
  auto ebm_eb = static_cast<folly::EventBase*>(nullptr);

  folly::EventBaseThread ebt;
  auto ebt_eb = ebt.getEventBase();

  ebt_eb->runInEventBaseThreadAndWait([&] { ebm_eb = ebm->getEventBase(); });
  REQUIRE(uintptr_t(ebt_eb) == uintptr_t(ebm_eb));
}

TEST_CASE("[EventBase]: custom evb manager") {
  folly::EventBaseManager ebm;
  auto ebm_eb = static_cast<folly::EventBase*>(nullptr);

  folly::EventBaseThread ebt(&ebm);
  auto ebt_eb = ebt.getEventBase();

  ebt_eb->runInEventBaseThreadAndWait([&] { ebm_eb = ebm.getEventBase(); });
  REQUIRE(uintptr_t(ebt_eb) == uintptr_t(ebm_eb));
}
