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
 * @file: transformed.cc
 * ----------------------------------------------------------------------------
 */

#include <boost/algorithm/string/join.hpp>       // for join
#include <boost/range/adaptor/argument_fwd.hpp>  // for forwarder
#include <boost/range/adaptor/transformed.hpp>  // for transformed_range, operator|, transform_holder, transformed
#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE

#include <string>  // for basic_string, operator==, string, to_string
#include <vector>  // for vector

TEST_CASE("[Transformed]: ") {
  using boost::adaptors::transformed;
  using boost::algorithm::join;

  std::vector<double> nubs{1.1, 2.2, 3.3, 4.4};
  std::string nubs_str =
      join(nubs | transformed(static_cast<std::string (*)(double)>(std::to_string)), ", ");
  REQUIRE(nubs_str == "1.100000, 2.200000, 3.300000, 4.400000");
}
