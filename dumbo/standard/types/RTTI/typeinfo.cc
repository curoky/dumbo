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

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, AssertionHandler, operator""_catch_sr, TEST_CASE, REQUIRE
#include <folly/Demangle.h>  // for demangle
#include <folly/FBString.h>  // for basic_fbstring, operator==, operator<<, fbstring_core::category_type, fbstring
#include <stdlib.h>  // for free

#include <string>       // for string
#include <string_view>  // for literals
#include <typeinfo>     // for type_info

// FIXME(@curoky): why not < ?
#include "absl/debugging/internal/demangle.h"

/*
 * 不保证同一类型上的 typeid 表达式的所有求值都指代同一个 std::type_info 实例，
 * 不过这些 type_info 对象的 std::type_info::hash_code 相同，其 std::type_index 也相同。
 *
 * typeid展现的是实现时输出，如果完整输出除了demangle外，也可以使用c++filt -t
 * echo 11Transmitter | c++filt -t
 */
namespace {
// clang-format off
struct A {};    // 非多态
struct B : A {};
struct C : B {};
struct VA { virtual void foo() {} };    // 多态
struct VB : VA {};
struct VC : VB {};
struct AA { struct A {}; };
// clang-format on
}  // namespace

TEST_CASE("[Typeinfo]: ExtendTest") {
  using namespace std::literals;  // NOLINT
  // 应用于多态类型的表达式时，typeid 表达式的求值可能涉及运行时开销（虚表查找），
  // 其他情况下 typeid 表达式都在编译时解决。

  // REQUIRE(typeid(A).name() == "1A"s);
  // REQUIRE(typeid(B).name() == "1B"s);

  // REQUIRE(typeid(VA).name() == "2VA"s);
  // REQUIRE(typeid(VB).name() == "2VB"s);
  // REQUIRE(typeid(VC).name() == "2VC"s);

  // REQUIRE(typeid(AA::A).name() == "N2AA1AE"s);

  // REQUIRE(folly::demangle(typeid(B).name()) == "B");
  // REQUIRE(folly::demangle(typeid(VC).name()) == "VC");
  // REQUIRE(folly::demangle(typeid(AA::A).name()) == "AA::A");
}

namespace a {
struct AA {
  struct A {};
};
}  // namespace a

TEST_CASE("[Typeinfo]: NamespaceTest") {
  //
  REQUIRE(folly::demangle(typeid(a::AA::A).name()) == "a::AA::A");
}

TEST_CASE("[Typeinfo]: container text") {
  // REQUIRE(typeid(std::string).name() == "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE");
  // string
  REQUIRE(folly::demangle(typeid(std::string).name()) ==
          "std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >");
  // char out[100];
  // REQUIRE(absl::debugging_internal::Demangle("NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE",
  //                                            out, 100));
  // REQUIRE(out == "123");
}
