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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_...

#include <memory>       // for shared_ptr, make_shared, allocator
#include <string>       // for string, basic_string
#include <type_traits>  // for integral_constant<>::value, is_const
#include <utility>      // for as_const

TEST_CASE("[Lambda]: MutableTest") {
  {
    auto str = std::make_shared<std::string>("123");
    // 捕获的拷贝对象，默认加了const，需要加mutable
    auto change = [str]() mutable { str.reset(); };
    change();
    REQUIRE(str.use_count() == 1);
  }
  {
    auto str = std::make_shared<std::string>("123");
    auto change = [&str]() { str.reset(); };
    change();
    REQUIRE(str.use_count() == 0);
  }
}
TEST_CASE("[Lambda]: ConstRefTest") {
  // https://stackoverflow.com/questions/3772867/lambda-capture-as-const-reference/32440415#32440415

  std::string str = "123";
  auto get_const_ref = [&str = static_cast<const std::string&>(str)] {
    // FIXME: why is not const
    (void)str;
    REQUIRE(std::is_const<decltype(str)>::value == false);
  };
  get_const_ref();
  auto get_const_ref2 = [&str = std::as_const(str)] {
    REQUIRE(std::is_const<decltype(str)>::value == false);
  };
  get_const_ref2();
}
