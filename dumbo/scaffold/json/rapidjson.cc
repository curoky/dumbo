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
 * @file: rapidjson.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>                 // for AssertionHandler, operator""_catch_sr, StringRef, SourceLineInfo, REQUIRE, REQUIRE_FALSE, CAPTURE, Capturer
#include <rapidjson/document.h>             // for GenericValue, Document, Value, GenericMemberIterator, SelectIfImpl<>::Apply<>::Type, GenericDocument, Gen...
#include <rapidjson/rapidjson.h>            // for rapidjson
#include <string>                           // for operator""s, operator==, basic_string, string
#include <string_view>                      // for literals

#include "dumbo/scaffold/json/json_data.h"  // for json_data

namespace rp = rapidjson;
using namespace std::literals;

TEST_CASE("[Rapidjson]: parse json") {
  rp::Document doc;
  REQUIRE_FALSE(doc.Parse(json_data.data()).HasParseError());
  REQUIRE(doc.IsObject());

  REQUIRE(doc.HasMember("key_int"));
  const rp::Value& key_int = doc["key_int"];
  REQUIRE(key_int.IsInt());
  REQUIRE(key_int.IsInt64());
  REQUIRE_FALSE(key_int.IsDouble());
  REQUIRE(key_int.GetInt() == 1);

  REQUIRE(doc.HasMember("key_str"));
  REQUIRE(doc["key_str"].IsString());
  REQUIRE(doc["key_str"].GetString() == "value2"s);

  REQUIRE(doc.HasMember("key_bool"));
  REQUIRE(doc["key_bool"].GetBool() == false);

  REQUIRE(doc.HasMember("key_null"));
  REQUIRE(doc["key_null"].IsNull());

  REQUIRE(doc["key_double"].GetDouble() == 1.1e+100);
  REQUIRE(doc["key_double2"].GetDouble() == -0.123);

  auto& key_list_eq = doc["key_list_eq"];
  REQUIRE(key_list_eq.IsArray());
  REQUIRE(key_list_eq.Size() == 3);
  for (auto& v : key_list_eq.GetArray()) {
    REQUIRE(v.IsInt64());
  }

  auto& key_list_mix = doc["key_list_mix"];
  REQUIRE(key_list_mix.Size() == 3);
  REQUIRE(key_list_mix[0].GetString() == "1"s);
  REQUIRE(key_list_mix[1].IsInt());
  rp::Value::ConstValueIterator itr = key_list_mix.Begin();
  REQUIRE(itr->IsString());
  REQUIRE((itr + 1)->GetInt64() == 2);

  auto& key_map_eq = doc["key_map_eq"];
  CAPTURE(key_map_eq.IsObject());
  REQUIRE(key_map_eq.IsObject() == true);
  REQUIRE(key_map_eq["kk1"].GetString() == "1"s);
  for (const auto& item : key_map_eq.GetObject()) {
    REQUIRE(item.value.IsString());
  }

  auto& key_map_mix = doc["key_map_mix"];
  rp::Value::ConstMemberIterator itr2 = key_map_mix.MemberBegin();
  REQUIRE(itr2->value.GetInt64() == 1);
  REQUIRE((itr2 + 2)->value.IsArray());
}
