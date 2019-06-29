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
 * @file: parallel-hashmap.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>          // for SourceLineInfo, StringRef, TEST_CASE
#include <parallel_hashmap/phmap.h>  // for flat_hash_map, BitMask, operator!=, raw_hash_set<>::iterator, raw_hash_map
#include <iostream>                  // for operator<<, basic_ostream, cout, ostream
#include <map>                       // for pair
#include <string>                    // for string, operator<<, char_traits, basic_string

TEST_CASE("[Parallel-hashmap]: basic usage") {
  // Create an unordered_map of three strings (that map to strings)
  phmap::flat_hash_map<std::string, std::string> email = {
      {"tom", "tom@gmail.com"}, {"jeff", "jk@gmail.com"}, {"jim", "jimg@microsoft.com"}};

  // Iterate and print keys and values
  for (const auto& n : email) std::cout << n.first << "'s email is: " << n.second << "\n";

  // Add a new entry
  email["bill"] = "bg@whatever.com";

  // and print it
  std::cout << "bill's email is: " << email["bill"] << "\n";
}
