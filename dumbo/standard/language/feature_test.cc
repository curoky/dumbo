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
 * @file: feature_test.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <concepts>  // for __cpp_lib_concepts

TEST_CASE("[Feature]: Attributes") {
  // REQUIRE(__has_cpp_attribute(carries_dependency)==200809);
  REQUIRE(__has_cpp_attribute(noreturn) == 200809);
  REQUIRE(__has_cpp_attribute(deprecated) == 201309);
  REQUIRE(__has_cpp_attribute(fallthrough) == 201603);
  REQUIRE(__has_cpp_attribute(maybe_unused) == 201603);
  REQUIRE(__has_cpp_attribute(likely) == 201803);
  REQUIRE(__has_cpp_attribute(no_unique_address) == 201803);
  REQUIRE(__has_cpp_attribute(unlikely) == 201803);
  REQUIRE(__has_cpp_attribute(nodiscard) == 201907);
}
TEST_CASE("[Feature]: Language features") {
  REQUIRE(__cpp_concepts == 201907);
  REQUIRE(__cpp_constexpr == 201907);
}
TEST_CASE("[Feature]: Library features") {
  REQUIRE(__cpp_lib_concepts == 202002);
  //   REQUIRE(__cpp_lib_erase_if == 202002);
}
