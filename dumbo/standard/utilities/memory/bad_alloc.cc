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

TEST_CASE("[BadAlloc]: VectorParallelPush") {
  // TODO(curoky): implement it
  // using ValueType = std::map<int, int>;
  // std::vector<ValueType> numbers;
  // std::vector<std::thread> threads;
  // for (int i = 0; i < 10000; ++i) {
  //     threads.emplace_back([&] {
  //         ValueType value;
  //         for (int i = 0; i < 10; ++i) { value.emplace(i, i); }
  //         numbers.push_back(value);
  //     });
  // }
  // for (auto& t : threads) t.join();
  // std::cout << numbers.size() << std::endl;
}
