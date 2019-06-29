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
#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, StringRef, SourceLineInfo, REQUIRE, CAPTURE, Capturer
#include <nlohmann/json.hpp>  // for basic_json, basic_json<>::object_t, operator==, operator<<, basic_json<>::value_type, json

#include <functional>        // for function
#include <initializer_list>  // for initializer_list
#include <map>               // for map<>::mapped_type, map
#include <string>  // for string, allocator, operator==, basic_string, char_traits, operator+
#include <vector>  // for vector

using json = nlohmann::json;
using MapString = std::map<std::string, std::string>;

class HttpBin {
 public:
  static void check_get(std::function<MapString(std::string, MapString, MapString)> func) {
    MapString headers{{"accept", "application/json"}};
    MapString params{{"key", "value"}};  // Parameters
    MapString result = func("https://httpbin.org/get", headers, params);
    REQUIRE(result["code"] == "200");

    // {
    //     "args": {
    //         "key": "value"
    //     },
    //     "headers": {
    //         "Accept": "application/json",
    //         "Host": "httpbin.org",
    //         "User-Agent": "curl/7.66.0-DEV"
    //     },
    //     "url": "https://httpbin.org/get?key=value"
    // }
    auto body = json::parse(result["body"]);
    CAPTURE(body.dump(4));
    REQUIRE(body["args"]["key"] == "value");
    REQUIRE(body["headers"]["Accept"] == "application/json");
    REQUIRE(body["url"] == "https://httpbin.org/get?key=value");
  }

  static void check_post_text(std::function<MapString(std::string, MapString, std::string)> func) {
    MapString headers{{"accept", "application/json"}, {"Content-Type", "text/plain"}};
    std::string data = "raw data";
    MapString result = func("https://httpbin.org/post", headers, data);

    REQUIRE(result["code"] == "200");
    auto body = json::parse(result["body"]);
    CAPTURE(body.dump(4));
    // {
    //     "args": {},
    //     "data": "raw data",
    //     "files": {},
    //     "form": {},
    //     "headers": {
    //         "Accept": "application/json",
    //         "Content-Length": "9",
    //         "Content-Type": "application/x-www-form-urlencoded",
    //         "Host": "httpbin.org",
    //         "User-Agent": "curl/7.66.0-DEV"
    //     },
    //     "json": null,
    //     "url": "https://httpbin.org/post"
    // }

    REQUIRE(body["headers"]["Accept"] == headers["accept"]);
    REQUIRE(body["headers"]["Content-Type"] == headers["Content-Type"]);
    REQUIRE(body["url"] == "https://httpbin.org/post");
    REQUIRE(body["data"] == data);
    REQUIRE(body["form"].empty());
  }

  static void check_post_form(std::function<MapString(std::string, MapString, MapString)> func) {
    MapString headers{{"accept", "application/json"},
                      {"Content-Type", "application/x-www-form-urlencoded"}};
    MapString data{{"key", "value"}};  // Payload
    MapString result = func("https://httpbin.org/post", headers, data);

    REQUIRE(result["code"] == "200");
    auto body = json::parse(result["body"]);
    CAPTURE(body.dump(4));

    // {
    //     "args": {},
    //     "data": "",
    //     "files": {},
    //     "form": {
    //         "key": "value"
    //     },
    //     "headers": {
    //         "Accept": "application/json",
    //         "Content-Length": "9",
    //         "Content-Type": "application/x-www-form-urlencoded",
    //         "Host": "httpbin.org",
    //         "User-Agent": "curl/7.66.0-DEV"
    //     },
    //     "json": null,
    //     "url": "https://httpbin.org/post"
    // }

    REQUIRE(body["headers"]["Accept"] == headers["accept"]);
    REQUIRE(body["headers"]["Content-Type"] == headers["Content-Type"]);
    REQUIRE(body["url"] == "https://httpbin.org/post");
    REQUIRE(body["form"]["key"] == data["key"]);
    REQUIRE(body["data"] == "");
  }

  static void check_post_json(std::function<MapString(std::string, MapString, MapString)> func) {
    MapString headers{{"accept", "application/json"}, {"Content-Type", "application/json"}};
    MapString data{{"key", "value"}};  // Payload
    MapString result = func("https://httpbin.org/post", headers, data);

    REQUIRE(result["code"] == "200");
    auto body = json::parse(result["body"]);
    CAPTURE(body.dump(4));

    // {
    //     "args": {},
    //     "data": "{\"key\":\"value\"}",
    //     "files": {},
    //     "form": {},
    //     "headers": {
    //         "Accept": "application/json",
    //         "Content-Length": "15",
    //         "Content-Type": "application/json",
    //         "Host": "httpbin.org",
    //         "User-Agent": "restclient-cpp/0.5.0"
    //     },
    //     "json": {
    //         "key": "value"
    //     },
    //     "origin": "103.136.220.72, 103.136.220.72",
    //     "url": "https://httpbin.org/post"
    // }
    REQUIRE(body["headers"]["Accept"] == headers["accept"]);
    REQUIRE(body["headers"]["Content-Type"] == headers["Content-Type"]);
    REQUIRE(body["url"] == "https://httpbin.org/post");
    REQUIRE(body["json"] == json(data));
  }

  static void check_basic_auth(
      std::function<MapString(std::string, std::string, std::string)> func) {
    std::string username = "username";
    std::string password = "password";
    std::string url = "https://httpbin.org/basic-auth/" + username + "/" + password;
    MapString result = func(url, username, password);
    REQUIRE(result["code"] == "200");
    auto body = json::parse(result["body"]);
    CAPTURE(body.dump(4));

    // {
    //     "authenticated": true,
    //     "user": "username"
    // }
    REQUIRE(body["authenticated"] == true);
    REQUIRE(body["user"] == username);
  }

  static void check_cookies(std::function<MapString(std::string, MapString)> fun) {
    MapString cookies{{"key", "value"}};
    MapString result = fun("https://httpbin.org/cookies", cookies);
    REQUIRE(result["code"] == "200");
    auto body = json::parse(result["body"]);
    CAPTURE(body.dump(4));
    // {
    //     "cookies": {
    //         "key": "value"
    //     }
    // }
    REQUIRE(body["cookies"]["key"] == cookies["key"]);
  }
};
