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
 * @file: factorial.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>

namespace {
// Recursive template for general case
template <int N>
struct factorial {
  enum { value = N * factorial<N - 1>::value };
};

// Template specialization for base case
template <>
struct factorial<0> {
  enum { value = 1 };
};

enum { result = factorial<5>::value };  // 5 * 4 * 3 * 2 * 1 == 120
}  // namespace

TEST_CASE("[Factorial]: basic test") { REQUIRE(factorial<5>::value == 1 * 2 * 3 * 4 * 5); }
