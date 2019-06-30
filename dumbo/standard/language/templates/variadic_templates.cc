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

// reference:
// https://en.cppreference.com/w/cpp/language/parameter_pack
// https://www.cnblogs.com/qicosmos/p/4325949.html

#include <catch2/catch.hpp>

#include <iostream>
#include <vector>

template <typename T, typename... Ts>
std::vector<T> to_vector(T t, Ts... args) {
  // 因为初始化器列表保证顺序，所以这可用于按顺序对包的每个元素调用函数：
  // std::vector<T> ret{t, args...};
  std::vector<T> ret{(std::cout << t, t), (std::cout << args, args)...};
  REQUIRE(ret.size() == sizeof...(Ts) + 1);
  REQUIRE(ret.size() == sizeof...(args) + 1);
  return ret;
}

TEST_CASE("[VariadicTemplates]: base test") {
  REQUIRE(to_vector(1, 2, 3, 4) == std::vector<int>({1, 2, 3, 4}));
}
