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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <json/json.h>  // for Value, String, CharReader, ValueConstIterator, CharReaderBuilder, JSONCPP_STRING, ValueIteratorBase

#include <memory>       // for unique_ptr
#include <string>       // for operator==, basic_string
#include <string_view>  // for string_view

#include "dumbo/scaffold/json/json_data.h"  // for json_data

TEST_CASE("[Jsoncpp]: parse json") {
  Json::Value params;
  JSONCPP_STRING err;
  Json::CharReaderBuilder builder;
  const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
  REQUIRE(reader->parse(json_data.data(), json_data.data() + json_data.size(), &params, &err));

  REQUIRE(params.isObject());
  REQUIRE(params.get("123", "123").asString() == "123");
  REQUIRE(params["123"].empty());
  REQUIRE(params["123"].isNull());

  REQUIRE(params["key_int"].asInt() == 1);
  REQUIRE(params["key_str"].asString() == "value2");
  REQUIRE(params["key_bool"].asBool() == false);
  REQUIRE(params["key_null"].isNull());
  REQUIRE(params["key_double"].asDouble() == 1.1e+100);
  REQUIRE(params["key_double2"].asDouble() == -0.123);

  const Json::Value& key_list_eq = params["key_list_eq"];
  REQUIRE(key_list_eq.isArray());
  REQUIRE(key_list_eq.size() == 3);
  for (auto& key : key_list_eq) {
    REQUIRE(key.isInt64());
  }

  const Json::Value& key_list_mix = params["key_list_mix"];
  REQUIRE(key_list_mix[0].asString() == "1");
  REQUIRE(key_list_mix[1].isInt64());

  const Json::Value& key_map_eq = params["key_map_eq"];
  REQUIRE(key_map_eq["kk1"].isString());
  REQUIRE(key_map_eq["kk2"].asString() == "2");

  const Json::Value& key_map_mix = params["key_map_mix"];
  REQUIRE(key_map_mix["kk1"].isInt());
  REQUIRE(key_map_mix["kk2"].asString() == "2");
  REQUIRE(key_map_mix["kk3"].isArray());
}
