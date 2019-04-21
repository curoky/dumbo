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
 * @file: number_literal.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, CHECK, TEST_CASE, REQUIRE

#include <cstddef>   // for nullptr_t
#include <typeinfo>  // for type_info

#define REQUIRE_TYPE(var, type) REQUIRE(typeid(var) == typeid(type));

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

TEST_CASE("[NumberLiteral]: integer syntax") {
  int d = 42;
  int o = 052;
  int x = 0x2a;
  int X = 0X2A;
  int b = 0b101010;  // C++14
}
#pragma GCC diagnostic pop

TEST_CASE("[NumberLiteral]: integer type") {
  REQUIRE_TYPE(1, int);
  REQUIRE_TYPE(1u, unsigned int);
  REQUIRE_TYPE(1U, unsigned int);
  REQUIRE_TYPE(1l, long);
  REQUIRE_TYPE(1L, long);
  REQUIRE_TYPE(1ll, long long);
  REQUIRE_TYPE(1LL, long long);
  REQUIRE_TYPE(1lu, unsigned long);
  REQUIRE_TYPE(1LU, unsigned long);
  REQUIRE_TYPE(1llu, unsigned long long int);
  REQUIRE_TYPE(1LLU, unsigned long long int);
}

TEST_CASE("[NumberLiteral]: bool type") {
  REQUIRE_TYPE(false, bool);
  REQUIRE_TYPE(true, bool);
}

TEST_CASE("[NumberLiteral]: nullptr type") { REQUIRE_TYPE(nullptr, std::nullptr_t); }

TEST_CASE("[NumberLiteral]: floating type") {
  REQUIRE_TYPE(1.0, double);
  REQUIRE_TYPE(1.0f, float);
  REQUIRE_TYPE(1.0l, long double);

  REQUIRE_TYPE(1e10, double);
  REQUIRE_TYPE(1.1e10, double);
}

TEST_CASE("[NumberLiteral]: scientific notation") {
  REQUIRE(1e3 == 1000);
  REQUIRE(1.1e3 == 1100);
  REQUIRE(1.11e3 == 1110);
}
