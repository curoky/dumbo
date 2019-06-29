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

#include <catch2/catch.hpp>  // for Approx, operator""_catch_sr, AssertionHandler, operator==, SourceLineInfo, StringRef, operator!=, MatchAllOf, REQUIRE

TEST_CASE("[Catch2]: floating point comparisons") {
  REQUIRE(2 == Approx(2.000000000001));

  using namespace Catch::literals;
  REQUIRE(2 == 2.000000000001_a);

  SECTION("epsilon") {
    // 允许相差 1%
    Approx target = Approx(100).epsilon(0.01);
    REQUIRE(89.9 != target);
    REQUIRE(99.0 == target);
    REQUIRE(101.0 == target);
    REQUIRE(101.1 != target);
  }

  SECTION("margin") {
    // 允许相差大小 5
    Approx target = Approx(100).margin(5);
    REQUIRE(94.0 != target);
    REQUIRE(95.0 == target);
    REQUIRE(105.0 == target);
    REQUIRE(106.0 != target);
  }

  SECTION("scale") {}
}

// https://github.com/catchorg/Catch2/blob/master/docs/matchers.md#top

TEST_CASE("[Catch2]: string matcher") {
  // using Catch::Matchers::EndsWith;
  // or using Catch::EndsWith
  REQUIRE_THAT("hello world", Catch::StartsWith("hello"));
  REQUIRE_THAT("hello world", Catch::EndsWith("world"));
  REQUIRE_THAT("hello world", Catch::Contains("hello"));
  REQUIRE_THAT("hello world", Catch::Equals("hello world"));
  REQUIRE_THAT("hello world", Catch::Matches(R"~(hello \w*)~"));

  REQUIRE_THAT("hello world", Catch::EndsWith("WORLD", Catch::CaseSensitive::No));

  REQUIRE_THAT("hello world", Catch::StartsWith("hello") && Catch::EndsWith("world"));
  REQUIRE_THAT("hello world", Catch::StartsWith("hello") && !Catch::Contains("dog"));
  // Bugs, &&等运算符不会持有matcher对象的所有权，所以下面的代码会crash
  // auto match_expression = Catch::StartsWith("hello") && Catch::EndsWith("world");
  // REQUIRE_THAT("hello world", match_expression);
}

TEST_CASE("[Catch2]: vector matchers") {}
TEST_CASE("[Catch2]: deneric matchers") {}
TEST_CASE("[Catch2]: Exception matchers") {}
TEST_CASE("[Catch2]: custom matchers") {}
