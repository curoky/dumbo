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

#include <boost/range/adaptor/copied.hpp>  // for operator|, copied
#include <boost/range/algorithm/copy.hpp>  // for copy
#include <boost/range/begin.hpp>           // for begin
#include <boost/range/end.hpp>             // for end
#include <catch2/catch.hpp>                // for SourceLineInfo, StringRef, TEST_CASE

#include <iterator>  // for back_insert_iterator, back_inserter
#include <vector>    // for vector

TEST_CASE("[Adaptor]: copied") {
  std::vector<int> input = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> result;

  boost::copy(input | boost::adaptors::copied(1, 5), std::back_inserter(result));
  // REQUIRE(result == {1, 2, 3, 4, 5});
}
