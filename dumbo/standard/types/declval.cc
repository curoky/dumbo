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
 * @file: declval.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <utility>  // for declval

namespace {
struct Default {
  int foo() const { return 1; }
};

struct NonDefault {
  NonDefault(const NonDefault&) {}
  int foo() const { return 1; }
};
}  // namespace

TEST_CASE("[Declval]: simple test") {
  decltype(Default().foo()) n1 = 1;  // type of n1 is int
  //  decltype(NonDefault().foo()) n2 = n1;               // error: no default constructor
  decltype(std::declval<NonDefault>().foo()) n2 = n1;  // type of n2 is int
  REQUIRE(n1 == 1);
  REQUIRE(n2 == 1);
}
