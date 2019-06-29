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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_...

#include <string>  // for operator==, basic_string, string, operator+, allocator

namespace {
class Parent {
 public:
  virtual ~Parent() {}
  std::string info() { return "Parent"; }
  virtual std::string info_v() { return "Parent"; }

  std::string info_base() { return "Parent"; }
  virtual std::string info_v_base() { return "Parent"; }
};

class Child : public Parent {
 public:
  ~Child() = default;
  std::string info() { return "Child"; }
  std::string info_v() override { return "Child"; }
  std::string info_base() { return Parent::info_base() + "-Child"; }
  std::string info_v_base() override { return Parent::info_v_base() + "-Child"; }
};

class Grandson : public Child {
 public:
  std::string info() { return "Grandson"; }
  std::string info_v() override { return "Grandson"; }

  std::string info_base() { return Child::info_base() + "-Grandson"; }
  std::string info_v_base() override { return Child::info_v_base() + "-Grandson"; }
};
}  // namespace

TEST_CASE("[Inherit]: base test") {
  // shared_ptr need dynamic_pointer_cast
  Child* c = new Child();
  REQUIRE(c->info() == "Child");
  REQUIRE(c->info_v() == "Child");

  REQUIRE(dynamic_cast<Parent*>(c)->info() == "Parent");
  REQUIRE(dynamic_cast<Parent*>(c)->info_v() == "Child");

  REQUIRE(dynamic_cast<Parent*>(c)->info_base() == "Parent");
  REQUIRE(dynamic_cast<Parent*>(c)->info_v_base() == "Parent-Child");

  Grandson* g = new Grandson();
  REQUIRE(g->info() == "Grandson");
  REQUIRE(g->info_v() == "Grandson");

  REQUIRE(dynamic_cast<Parent*>(g)->info() == "Parent");
  REQUIRE(dynamic_cast<Parent*>(g)->info_v() == "Grandson");
  REQUIRE(dynamic_cast<Child*>(g)->info() == "Child");
  REQUIRE(dynamic_cast<Child*>(g)->info_v() == "Grandson");

  REQUIRE(dynamic_cast<Parent*>(g)->info_base() == "Parent");
  REQUIRE(dynamic_cast<Parent*>(g)->info_v_base() == "Parent-Child-Grandson");
  REQUIRE(dynamic_cast<Child*>(g)->info_base() == "Parent-Child");
  REQUIRE(dynamic_cast<Child*>(g)->info_v_base() == "Parent-Child-Grandson");

  delete c;
  delete g;
}
