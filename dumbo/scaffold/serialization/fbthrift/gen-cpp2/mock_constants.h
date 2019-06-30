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

#pragma once

#include <thrift/lib/cpp2/gen/module_constants_h.h>

#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/mock_types.h"

namespace idl {
namespace thrift {
namespace cpp2 {

struct mock_constants {
  // consider using folly::StringPiece instead of std::string whenever possible
  // to referencing this statically allocated string constant, in order to
  // prevent unnecessary allocations

  static constexpr char const* const GLOBAL_CONST_VAR_STRING_ = "123";

  static constexpr char const* GLOBAL_CONST_VAR_STRING() { return GLOBAL_CONST_VAR_STRING_; }
};

}  // namespace cpp2
}  // namespace thrift
}  // namespace idl
