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

/** Refference
 * https://codereview.stackexchange.com/questions/30846/zip-like-functionality-with-c11s-range-based-for-loop
 * https://stackoverflow.com/questions/12552277/whats-the-best-way-to-iterate-over-two-or-more-containers-simultaneously
 * https://stackoverflow.com/questions/8511035/sequence-zip-function-for-c11
 */

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE

#include <list>    // for list
#include <vector>  // for vector

TEST_CASE("[Combine]: basic usage") {
  std::vector<int> v;
  std::list<int> l;
  for (int i = 0; i < 5; ++i) {
    v.push_back(i);
    l.push_back(i);
  }

  // TODO(@curoky): fix this test
  // int index;
  // int vi;
  // int li;
  // BOOST_FOREACH (boost::tie(vi, li), boost::combine(v, l)) {
  //   REQUIRE(index == vi);
  //   REQUIRE(index == li);
  //   index++;
  // }
}
