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
 * @file: restclient-cpp.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE, CAPTURE, Capturer, AssertionHandler, operator""_catch_sr, REQUIRE
#include "dumbo/scaffold/http/httpbin.h"         // for MapString, HttpBin
#include <nlohmann/json.hpp>            // for basic_json<>::object_t, json
#include <restclient-cpp/connection.h>  // for Connection
#include <restclient-cpp/restclient.h>  // for Response, disable, init, HeaderFields, get

#include <memory>  // for allocator, make_unique, unique_ptr
#include <string>  // for to_string, operator+, string, char_traits, basic_string

using json = nlohmann::json;

TEST_CASE("[Restclient-cpp]: simple test") {
  RestClient::Response r = RestClient::get("http://httpbin.org/get");
  CAPTURE(r.body);
  REQUIRE(r.code == 200);
}

TEST_CASE("[Restclient-cpp]: get") {
  RestClient::init();
  HttpBin::check_get([](std::string url, MapString headers, MapString params) {
    auto conn = std::make_unique<RestClient::Connection>(url);
    conn->SetHeaders(headers);
    RestClient::Response r = conn->get("?key=" + params["key"]);
    return MapString{{"code", std::to_string(r.code)}, {"body", r.body}};
  });
  RestClient::disable();
}

TEST_CASE("[Restclient-cpp]: post") {
  RestClient::init();
  HttpBin::check_post_text([](std::string url, MapString headers, std::string data) {
    auto conn = std::make_unique<RestClient::Connection>(url);
    conn->SetHeaders(headers);
    RestClient::Response r = conn->post("", data);
    return MapString{{"code", std::to_string(r.code)}, {"body", r.body}};
  });
  HttpBin::check_post_form([](std::string url, MapString headers, MapString data) {
    auto conn = std::make_unique<RestClient::Connection>(url);
    conn->SetHeaders(headers);
    RestClient::Response r = conn->post("", "key=" + data["key"]);
    return MapString{{"code", std::to_string(r.code)}, {"body", r.body}};
  });
  HttpBin::check_post_json([](std::string url, MapString headers, MapString data) {
    auto conn = std::make_unique<RestClient::Connection>(url);
    conn->SetHeaders(headers);
    RestClient::Response r = conn->post("", json(data).dump());
    return MapString{{"code", std::to_string(r.code)}, {"body", r.body}};
  });
  RestClient::disable();
}

TEST_CASE("[Restclient-cpp]: basic auth") {
  RestClient::init();
  HttpBin::check_basic_auth([](std::string url, std::string username, std::string password) {
    auto conn = std::make_unique<RestClient::Connection>(url);
    conn->SetBasicAuth(username, password);
    RestClient::Response r = conn->get("");
    return MapString{{"code", std::to_string(r.code)}, {"body", r.body}};
  });
  RestClient::disable();
}

TEST_CASE("[Restclient-cpp]: cookies") {
  RestClient::init();
  HttpBin::check_cookies([](std::string url, MapString cookies) {
    auto conn = std::make_unique<RestClient::Connection>(url);
    conn->AppendHeader("Cookie", "key=" + cookies["key"]);
    RestClient::Response r = conn->get("");
    CAPTURE(r.headers);
    CAPTURE(r.body);
    return MapString{{"code", std::to_string(r.code)}, {"body", r.body}};
  });
  RestClient::disable();
}