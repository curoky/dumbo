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

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE

#include <iomanip>   // for operator<<, setfill, setiosflags, setprecision, setw
#include <iostream>  // for basic_ostream::operator<<, endl, basic_ostream, basic_ostream<>::__ostream_type, cout, ostream, ios

TEST_CASE("[Cout]: prefix zero") {
  //
  std::cout << std::setfill('0') << std::setw(5) << 25 << std::endl;
  std::cout << 25 << std::endl;

  std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << 1.2344 << std::endl;
  // REQUIRE(false);
}
