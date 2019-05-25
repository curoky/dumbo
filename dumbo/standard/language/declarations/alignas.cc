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
 * @file: alignas.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE
#include <stdint.h>          // for int32_t

TEST_CASE("[Alignas]: basic usage") {
  struct alignas(16) Foo {
    int32_t foo_data[4];
  };
}
