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
 * @file: shared_ptr.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <memory>  // for shared_ptr, __shared_ptr_access, operator==, make_shared, allocator
#include <string>  // for string, operator==, basic_string, move

#include "dumbo/utilities/class_utils.h"

TEST_CASE("[SharedPtr]: make_shared with move constructor") {
  std::string msg = "123";
  auto new_msg = std::make_shared<std::string>(std::move(msg));

  REQUIRE(msg.size() == 0);
  REQUIRE(*new_msg == "123");
}

namespace {
struct A;

struct B {
  ~B() { *destroy = true; }
  std::shared_ptr<A> a;
  bool* destroy;
};
struct A {
  ~A() { *destroy = true; }
  std::shared_ptr<B> b;
  bool* destroy;
};
}  // namespace

TEST_CASE("[SharedPtr]: circular references/dependency") {
  // make circular references
  auto a = std::make_shared<A>();
  a->b = std::make_shared<B>();
  a->b->a = a;

  // add observer when destory
  bool a_destroy = false;
  bool b_destroy = false;
  a->destroy = &a_destroy;
  a->b->destroy = &b_destroy;

  // check refference count
  REQUIRE(a.use_count() == 2);
  REQUIRE(a->b.use_count() == 1);

  // force destory b
  a->b.reset();
  REQUIRE(a->b == nullptr);
  REQUIRE(a.use_count() == 1);
  REQUIRE(b_destroy);

  // force destory b
  a.reset();
  REQUIRE(a == nullptr);
  REQUIRE(a_destroy);
}

TEST_CASE("[SharedPtr]: no initialization") {
  std::shared_ptr<int> ptr;
  REQUIRE(ptr == nullptr);
}

TEST_CASE("[SharedPtr]: return") {
  auto make_shared_ptr = [] {
    auto ptr = std::make_shared<int>(1);
    return ptr;
  };
  REQUIRE(*make_shared_ptr() == 1);
}

TEST_CASE("[SharedPtr]: noop deleter") {
  using taro::util::ClassMetrics;

  taro::util::ClassMetrics::Counter counter;
  // int count = 0;
  // taro::util::ClassMetrics cm;

  // Nofree* nf = new Nofree(count);
  // REQUIRE(count == 1);

  SECTION("with default deleter") {
    std::shared_ptr<ClassMetrics> p1(new ClassMetrics(counter));
    p1.reset();
    REQUIRE(counter.destruct == 1);
  }

  SECTION("with noop deleter") {
    std::shared_ptr<ClassMetrics> p2(new ClassMetrics(counter), [](ClassMetrics*) {});

    auto raw_ptr = p2.get();
    p2.reset();
    REQUIRE(counter.destruct == 0);
    delete raw_ptr;
  }
}
