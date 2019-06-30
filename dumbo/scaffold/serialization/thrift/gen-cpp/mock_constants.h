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

#ifndef mock_CONSTANTS_H
#define mock_CONSTANTS_H

#include <string>  // for string

#include "mock_types.h"

namespace idl {
namespace thrift {

class mockConstants {
 public:
  mockConstants();

  std::string GLOBAL_CONST_VAR_STRING;
};

extern const mockConstants g_mock_constants;

}  // namespace thrift
}  // namespace idl

#endif
