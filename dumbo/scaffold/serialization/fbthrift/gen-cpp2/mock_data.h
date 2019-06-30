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

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/mock_types.h"

namespace apache {
namespace thrift {

template <>
struct TEnumDataStorage<::idl::thrift::cpp2::EnumType> {
  using type = ::idl::thrift::cpp2::EnumType;
  static constexpr const std::size_t size = 4;
  static constexpr const std::array<type, size> values = {{
      type::ZERO,
      type::ONE,
      type::TWO,
      type::THREE,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
      "ZERO",
      "ONE",
      "TWO",
      "THREE",
  }};
};

template <>
struct TEnumDataStorage<::idl::thrift::cpp2::UnionType::Type> {
  using type = ::idl::thrift::cpp2::UnionType::Type;
  static constexpr const std::size_t size = 2;
  static constexpr const std::array<type, size> values = {{
      type::var_i16,
      type::var_i32,
  }};
  static constexpr const std::array<folly::StringPiece, size> names = {{
      "var_i16",
      "var_i32",
  }};
};

}  // namespace thrift
}  // namespace apache
