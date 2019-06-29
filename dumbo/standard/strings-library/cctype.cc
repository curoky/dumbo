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

#include <cctype>

// isalnum 检查字符是否为字母或数字
// isalpha 检查字符是否为字母
// islower 检查字符是否为小写
// isupper 检查字符是否为大写字符
// isdigit 检查字符是否为数字
// isxdigit 检查字符是为十六进制字符
// iscntrl 检查字符是否为控制字符
// isgraph 检查字符是否为图形字符
// isspace 检查字符是否为空白间隔字符
// isblank(C++11)检查字符是否为空白字符
// isprint 检查字符是否为打印字符
// ispunct 检查字符是否为标点符
// tolower 转换字符为小写
// toupper 转换字符为大写
TEST_CASE("[Cctype]: base test") {
  REQUIRE(std::isalnum('1'));
  REQUIRE(std::isalpha('A'));
  REQUIRE(std::islower('a'));
  REQUIRE(std::isdigit('1'));
  REQUIRE(std::ispunct(','));
  REQUIRE(std::isspace(' '));
  REQUIRE(std::isspace('\n'));
  REQUIRE(std::tolower('A') == 'a');
  REQUIRE(std::toupper('a') == 'A');
}
