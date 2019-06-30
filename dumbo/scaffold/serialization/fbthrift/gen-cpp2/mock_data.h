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

template <>
struct TStructDataStorage<::idl::thrift::cpp2::UnionType> {
 private:
  using TType = apache::thrift::protocol::TType;

 public:
  static constexpr const std::size_t fields_size = 2;
  static constexpr std::array<folly::StringPiece, fields_size> fields_names = {{
      "var_i16",
      "var_i32",
  }};
  static constexpr std::array<int16_t, fields_size> fields_ids = {{
      1,
      2,
  }};
  static constexpr std::array<TType, fields_size> fields_types = {{
      TType::T_I16,
      TType::T_I32,
  }};
};

template <>
struct TStructDataStorage<::idl::thrift::cpp2::MockRequest> {
 private:
  using TType = apache::thrift::protocol::TType;

 public:
  static constexpr const std::size_t fields_size = 18;
  static constexpr std::array<folly::StringPiece, fields_size> fields_names = {{
      "var_bool",
      "var_byte",
      "var_i16",
      "var_i32",
      "var_i64",
      "var_double",
      "var_string",
      "var_binary",
      "var_string_type",
      "var_string_list",
      "var_binary_list",
      "var_string_set",
      "var_string_binary_map",
      "var_enum",
      "var_enum_set",
      "var_union",
      "var_required_i32",
      "var_optional_i32",
  }};
  static constexpr std::array<int16_t, fields_size> fields_ids = {{
      1,
      2,
      3,
      4,
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15,
      16,
      17,
      18,
  }};
  static constexpr std::array<TType, fields_size> fields_types = {{
      TType::T_BOOL,
      TType::T_BYTE,
      TType::T_I16,
      TType::T_I32,
      TType::T_I64,
      TType::T_DOUBLE,
      TType::T_STRING,
      TType::T_STRING,
      TType::T_STRING,
      TType::T_LIST,
      TType::T_LIST,
      TType::T_SET,
      TType::T_MAP,
      TType::T_I32,
      TType::T_SET,
      TType::T_STRUCT,
      TType::T_I32,
      TType::T_I32,
  }};
};

template <>
struct TStructDataStorage<::idl::thrift::cpp2::MockResponse> {
 private:
  using TType = apache::thrift::protocol::TType;

 public:
  static constexpr const std::size_t fields_size = 1;
  static constexpr std::array<folly::StringPiece, fields_size> fields_names = {{
      "req",
  }};
  static constexpr std::array<int16_t, fields_size> fields_ids = {{
      1,
  }};
  static constexpr std::array<TType, fields_size> fields_types = {{
      TType::T_STRUCT,
  }};
};

template <>
struct TStructDataStorage<::idl::thrift::cpp2::MockException> {
 private:
  using TType = apache::thrift::protocol::TType;

 public:
  static constexpr const std::size_t fields_size = 1;
  static constexpr std::array<folly::StringPiece, fields_size> fields_names = {{
      "msg",
  }};
  static constexpr std::array<int16_t, fields_size> fields_ids = {{
      1,
  }};
  static constexpr std::array<TType, fields_size> fields_types = {{
      TType::T_STRING,
  }};
};

}  // namespace thrift
}  // namespace apache
