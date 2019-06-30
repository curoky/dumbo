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

#include <catch2/catch.hpp>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wempty-body"

struct A {
  A(int) {}       // 转换构造函数     // NOLINT
  A(int, int) {}  // 转换构造函数 (C++11)
  operator bool() const { return true; }
};

struct B {
  explicit B(int) {}
  explicit B(int, int) {}
  explicit operator bool() const { return true; }
};

// clang-format off
TEST_CASE("[Explicit]: base test") {
    A a1 = 1;       // OK：复制初始化选择 A::A(int)
    A a2(2);        // OK：直接初始化选择 A::A(int)
    A a3{4, 5};     // OK：直接列表初始化选择 A::A(int, int)
    A a4 = {4, 5};  // OK：复制列表初始化选择 A::A(int, int)
    A a5 = (A)1;    // OK：显式转型进行 static_cast

    if (a1) {}                          // OK：A::operator bool()
    bool na1 = a1;                      // OK：复制初始化选择 A::operator bool()
    bool na2 = static_cast<bool>(a1);   // OK：static_cast 进行直接初始化

    // B b1 = 1;        // 错误：复制初始化不考虑 B::B(int)
    B b2(2);            // OK：直接初始化选择 B::B(int)
    B b3{4, 5};         // OK：直接列表初始化选择 B::B(int, int)
    // B b4 = {4, 5};   // 错误：复制列表初始化不考虑 B::B(int,int)
    B b5 = (B)1;        // OK：显式转型进行 static_cast

    if (b2) {}                          // OK：B::operator bool()
    // bool nb1 = b2;                   // 错误：复制初始化不考虑 B::operator bool()
    bool nb2 = static_cast<bool>(b2);  // OK：static_cast 进行直接初始化
}
// clang-format on
#pragma GCC diagnostic pop
