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

#include <type_traits>

namespace {
template <typename T, typename U>
struct decay_equiv : std::is_same<typename std::decay<T>::type, U>::type {};
}  // namespace

TEST_CASE("[Miscellaneous-transformations]: decay") {
  REQUIRE((decay_equiv<int, int>::value) == true);
  REQUIRE((decay_equiv<int&, int>::value) == true);
  REQUIRE((decay_equiv<int&&, int>::value) == true);
  REQUIRE((decay_equiv<const int&, int>::value) == true);
  REQUIRE((decay_equiv<int[2], int*>::value) == true);
  REQUIRE((decay_equiv<int(int), int (*)(int)>::value) == true);
}
