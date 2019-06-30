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

#include <cassert>  // for assert

namespace {
class President {
 public:
  static President& GetInstance() {
    static President instance;
    return instance;
  }

  President(const President&) = delete;
  President& operator=(const President&) = delete;

 private:
  President() {}
};
}  // namespace

TEST_CASE("[Singleton]: ") {
  const President& president1 = President::GetInstance();
  const President& president2 = President::GetInstance();

  (void)president1;
  (void)president2;
  assert(&president1 == &president2);  // same address, point to same object.
}
