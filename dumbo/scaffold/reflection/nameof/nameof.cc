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

#include <bits/exception.h>  // for exception
#include <catch2/catch.hpp>
#include <nameof.hpp>  // for cstring, operator<<, NAMEOF, nameof_type, nameof_enum, NAMEOF_TYPE, NAMEOF_TYPE_EXPR, nameof_enum_flag, nameof_full_type

#include <iostream>  // for endl, cout, basic_ostream, ostream, basic_ostream::put, operator<<, basic_ostream::operator<<, basic_ostream<>::__ostrea...
#include <stdexcept>  // for invalid_argument
#include <string>     // for operator<<, char_traits, operator+, string
#include <string_view>  // for operator<<, operator""sv, basic_string_view, string_view, string_view_literals
#include <utility>  // for declval

TEST_CASE("[Nameof]: check compiler support") {
  // check is nameof_type supported compiler
  REQUIRE(NAMEOF_TYPE_SUPPORTED);
  REQUIRE(nameof::is_nameof_type_supported);
  // check is nameof_enum supported compiler
  REQUIRE(NAMEOF_ENUM_SUPPORTED);
  REQUIRE(nameof::is_nameof_enum_supported);
}

TEST_CASE("[Nameof]: NAMEOF usage") {
  bool bool_var;
  // Name of variable.
  REQUIRE(NAMEOF(bool_var) == "bool_var");

  // Name of member variable.
  std::pair<int, int> pii_var;
  REQUIRE(NAMEOF(pii_var.first) == "first");

  // Name of member function.
  std::string str_var;
  REQUIRE(NAMEOF(str_var.c_str()) == "c_str");

  // Name of macro.
  REQUIRE(NAMEOF(__LINE__) == "__LINE__");
  REQUIRE(NAMEOF(NAMEOF(str_var)) == "NAMEOF");
}

TEST_CASE("[Nameof]: nameof_enum") {
  //
}
TEST_CASE("[Nameof]: nameof_type") {
  using T = const int&;
  REQUIRE(NAMEOF_TYPE(T) == "int");
}
