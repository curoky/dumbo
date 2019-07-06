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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <folly/Traits.h>             // for index_constant
#include <folly/functional/Invoke.h>  // for invoke_result_t

#include <string>       // for string
#include <type_traits>  // for integral_constant<>::value, is_same

template <typename...>
struct ArgType;

template <typename Arg, typename... Args>
struct ArgType<Arg, Args...> {
  typedef Arg FirstArg;
  typedef ArgType<Args...> Tail;
};

template <>
struct ArgType<> {
  typedef void FirstArg;
};

// 当知道函数跟函数参数的情况下
template <typename F, typename... Args>
struct argResult {
  using Function = F;
  using ArgList = ArgType<Args...>;
  using Result = folly::invoke_result_t<F, Args...>;
  using ArgsSize = folly::index_constant<sizeof...(Args)>;
};

// 仅知道函数本身时
template <typename L>
struct Extract : Extract<decltype(&L::operator())> {};

template <typename Class, typename R, typename... Args>
struct Extract<R (Class::*)(Args...) const> {
  using ArgList = ArgType<Args...>;
  using Result = R;
  using ArgsSize = folly::index_constant<sizeof...(Args)>;
};

template <typename Class, typename R, typename... Args>
struct Extract<R (Class::*)(Args...)> {
  using ArgList = ArgType<Args...>;
  using Result = R;
  using ArgsSize = folly::index_constant<sizeof...(Args)>;
};

template <typename R, typename... Args>
struct Extract<R (*)(Args...)> {
  using ArgList = ArgType<Args...>;
  using Result = R;
  using ArgsSize = folly::index_constant<sizeof...(Args)>;
};

template <typename R, typename... Args>
struct Extract<R (&)(Args...)> {
  using ArgList = ArgType<Args...>;
  using Result = R;
  using ArgsSize = folly::index_constant<sizeof...(Args)>;
};

TEST_CASE("[ArgsUnpack] example from folly") {
  auto func = [](int a, std::string b, double c) { return true; };
  REQUIRE(Extract<decltype(func)>::ArgsSize::value == 3);
  REQUIRE(std::is_same<Extract<decltype(func)>::Result, bool>::value);
  REQUIRE(std::is_same<Extract<decltype(func)>::ArgList::FirstArg, int>::value);
  REQUIRE(std::is_same<Extract<decltype(func)>::ArgList::Tail::FirstArg, std::string>::value);
}
