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

#include <numbers>

TEST_CASE("[Constants]: basic usage") {
  REQUIRE(std::numbers::e == Approx(2.7182818285).epsilon(0.00001));
  REQUIRE(std::numbers::log2e == Approx(1.4426950409).epsilon(0.00001));
  REQUIRE(std::numbers::log10e == Approx(0.4342944819).epsilon(0.00001));
  REQUIRE(std::numbers::pi == Approx(3.1415926536).epsilon(0.00001));
  REQUIRE(std::numbers::inv_pi == Approx(0.3183098862).epsilon(0.00001));
  REQUIRE(std::numbers::inv_sqrtpi == Approx(0.5641895835).epsilon(0.00001));
  REQUIRE(std::numbers::ln2 == Approx(0.6931471806).epsilon(0.00001));
  REQUIRE(std::numbers::ln10 == Approx(2.302585093).epsilon(0.00001));
  REQUIRE(std::numbers::sqrt2 == Approx(1.4142135624).epsilon(0.00001));
  REQUIRE(std::numbers::sqrt3 == Approx(1.7320508076).epsilon(0.00001));
  REQUIRE(std::numbers::inv_sqrt3 == Approx(0.5773502692).epsilon(0.00001));
  REQUIRE(std::numbers::egamma == Approx(0.5772156649).epsilon(0.00001));
  REQUIRE(std::numbers::phi == Approx(1.6180339887).epsilon(0.00001));
}
