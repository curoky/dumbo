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

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE
#include <refl.hpp>  // for is_readable, map_to_tuple, reflect, REFL_DETAIL_EX_1_field, REFL_AUTO, REFL_DETAIL_EX_1_type, REFL_DETAIL_FOR_EACH_3

#include <tuple>  // for tuple, operator==

struct Point {
  float x;
  float y;
};

/* Metadata */
REFL_AUTO(type(Point), field(x, /* attributes */), field(y));

TEST_CASE("[Refl]: basic usage") {
  constexpr Point pt{};

  // Converting to an std::tuple: (Note the constexpr!)
  constexpr auto values = refl::util::map_to_tuple(refl::reflect(pt).members, [&](auto member) {
    // refl::descriptor::is_readable (found by Koenig lookup)
    if constexpr (is_readable(member)) {
      return member(pt);  // invoke the member
    }
  });

  std::tuple<int, int> expect{0, 0};
  REQUIRE(values == expect);
  // Result: values == std::tuple<int, int>{ 0, 0 };
}
