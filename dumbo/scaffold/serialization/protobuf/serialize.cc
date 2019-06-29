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

#include <catch2/catch.hpp>

#include <string>

#include "dumbo/scaffold/serialization/protobuf/mock.pb.h"

TEST_CASE("[Serialize]: pb serialize") {
  idl::pb::MockRequest req;
  req.set_var_bool(true);
  req.set_var_int32(1);
  req.set_var_float(1);

  req.set_var_enum(idl::pb::MockRequest_EnumType::MockRequest_EnumType_ONE);
  req.add_var_int32_list(1);
  req.add_var_string_list();

  std::string serialize_data;
  SECTION("debug string") {
    // "var_bool: true
    // var_int32: 1
    // var_float: 1
    // var_int32_list: 1
    // var_string_list: """
    serialize_data = req.DebugString();
  }

  SECTION("short debug string") {
    // "var_bool: true var_int32: 1 var_float: 1 var_int32_list: 1 var_string_list: """
    serialize_data = req.ShortDebugString();
  }

  SECTION("utf8 debug string") {
    // "var_bool: true
    // var_int32: 1
    // var_float: 1
    // var_int32_list: 1
    // var_string_list: """
    serialize_data = req.Utf8DebugString();
  }
  SECTION("serialize string ") {
    REQUIRE(req.SerializeToString(&serialize_data) == true);
    idl::pb::MockRequest req_copy;
    REQUIRE(req_copy.ParseFromString(serialize_data) == true);
  }

  CAPTURE(serialize_data);
}
