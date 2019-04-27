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
 * @file: forward.cc
 * ----------------------------------------------------------------------------
 */

// reference
// https://stackoverflow.com/questions/24109737/what-are-some-uses-of-decltypeauto
// https://stackoverflow.com/questions/49033889/perfect-forwarding-a-return-value-with-auto

#include <catch2/catch.hpp>

#include <functional>
#include <utility>

namespace {
int add(int a) { return a; }
int add(int a, int b) { return a + b; }
struct Oper {
  virtual int add(int a, int b, int c) { return a + b + c; }
};

template <typename... Args>
decltype(auto) add_proxy(Args&&... args) {
  return add(std::forward<Args>(args)...);
}

template <class Fun, class... Args>
decltype(auto) proxy(Fun fun, Args&&... args) {
  return fun(std::forward<Args>(args)...);
}
}  // namespace

TEST_CASE("[Forward]: base test") {
  REQUIRE(add_proxy(1) == 1);
  REQUIRE(add_proxy(1, 2) == 3);

  using namespace std::placeholders;
  REQUIRE(proxy(std::bind(static_cast<int (*)(int)>(&add), _1), 1) == 1);
  REQUIRE(proxy(std::bind(static_cast<int (*)(int, int)>(&add), _1, _2), 1, 2) == 3);
  REQUIRE(proxy(std::bind(&Oper::add, _1, _2, _3, _4), Oper(), 1, 2, 3) == 6);
}
