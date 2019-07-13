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

template <typename T>
struct isSharedPtr : std::false_type {};

template <typename T>
struct isSharedPtr<std::shared_ptr<T>> : std::true_type {};

template <typename T>
typename std::enable_if<isSharedPtr<T>::value, bool>::type is_ptr(T t) {
  return true;
}
template <typename T>
typename std::enable_if<!isSharedPtr<T>::value, bool>::type is_ptr(T t) {
  return false;
}

TEST_CASE("[]: example") {
  REQUIRE(isSharedPtr<int>::value == false);
  REQUIRE(isSharedPtr<std::shared_ptr<int>>::value == true);

  REQUIRE(is_ptr(int(1)) == false);
  REQUIRE(is_ptr(std::make_shared<int>(1)) == true);
}
