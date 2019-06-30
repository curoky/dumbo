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

// std::function 对象可以用 Callable type 对象构造
// - std::function
// - std::bind
// - std::result_of
// - std::thread::thread
// - std::call_once
// - std::async
// - std::packaged_task
// - std::reference_wrapper

#include <catch2/catch.hpp>

#include <functional>

int add(int a, int b) { return a + b; }

struct Oper {
  int add(int a, int b) const { return a + b; }  // 该方法需要传入this
  static int add2(int a, int b) { return a + b; }
};

struct Add {
  int operator()(int a, int b) { return a + b; }
};

TEST_CASE("[Functional]: base test") {
  using namespace std::placeholders;  // NOLINT
  std::function<int(int, int)> f1 = [](int a, int b) { return a + b; };
  std::function<int(int, int)> f2 = std::bind(add, _1, _2);
  std::function<int(int, int)> f3 = Add();
  std::function<int(int, int)> f4 = &Oper::add2;
  std::function<int(const Oper&, int, int)> f5 = &Oper::add;

  REQUIRE(f1(1, 2) == 3);
  REQUIRE(f2(1, 2) == 3);
  REQUIRE(f3(1, 2) == 3);
  REQUIRE(f4(1, 2) == 3);
  REQUIRE(f5(Oper(), 1, 2) == 3);
}
