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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <fatal/type/has_type.h>  // for FATAL_HAS_TYPE

#include <type_traits>  // for integral_constant<>::value

class Foo1;
class Foo2;

FATAL_HAS_TYPE(has_type_int, type_int);

TEST_CASE("[Fatal]: has tyep") {
  REQUIRE(has_type_int::apply<Foo1>::value == true);
  REQUIRE(has_type_int::apply<Foo2>::value == false);
}
