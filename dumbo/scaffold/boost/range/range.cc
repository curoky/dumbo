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

#include <boost/algorithm/string/join.hpp>       // for join
#include <boost/range/adaptor/argument_fwd.hpp>  // for forwarder
#include <boost/range/adaptor/map.hpp>  // for select_first_range, select_second_mutable_range, operator|, map_keys, map_keys_forwarder, map_values
#include <boost/range/adaptor/transformed.hpp>  // for transformed_range, operator|, transform_holder, transformed
#include <boost/range/algorithm/copy.hpp>  // for copy
#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <algorithm>  // for copy, equal
#include <iterator>   // for back_insert_iterator, back_inserter
#include <list>       // for list, operator==, operator!=
#include <map>        // for map, operator==
#include <string>     // for basic_string, allocator, operator==, string, to_string
#include <vector>     // for vector, operator==

TEST_CASE("[Range]: copy") {
  std::map<int, int> foo = {{1, 2}, {2, 3}};
  std::vector<int> keys;
  std::list<int> valus;
  boost::copy(foo | boost::adaptors::map_keys, std::back_inserter(keys));
  boost::copy(foo | boost::adaptors::map_values, std::back_inserter(valus));
  REQUIRE(keys == std::vector<int>({1, 2}));
  REQUIRE(valus == std::list<int>({2, 3}));
}

TEST_CASE("[Range]: transformed") {
  std::vector<double> nubs{1.1, 2.2, 3.3, 4.4};
  std::string nubs_str = boost::algorithm::join(
      nubs | boost::adaptors::transformed(static_cast<std::string (*)(double)>(std::to_string)),
      ", ");
  REQUIRE(nubs_str == "1.100000, 2.200000, 3.300000, 4.400000");
}
