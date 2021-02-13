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

// https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html

#if !defined(__clang__)

#include <catch2/catch.hpp>

#include <string>
using namespace std::literals;  // NOLINT

TEST_CASE("[PredefinedMacrosGcc]: __COUNTER__") {
  REQUIRE(__COUNTER__ == 2);
  REQUIRE(__COUNTER__ == 3);
  REQUIRE(__COUNTER__ == 4);
}

TEST_CASE("[PredefinedMacrosGcc]: __GNUC__") {
  REQUIRE(__GNUC__ == 10);
  // REQUIRE(__GNUC_MINOR__ == 1);
  // REQUIRE(__GNUC_PATCHLEVEL__ == 0);
}

TEST_CASE("[PredefinedMacrosGcc]: __GNUG__") { REQUIRE(__GNUG__ == 10); }

TEST_CASE("[PredefinedMacrosGcc]: __BASE_FILE__") {
  REQUIRE_THAT(__BASE_FILE__, Catch::Matchers::EndsWith("predefined_macros_gcc.cc"));
}

TEST_CASE("[PredefinedMacrosGcc]: __INCLUDE_LEVEL__") { REQUIRE(__INCLUDE_LEVEL__ == 0); }

TEST_CASE("[PredefinedMacrosGcc]: __VERSION__") {
  // REQUIRE(__VERSION__ == "9.2.1 20191130"s);
}
#endif
