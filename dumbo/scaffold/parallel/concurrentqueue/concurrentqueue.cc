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
 * ----------------------------------------------------------------------------
 * @file: concurrentqueue.cc
 * ----------------------------------------------------------------------------
 */

#include <blockingconcurrentqueue.h>  // for BlockingConcurrentQueue
#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <concurrentqueue.h>  // for ConcurrentQueue

#include <chrono>  // for milliseconds
#include <thread>  // for thread, sleep_for

TEST_CASE("[Concurrentqueue]: BaseTest") {
  moodycamel::ConcurrentQueue<int> q;
  q.enqueue(25);

  int item;
  bool found = q.try_dequeue(item);
  REQUIRE(found);
  REQUIRE(item == 25);
}

TEST_CASE("[Concurrentqueue]: BlockTest") {
  moodycamel::BlockingConcurrentQueue<int> q;
  std::thread producer([&]() {
    for (int i = 0; i != 100; ++i) {
      std::this_thread::sleep_for(std::chrono::milliseconds(i % 10));
      q.enqueue(i);
    }
  });
  std::thread consumer([&]() {
    for (int i = 0; i != 100; ++i) {
      int item;
      q.wait_dequeue(item);
      REQUIRE(item == i);

      if (q.wait_dequeue_timed(item, std::chrono::milliseconds(5))) {
        ++i;
        REQUIRE(item == i);
      }
    }
  });
  producer.join();
  consumer.join();
  REQUIRE(q.size_approx() == 0);
}
