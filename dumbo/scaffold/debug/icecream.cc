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
#include <icecream.hpp>

TEST_CASE("[Icecream]: basic usage") {
  auto a = int{7};
  auto b = std::string{"bla"};
  auto c = float{3.14};

  IC();
  int& d = IC(a);
  std::tuple<std::string&, float&> e = IC(b, c);
}
