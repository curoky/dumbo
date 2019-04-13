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
 * @file: comma_in_macro.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>

#include <map>

template <typename T>
struct argument_type;
template <typename T, typename U>
struct argument_type<T(U)> {
  typedef U type;
};
#define FOO(t, name) argument_type<void(t)>::type name

TEST_CASE("[CommaInMacro]: comma in macro") {
  // https://stackoverflow.com/questions/13842468/comma-in-c-c-macro
  FOO((std::map<int, int>), map_var);
  REQUIRE(map_var.size() == 0);
}
