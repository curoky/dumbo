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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <google/protobuf/any.pb.h>        // for RepeatedField, RepeatedPtrField, Any
#include <google/protobuf/stubs/common.h>  // for string

#include <cstdint>   // for int32_t, int64_t, uint32_t, uint64_t
#include <string>    // for string
#include <typeinfo>  // for type_info

#include "dumbo/scaffold/serialization/protobuf/mock.pb.h"  // for MockRequest, MockRequest_EnumType, MockRequest_InnerClass, Map

#pragma GCC diagnostic push
// #pragma GCC diagnostic ignored "-Wpotentially-evaluated-expression"

#define REQUIRE_TYPE(var, type) REQUIRE(typeid(var) == typeid(type));

TEST_CASE("[Type]: pb basic type") {
  idl::pb::MockRequest req;
  REQUIRE_TYPE(req.var_bool(), bool);
  REQUIRE_TYPE(req.var_int32(), int32_t);
  REQUIRE_TYPE(req.var_int64(), int64_t);
  REQUIRE_TYPE(req.var_uint32(), uint32_t);
  REQUIRE_TYPE(req.var_uint64(), uint64_t);
  REQUIRE_TYPE(req.var_float(), float);
  REQUIRE_TYPE(req.var_double(), double);
  REQUIRE_TYPE(req.var_str(), std::string);
  REQUIRE_TYPE(req.var_bytes(), std::string);
}

TEST_CASE("[Type]: pb enum") {
  idl::pb::MockRequest req;
  REQUIRE_TYPE(req.var_enum(), ::idl::pb::MockRequest_EnumType);
}

TEST_CASE("[Type]: pb container") {
  idl::pb::MockRequest req;
  REQUIRE_TYPE(req.var_int32_list(), google::protobuf::RepeatedField<int32_t>);
  REQUIRE_TYPE(req.var_string_list(), google::protobuf::RepeatedPtrField<std::string>);
  using MapI32Str = google::protobuf::Map<int32_t, std::string>;
  REQUIRE_TYPE(req.var_map(), MapI32Str);
}

TEST_CASE("[Type]: pb InnerClass") {
  idl::pb::MockRequest req;
  REQUIRE_TYPE(req.var_inner_class(), idl::pb::MockRequest_InnerClass);
}

TEST_CASE("[Type]: pb any") {
  idl::pb::MockRequest req;
  REQUIRE_TYPE(req.var_any(), google::protobuf::Any);
}

TEST_CASE("[Type]: pb oneof") {
  idl::pb::MockRequest req;
  REQUIRE_TYPE(req.var_oneof_bool(), bool);
  REQUIRE_TYPE(req.var_oneof_int32(), int32_t);
}

#pragma GCC diagnostic pop
