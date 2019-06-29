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

#pragma once

#include <thrift/lib/cpp2/gen/module_metadata_h.h>

#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/mock_types.h"

namespace idl {
namespace thrift {
namespace cpp2 {
class EchoServiceSvIf;
}
}  // namespace thrift
}  // namespace idl

namespace apache {
namespace thrift {
namespace detail {
namespace md {

template <>
class EnumMetadata<::idl::thrift::cpp2::EnumType> {
 public:
  static void gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::idl::thrift::cpp2::UnionType> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::idl::thrift::cpp2::MockRequest> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::idl::thrift::cpp2::MockResponse> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class StructMetadata<::idl::thrift::cpp2::MockException> {
 public:
  static const ::apache::thrift::metadata::ThriftStruct& gen(ThriftMetadata& metadata);
};
template <>
class ExceptionMetadata<::idl::thrift::cpp2::MockException> {
 public:
  static void gen(ThriftMetadata& metadata);
};
template <>
class ServiceMetadata<::idl::thrift::cpp2::EchoServiceSvIf> {
 public:
  static void gen(ThriftMetadata& metadata, ThriftServiceContext& context);

 private:
  static void gen_echo(ThriftMetadata& metadata, ThriftService& context);
  static void gen_oneway_echo(ThriftMetadata& metadata, ThriftService& context);
};
}  // namespace md
}  // namespace detail
}  // namespace thrift
}  // namespace apache
