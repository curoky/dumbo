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
 * @file: type_index.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_...

#include <memory>         // for unique_ptr
#include <string>         // for string, basic_string, operator==
#include <typeindex>      // for type_index, hash
#include <unordered_map>  // for unordered_map, unordered_map<>::mapped_type

namespace {
struct A {
  virtual ~A() {}
};
struct B : A {};
struct C : A {};
}  // namespace

TEST_CASE("type_index") {
  std::unordered_map<std::type_index, std::string> type_names;

  type_names[std::type_index(typeid(int))] = "int";
  type_names[std::type_index(typeid(double))] = "double";
  type_names[std::type_index(typeid(A))] = "A";
  type_names[std::type_index(typeid(B))] = "B";
  type_names[std::type_index(typeid(C))] = "C";

  int i;
  double d;
  A a;

  // note that we're storing pointer to type A
  std::unique_ptr<A> b(new B);
  std::unique_ptr<A> c(new C);
  REQUIRE(type_names[std::type_index(typeid(i))] == "int");
  REQUIRE(type_names[std::type_index(typeid(d))] == "double");
  REQUIRE(type_names[std::type_index(typeid(a))] == "A");
  REQUIRE(type_names[std::type_index(typeid(*b))] == "B");
  REQUIRE(type_names[std::type_index(typeid(*c))] == "C");
}
