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
 * @file: condition_variable.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <chrono>              // for milliseconds
#include <condition_variable>  // for cv_status, condition_variable, cv_status::no_timeout, cv_status::timeout
#include <mutex>               // for mutex

TEST_CASE("[ConditionVariable]: wait after notify") {
  std::mutex cv_m;
  std::condition_variable cv;
  // cv.notify_one();
  cv.notify_all();

  std::unique_lock lock(cv_m);
  std::cv_status status = cv.wait_for(lock, std::chrono::milliseconds(10));
  REQUIRE(status == std::cv_status::timeout);
  REQUIRE(status != std::cv_status::no_timeout);
}
