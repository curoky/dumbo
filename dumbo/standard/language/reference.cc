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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, Section, TEST_CASE, SECTION, SectionInfo, CAP...

#include <functional>   // for function
#include <string>       // for operator==, string, move, basic_string, allocator, forward
#include <type_traits>  // for remove_reference<>::type, integral_constant<>::value, is_lvalue_reference, is_rvalue_reference

TEST_CASE("[Reference]: lvalue and rvalue reference") {
  std::string msg = "12345";
  typedef std::string& LvRef;
  typedef std::string&& RvRef;

  LvRef& l1 = msg;
  LvRef&& l2 = msg;
  RvRef& r1 = msg;
  RvRef&& r2 = std::move(msg);
  REQUIRE(std::is_lvalue_reference<decltype(l1)>::value == true);
  REQUIRE(std::is_lvalue_reference<decltype(l2)>::value == true);
  REQUIRE(std::is_rvalue_reference<decltype(r1)>::value == false);
  REQUIRE(std::is_rvalue_reference<decltype(r2)>::value == true);
}

// 此处必须是模板才能触发引用折叠
template <typename T>
std::string echo(T&& msg) {
  return std::forward<T>(msg);
}
TEST_CASE("[Reference]: Reference collapsing") {
  std::string msg = "12345";
  std::string& lmsg = msg;
  const std::string& clmsg = msg;

  REQUIRE(echo(lmsg) == "12345");
  REQUIRE(echo(clmsg) == "12345");

  REQUIRE(msg == "12345");
  REQUIRE(echo(std::move(lmsg)) == "12345");
  REQUIRE(msg == "");
}

std::string echo_lref(std::string& msg) { return msg; }
std::string echo_clref(const std::string& msg) { return msg; }
std::string echo_rref(std::string&& msg) { return std::move(msg); }

TEST_CASE("[Reference]: interface test") {
  std::string str = "12345";
  SECTION("rvalue to lref interface") {
    // reason: rvalue can't be changed
    // error: cannot bind non-const lvalue reference of type ... to an rvalue of type ...
    // echo_lref(std::move(str));
  }
  SECTION("rvalue to clref interface") {
    // rvalue can to const ref
    echo_clref(std::move(str));
    REQUIRE(str == "12345");
  }
  SECTION("lvalue to rref interface") {
    // error: cannot bind rvalue reference of type ... to lvalue of type ...
    // echo_rref(str);
  }
}

TEST_CASE("[Reference]: reference destruct") {
  int* number = new int(100);

  std::function<int()> func1, func2;
  {
    int& number_ref = *number;
    int* number_addr = &(*number);

    CAPTURE(&number_ref);
    CAPTURE(number_addr);
    REQUIRE(number_addr == &number_ref);
    func1 = [&]() { return number_ref; };
    func2 = [&]() { return *number_addr; };
  }
  *number = 1;
  REQUIRE(func1() == 1);
  // FIXME: this is a memory leak
  // REQUIRE(func2() == 1);

  delete number;
}
