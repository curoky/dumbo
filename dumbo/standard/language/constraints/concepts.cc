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
 * @file: concepts.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE

#include <random>  // for random_device

namespace {
template <typename T>
requires std::invocable<T> bool is_invocable(T) {
  return true;
}
}  // namespace

TEST_CASE("[Concepts]: basic usage") {
  REQUIRE(is_invocable(std::random_device{}));
  // note: the expression 'is_invocable_v<_Fn, _Args ...> [with _Fn = int; _Args = {}]' evaluated
  // to 'false'
  // concept invocable = is_invocable_v<_Fn, _Args...>;
  // REQUIRE(is_invocable(int{}));
}
