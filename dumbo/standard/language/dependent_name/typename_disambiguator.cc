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

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE
#include <folly/Demangle.h>

#include <vector>  // for vector
// https://en.cppreference.com/w/cpp/language/dependent_name#The_typename_disambiguator_for_dependent_names
// https://www.cnblogs.com/dongzhiquan/p/4051051.html

namespace {
template <typename T>
void foo(std::vector<T>) {
  // without typename follow code can compiles
  // but fails when template instantiation, there is no member variable called 'const_iterator' in
  // the type std::vector<int>
  int error = std::vector<T>::const_iterator * "string";
  (void)error;
  // error: expected ‘(’ before ‘*’ token
  // int error = typename std::vector<T>::const_iterator * "string";
}

template <typename T>
struct S {
  typedef int value_t;  // member of current instantiation
  void f() {
    S<T>::value_t n{};  // S<T> is dependent, but 'typename' not needed
    (void)n;
  }
};

}  // namespace

TEST_CASE("[TypenameDisambiguator]: simple test") {
  // error: dependent-name ‘std::vector<T>::const_iterator’ is parsed as a non-type, but
  // instantiation yields a type
  // foo(std::vector<int>());
}

#if !defined(__clang__)
// FIXME: compile error with clang++-9
namespace {
struct A {  // A has a nested variable X and a nested type struct X
  struct X {};
  int X;
};
struct B {
  struct X {};  // B has a nested type struct X
};
template <class T>
typename T::X f(T) {
  // typename T::X x;
  return typename T::X{};
}
}  // namespace

TEST_CASE("[TypenameDisambiguator]: lookup rules test") {
  REQUIRE(folly::demangle(typeid(f(A())).name()) == "(anonymous namespace)::A::X");
  REQUIRE(folly::demangle(typeid(f(B())).name()) == "(anonymous namespace)::B::X");
}
#endif
