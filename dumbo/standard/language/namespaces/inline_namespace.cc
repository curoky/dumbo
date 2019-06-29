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

namespace std {

namespace c03 {
int f() { return 0; }
}  // namespace c03
namespace c11 {
int f() { return 1; }
}  // namespace c11
inline namespace c14 {
int f() { return 2; }
}  // namespace c14

}  // namespace std

TEST_CASE("[InlineNamespace]: ") {
  REQUIRE(std::c03::f() == 0);
  REQUIRE(std::c11::f() == 1);
  REQUIRE(std::c14::f() == 2);
  REQUIRE(std::f() == 2);
}
