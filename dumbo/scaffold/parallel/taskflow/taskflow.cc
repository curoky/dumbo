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

#include <bits/exception.h>  // for exception
#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <taskflow/taskflow.hpp>  // for Task, Taskflow, Executor, Future

#include <iostream>  // for cout
#include <memory>    // for allocator

TEST_CASE("[Taskflow]: BaseTest") {
  tf::Executor executor;
  tf::Taskflow taskflow;
  int a = 0, b = 0, c = 0, d = 0;
  // clang-format off
  auto [A, B, C, D] = taskflow.emplace(
      [&] { a++; },
      [&] { b = a + 1; },
      [&] { c = a + 1; },
      [&] { d = b + c; }
);
  // clang-format on
  //  task dependency graph
  //
  //          +---+
  //    +---->| B |-----+
  //    |     +---+     |
  //  +---+           +-v-+
  //  | A |           | D |
  //  +---+           +-^-+
  //    |     +---+     |
  //    +---->| C |-----+
  //          +---+

  A.name("A").precede(B).precede(C);
  B.name("B").precede(D);
  C.name("C").precede(D);
  D.name("D");

  executor.run(taskflow).wait();

  REQUIRE(a == 1);
  REQUIRE(b == 2);
  REQUIRE(c == 2);
  REQUIRE(d == 4);
  taskflow.dump(std::cout);
}

TEST_CASE("[Taskflow]: throw exception ") {
  tf::Executor executor;
  tf::Taskflow taskflow;
  int a = 0, b = 0;
  // clang-format off
  auto [A, B] = taskflow.emplace(
      [&] { a++; },
      [&]() {
        b = a + 1;
        throw std::exception();
      }
);
  // clang-format on

  //   bool throwed = false;
  //   try {
  //     A.name("A").precede(B);
  //     executor.run(taskflow).wait();
  //   } catch(...) {
  //     throwed = true;
  //   }
  //   REQUIRE(throwed == true);
}
