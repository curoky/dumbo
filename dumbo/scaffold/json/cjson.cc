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
 * @file: cjson.cc
 * ----------------------------------------------------------------------------
 */

// https://cloud.tencent.com/developer/article/1055318

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <cjson/cJSON.h>  // for cJSON_GetObjectItem, cJSON, cJSON_IsNumber, cJSON_GetArraySize, cJSON_IsArray, cJSON_IsBool, cJSON_IsFalse, cJSON_IsNull

#include <string>       // for operator""s, operator==, basic_string, string
#include <string_view>  // for literals

#include "dumbo/scaffold/json/json_data.h"  // for json_data

using namespace std::literals;

TEST_CASE("[Cjson]: parse json") {
  cJSON* params = cJSON_Parse(json_data.data());

  REQUIRE(cJSON_GetObjectItem(params, "firstName") == nullptr);

  cJSON* key_int = cJSON_GetObjectItem(params, "key_int");
  REQUIRE(cJSON_IsNumber(key_int));
  REQUIRE(key_int->valueint == 1);

  cJSON* key_str = cJSON_GetObjectItem(params, "key_str");
  REQUIRE(cJSON_IsString(key_str));
  REQUIRE(key_str->valuestring == "value2"s);

  cJSON* key_bool = cJSON_GetObjectItem(params, "key_bool");
  REQUIRE(cJSON_IsBool(key_bool));
  REQUIRE(cJSON_IsFalse(key_bool));

  cJSON* key_null = cJSON_GetObjectItem(params, "key_null");
  REQUIRE(cJSON_IsNull(key_null));

  cJSON* key_double = cJSON_GetObjectItem(params, "key_double");
  REQUIRE(cJSON_IsNumber(key_double));
  REQUIRE(key_double->valuedouble == 1.1e+100);

  cJSON* key_double2 = cJSON_GetObjectItem(params, "key_double2");
  REQUIRE(cJSON_IsNumber(key_double2));
  REQUIRE(key_double2->valuedouble == -0.123);

  cJSON* key_list_eq = cJSON_GetObjectItem(params, "key_list_eq");
  REQUIRE(cJSON_IsArray(key_list_eq));
  REQUIRE(cJSON_GetArraySize(key_list_eq) == 3);

  cJSON* key_list_mix = cJSON_GetObjectItem(params, "key_list_mix");
  REQUIRE(cJSON_GetArraySize(key_list_mix) == 3);
  cJSON* key_list_mix_0 = cJSON_GetArrayItem(key_list_mix, 0);
  REQUIRE(key_list_mix_0->valuestring == "1"s);
  cJSON* key_list_mix_1 = cJSON_GetArrayItem(key_list_mix, 1);
  REQUIRE(key_list_mix_1->valueint == 2);

  cJSON* key_map_eq = cJSON_GetObjectItem(params, "key_map_eq");
  REQUIRE(cJSON_IsObject(key_map_eq));
  REQUIRE(cJSON_GetObjectItem(key_map_eq, "kk0") == nullptr);
  REQUIRE(cJSON_GetObjectItem(key_map_eq, "kk1") != nullptr);
  cJSON* kk2 = cJSON_GetObjectItem(key_map_eq, "kk2");
  REQUIRE(kk2->valuestring == "2"s);

  cJSON* key_map_mix = cJSON_GetObjectItem(params, "key_map_mix");
  cJSON* kk3 = cJSON_GetObjectItem(key_map_mix, "kk3");
  REQUIRE(cJSON_IsArray(kk3));

  cJSON_Delete(params);
}
