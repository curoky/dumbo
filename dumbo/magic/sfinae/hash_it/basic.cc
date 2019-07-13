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

// https://github.com/xu-cheng/sfinae-utility/blob/master/include/sfinae-utility.hpp
#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <type_traits>  // for conditional, false_type, true_type
#include <utility>      // for declval

#include "foo.h"
namespace detail {
template <typename... Ts>
struct helper {};
}  // namespace detail

template <class Container, class = void>
struct has_method : std::false_type {};

template <class Container>
struct has_method<
    Container,
    typename std::conditional<
        false, detail::helper<decltype(std::declval<Container>().var_func_void_int())>, void>::type>
    : std::true_type {};

template <class Container>
constexpr bool has_method_v = has_method<Container>::value;

TEST_CASE("[SFINAE]: has method") {
  REQUIRE(has_method_v<Foo1> == true);
  REQUIRE(has_method_v<Foo2> == false);
}
