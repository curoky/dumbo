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

#include <thrift/lib/cpp2/visitation/for_each.h>

#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/mock_metadata.h"

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::idl::thrift::cpp2::UnionType> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).var_i16_ref()...);
    f(1, static_cast<T&&>(t).var_i32_ref()...);
  }
};

template <>
struct ForEachField<::idl::thrift::cpp2::MockRequest> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).var_bool_ref()...);
    f(1, static_cast<T&&>(t).var_byte_ref()...);
    f(2, static_cast<T&&>(t).var_i16_ref()...);
    f(3, static_cast<T&&>(t).var_i32_ref()...);
    f(4, static_cast<T&&>(t).var_i64_ref()...);
    f(5, static_cast<T&&>(t).var_double_ref()...);
    f(6, static_cast<T&&>(t).var_string_ref()...);
    f(7, static_cast<T&&>(t).var_binary_ref()...);
    f(8, static_cast<T&&>(t).var_string_type_ref()...);
    f(9, static_cast<T&&>(t).var_string_list_ref()...);
    f(10, static_cast<T&&>(t).var_binary_list_ref()...);
    f(11, static_cast<T&&>(t).var_string_set_ref()...);
    f(12, static_cast<T&&>(t).var_string_binary_map_ref()...);
    f(13, static_cast<T&&>(t).var_enum_ref()...);
    f(14, static_cast<T&&>(t).var_enum_set_ref()...);
    f(15, static_cast<T&&>(t).var_union_ref()...);
    f(16, static_cast<T&&>(t).var_required_i32_ref()...);
    f(17, static_cast<T&&>(t).var_optional_i32_ref()...);
  }
};

template <>
struct ForEachField<::idl::thrift::cpp2::MockResponse> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).req_ref()...);
  }
};

template <>
struct ForEachField<::idl::thrift::cpp2::MockException> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).msg_ref()...);
  }
};
}  // namespace detail
}  // namespace thrift
}  // namespace apache
