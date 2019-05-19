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
 * @file: partial_specialization.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_...

#include <string>  // for operator==, string, basic_string, allocator

namespace {
template <typename A, typename B, typename C>
struct Echo {
  std::string a() { return "unknown"; }
  std::string b() { return "unknown"; }
  std::string c() { return "unknown"; }
};

// error: invalid use of incomplete type ‘class Echo<int, B, C>’
// template <typename B, typename C>
// inline std::string Echo<int, B, C>::a() {
//     return "int";
// }
// template <typename A, typename C>
// inline std::string Echo<A, int, C>::b() {
//     return "int";
// }
// template <typename A, typename B>
// inline std::string Echo<A, B, int>::c() {
//     return "int";
// }

template <typename B, typename C>
struct EchoA : Echo<int, B, C> {
  std::string a() { return "int"; }
};
template <typename A, typename C>
struct EchoB : Echo<A, int, C> {
  std::string b() { return "int"; }
};
template <typename A, typename B>
struct EchoC : Echo<A, B, int> {
  std::string c() { return "int"; }
};

}  // namespace

TEST_CASE("[PartialSpecialization]: members of partial specializations") {
  // https://stackoverflow.com/questions/165101/invalid-use-of-incomplete-type-error-with-partial-template-specialization
  // 按照目前的理解：无法直接偏特化模板类的成员函数，只能继承偏特化类的方法绕过
  {
    Echo<void, void, void> echo;
    REQUIRE(echo.a() == "unknown");
    REQUIRE(echo.b() == "unknown");
    REQUIRE(echo.c() == "unknown");
  }
  // {
  //     Echo<int, int, int> echo;
  //     REQUIRE(echo.a() == "int");
  //     REQUIRE(echo.b() == "int");
  //     REQUIRE(echo.c() == "int");
  // }
  {
    REQUIRE(EchoA<void, void>().a() == "int");
    REQUIRE(EchoB<void, void>().b() == "int");
    REQUIRE(EchoC<void, void>().c() == "int");
  }
}
