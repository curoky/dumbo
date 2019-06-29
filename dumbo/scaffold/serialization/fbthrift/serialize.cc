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

#include <catch2/catch.hpp>    // for SourceLineInfo, StringRef, TEST_CASE
#include <folly/File.h>        // for File
#include <folly/ScopeGuard.h>  // for SCOPE_EXIT

#include <utility>  // for forward

#include "gen-cpp2/mock_types.h"  // for MockRequest

TEST_CASE("[Serialize]: zero copy") {
  {
    idl::thrift::cpp2::MockRequest req;
    req.set_var_string("hhh");

    auto file = folly::File::temporary();
    SCOPE_EXIT { file.close(); };
  }
}
