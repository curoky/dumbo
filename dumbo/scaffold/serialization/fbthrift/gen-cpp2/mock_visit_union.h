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

#include <thrift/lib/cpp2/visitation/visit_union.h>

#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/mock_metadata.h"

namespace apache {
namespace thrift {
namespace detail {

template <>
struct VisitUnion<::idl::thrift::cpp2::UnionType> {
  template <typename F, typename T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, T&& t) const {
    using Union = std::remove_reference_t<T>;
    switch (t.getType()) {
      case Union::Type::var_i16:
        return f(0, *static_cast<T&&>(t).var_i16_ref());
      case Union::Type::var_i32:
        return f(1, *static_cast<T&&>(t).var_i32_ref());
      case Union::Type::__EMPTY__:;
    }
  }
};
}  // namespace detail
}  // namespace thrift
}  // namespace apache
