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

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE, AssertionHandler, operator""_catch_sr, REQUIRE
#include <cxxabi.h>  // for __forced_unwind

#include <chrono>  // for system_clock, duration, minutes, operator-, seconds, system_clock::time_point, time_point, duration_cast, time_point_cast
#include <ctime>   // for localtime, time_t
#include <iomanip>   // for operator<<, put_time
#include <iostream>  // for char_traits, stringstream, basic_ostream
#include <ratio>     // for ratio
#include <string>    // for string_literals

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

typedef std::chrono::duration<int, std::ratio<60 * 60 * 24>> days_type;
using namespace std::string_literals;  // NOLINT

TEST_CASE("[Chrono]: calculate") {
  std::chrono::minutes t1(10);
  std::chrono::seconds t2(60);
  std::chrono::seconds t3 = t1 - t2;
  REQUIRE(t3.count() == 540);
  std::chrono::minutes t4 = std::chrono::duration_cast<std::chrono::minutes>(t3);
  REQUIRE(t4.count() == 9);
}

TEST_CASE("[Chrono]: time_point") {
  using std::chrono::system_clock;
  using std::chrono::time_point;
  using std::chrono::time_point_cast;

  time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());

  // count days since epoch
  // REQUIRE(today.time_since_epoch().count() == 18290);
}

TEST_CASE("[Chrono]: time_point calculate") {
  using std::chrono::system_clock;
  system_clock::time_point now = system_clock::now();
  std::time_t last = system_clock::to_time_t(now - std::chrono::hours(24));
  std::time_t next = system_clock::to_time_t(now - std::chrono::hours(24));

  std::stringstream ss1, ss2;
  // One day ago, the time was
  ss1 << std::put_time(std::localtime(&last), "%F %T");
  // REQUIRE(ss1.str() == "2020-01-28 20:49:31"s);
  ss2 << std::put_time(std::localtime(&next), "%F %T");
  // Next day, the time was
  // REQUIRE(ss2.str() == "2020-01-28 20:52:29"s);
}

TEST_CASE("[Chrono]: format") {
  // 1607422087564370033
  // CHECK(std::chrono::system_clock::now().time_since_epoch().count() == 111);
  // 1607422087
  // CHECK(time(nullptr) == 111);
}

TEST_CASE("[Chrono]: clock") {
  using std::chrono::steady_clock;
  using std::chrono::system_clock;
  system_clock::time_point t1 = system_clock::now();
  system_clock::time_point t2 = system_clock::now();

  // tick count
  // REQUIRE((t2 - t1).count() == 51);
  // REQUIRE(std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() == 1);
}

TEST_CASE("[Chrono]: clock to ctime") {
  using std::chrono::steady_clock;
  using std::chrono::system_clock;
  system_clock::time_point t1 = system_clock::now();
  std::time_t now_c = system_clock::to_time_t(t1);
  // REQUIRE(now_c == 1580301724);

  auto t = system_clock::to_time_t(system_clock::now());
  std::stringstream ss1, ss2;
  ss1 << std::put_time(std::localtime(&t), "%Y-%m-%d %X");
  ss2 << std::put_time(std::localtime(&t), "%Y-%m-%d %H.%M.%S");
  // REQUIRE(ss1.str() == "2020-01-29 20:49:31"s);
  // REQUIRE(ss2.str() == "2020-01-29 20.53.04"s);
}

#pragma GCC diagnostic pop
