/**
 * Autogenerated by Thrift for /home/curoky/repos/cpp/dumbo/dumbo/scaffold/serialization/fbthrift/mock.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_metadata_h.h>
#include "dumbo/scaffold/serialization/fbthrift/gen-cpp2/mock_types.h"

namespace idl {
namespace thrift {
namespace cpp2 {
class EchoServiceSvIf;
}}} // namespace idl::thrift::cpp2

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
} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache
