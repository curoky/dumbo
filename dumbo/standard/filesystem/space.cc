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
 * ----------------------------------------------------------------------------
 * @file: space.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE

#include <chrono>      // for filesystem
#include <filesystem>  // for space_info, space
#include <iostream>  // for operator<<, basic_ostream, basic_ostream<>::__ostream_type, char_traits, cout, ostream

namespace fs = std::filesystem;

TEST_CASE("[Space]: base test") {
  fs::space_info devi = fs::space("/dev/null");
  fs::space_info tmpi = fs::space("/tmp");

  std::cout << ".        Capacity       Free      Available\n"
            << "/dev:   " << devi.capacity << "   " << devi.free << "   " << devi.available << '\n'
            << "/tmp: " << tmpi.capacity << " " << tmpi.free << " " << tmpi.available << '\n';
}