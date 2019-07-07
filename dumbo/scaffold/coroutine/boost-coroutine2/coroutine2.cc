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

#include <boost/coroutine2/coroutine.hpp>  // for coroutine<>::push_type, coroutine<>::pull_type, coroutine
#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE
#include <cxxabi.h>  // for __forced_unwind

#include <functional>  // for bind, ref, _1
#include <vector>      // for vector, allocator, operator==

namespace {
void foo(boost::coroutines2::coroutine<void>::pull_type& pull, std::vector<int>& vec) {
  vec.push_back(2);
  pull();
  vec.push_back(4);
  pull();
  vec.push_back(6);
}
}  // namespace

TEST_CASE("[Coroutine2]: basic usage") {
  std::vector<int> vec;
  auto foo2 = std::bind(foo, std::placeholders::_1, std::ref(vec));
  boost::coroutines2::coroutine<void>::push_type push(foo2);
  vec.push_back(1);
  push();
  vec.push_back(3);
  push();
  vec.push_back(5);
  push();
  REQUIRE(vec == std::vector<int>{1, 2, 3, 4, 5, 6});
}
