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

// https://juejin.im/post/5b39a111f265da59a4020309

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, REQUIRE, SourceLineInfo, StringRef, TEST_CASE
#include <flatbuffers/flatbuffers.h>  // for Vector (ptr only), String (ptr only), Offset (ptr only), FlatBufferBuilder
#include <stdint.h>  // for int32_t, int8_t, int16_t, int64_t, uint16_t, uint32_t, uint64_t, uint8_t

#include <typeinfo>  // for type_info

#include "dumbo/scaffold/serialization/flatbuffers/mock_generated.h"  // for MockRequest, CreateMockRequestDirect, EnumType, GetMockRequest

#define REQUIRE_TYPE(var, type) REQUIRE(typeid(var) == typeid(type));

TEST_CASE("[Type]: fb type") {
  return;
  flatbuffers::FlatBufferBuilder builder;
  idl::fb::CreateMockRequestDirect(builder);
  const idl::fb::MockRequest* req = idl::fb::GetMockRequest(builder.GetBufferPointer());

  REQUIRE_TYPE(req->var_bool(), bool);
  REQUIRE_TYPE(req->var_byte(), int8_t);
  REQUIRE_TYPE(req->var_ubyte(), uint8_t);
  REQUIRE_TYPE(req->var_short(), int16_t);
  REQUIRE_TYPE(req->var_ushort(), uint16_t);
  REQUIRE_TYPE(req->var_int(), int32_t);
  REQUIRE_TYPE(req->var_uint(), uint32_t);
  REQUIRE_TYPE(req->var_long(), int64_t);
  REQUIRE_TYPE(req->var_ulong(), uint64_t);
  REQUIRE_TYPE(req->var_float(), float);
  REQUIRE_TYPE(req->var_double(), double);
  REQUIRE_TYPE(req->var_string(), const flatbuffers::String*);

  REQUIRE_TYPE(req->var_int_list(), const flatbuffers::Vector<int32_t>*);
  REQUIRE_TYPE(req->var_byte_list(), const flatbuffers::Vector<int8_t>*);
  REQUIRE_TYPE(req->var_string_list(),
               const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>*);
  REQUIRE_TYPE(req->var_enum(), idl::fb::EnumType);
}
