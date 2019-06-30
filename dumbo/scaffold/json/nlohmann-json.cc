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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, REQUIRE_FALSE, TEST_CASE
#include <nlohmann/json.hpp>  // for basic_json, basic_json<>::object_t, operator==, operator<<, basic_json<>::type_error, basic_json<>::value...
#include <tbb/concurrent_unordered_map.h>  // for concurrent_unordered_map, operator!=, tbb_hash
#include <tbb/concurrent_unordered_set.h>  // for concurrent_unordered_set
#include <tbb/concurrent_vector.h>         // for concurrent_vector, operator!=, operator-
#include <tbb/tbb_allocator.h>             // for tbb_allocator

#include <functional>        // for equal_to
#include <initializer_list>  // for initializer_list
#include <stdexcept>         // for out_of_range
#include <string>            // for string, basic_string, operator==, hash
#include <unordered_map>     // for unordered_map
#include <vector>            // for vector, allocator

#include "dumbo/scaffold/json/json_data.h"  // for json_data

// for convenience
using json = nlohmann::json;

TEST_CASE("[Nlohmann-json]: parse json") {
  auto params = json::parse(json_data);
  REQUIRE(params.is_object());

  auto& key_int = params["key_int"];
  REQUIRE(key_int.is_number_integer());
  REQUIRE(key_int.is_number_unsigned());
  REQUIRE_FALSE(key_int.is_number_float());
  REQUIRE(key_int == 1);

  auto& key_str = params["key_str"];
  REQUIRE(key_str.is_string());
  REQUIRE_FALSE(key_str.is_number_integer());
  REQUIRE(key_str == "value2");

  auto& key_bool = params["key_bool"];
  REQUIRE(key_bool.is_boolean());
  REQUIRE_FALSE(key_bool.is_number());
  REQUIRE_FALSE(key_bool.is_number_float());
  REQUIRE(key_bool == false);

  auto& key_null = params["key_null"];
  REQUIRE(key_null.is_null());

  auto& key_double = params["key_double"];
  REQUIRE(key_double.is_number_float());
  REQUIRE_FALSE(key_double.is_number_integer());
  REQUIRE(key_double == 1.1e100);

  auto& key_double2 = params["key_double2"];
  REQUIRE(key_double2 == -0.123);

  auto& key_list_eq = params["key_list_eq"];
  REQUIRE(key_list_eq.is_array());
  REQUIRE(key_list_eq == std::vector<int>{1, 2, 3});
  REQUIRE(key_list_eq.at(2) == 3);

  auto& key_list_mix = params["key_list_mix"];
  REQUIRE(key_list_mix.is_array());
  REQUIRE(key_list_mix.at(0) == "1");
  REQUIRE(key_list_mix.at(1) == 2);
  {
    auto& key_map_eq = params["key_map_eq"];
    REQUIRE(key_map_eq.is_object());
    REQUIRE(key_map_eq.count("kk1") == 1);
    REQUIRE(key_map_eq["kk2"] == "2");

    std::unordered_map<std::string, std::string> string_map =
        key_map_eq.get<std::unordered_map<std::string, std::string>>();
    REQUIRE(string_map.size() == 2);
  }
  {
    auto& key_map_mix = params["key_map_mix"];
    REQUIRE(key_map_mix.is_object());
    REQUIRE(key_map_mix.at("kk1") == 1);
    REQUIRE(key_map_mix.at("kk3").at(2) == 3);

    bool have_except = false;
    try {
      std::unordered_map<std::string, std::string> string_map =
          key_map_mix.get<std::unordered_map<std::string, std::string>>();
      REQUIRE(string_map.size() == 3);
    } catch (json::type_error& e) {
      have_except = true;
      REQUIRE(e.what() ==
              std::string("[json.exception.type_error.302] type must be string, but is number"));
    }
    REQUIRE(have_except == true);
  }
}

namespace tbb {
void to_json(json& j, const concurrent_unordered_set<std::string>& p) {}

void from_json(const json& j, concurrent_unordered_set<std::string>& p) {}
}  // namespace tbb

TEST_CASE("[Nlohmann-json]: tbb to/from json") {
  json j;
  {
    tbb::concurrent_vector<int> vec;
    j["vec"] = vec;
  }
  {
    tbb::concurrent_unordered_set<std::string> set;
    j["set"] = set;
  }
  {
    tbb::concurrent_unordered_map<int, std::string> map;
    j["map"] = map;
  }
}
