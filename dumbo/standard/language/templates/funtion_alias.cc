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

#include <catch2/catch.hpp>

template <typename Source, typename Target>
Target toType(Source s) {
  return static_cast<Target>(s);
}

template <typename S>
const auto toDouble = toType<S, double>;

// is it a bug ?
template <typename S>
using toFloat = decltype(toType<S, float>(0));

TEST_CASE("[FuntionAlias]: base test") {
  REQUIRE(toDouble<int>(1) == 1.0);
  REQUIRE(toFloat<int>(1) == 1.0);
}
