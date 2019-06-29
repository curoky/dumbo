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

#include <catch2/catch.hpp>

// https://en.cppreference.com/w/cpp/language/dependent_name#The_template_disambiguator_for_dependent_names

namespace {

template <typename T>
struct S {
  template <typename U>
  void foo() {}
};

template <typename T>
void bar() {
  S<T> s;
  // s.foo<T>();           // error: < parsed as less than operator
  s.template foo<T>();  // OK
}
}  // namespace

namespace {
template <int>
struct A {
  int value;
};

template <class T>
void f(T t) {
  (void)t.A<0>::value;  // Ordinary lookup of A finds a class template. A<0>::value names member
                        // of class A<0>
                        // t.A < 0; // Error: '<' is treated as the start of template argument list
}
}  // namespace

TEST_CASE("[TemplateDisambiguator]: unqualified_lookup") {
  A<0> a;
  f(a);
}
