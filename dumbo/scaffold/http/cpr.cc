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
 * @file: cpr.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>               // for StringRef, SourceLineInfo, TEST_CASE, AssertionHandler, operator""_catch_sr, CAPTURE, Capturer, REQUIRE
#include <cpr/cpr.h>                      // for Response, Get, Post, Url, Header, Body, Authentication, Cookies, Parameters, Payload
#include <nlohmann/json.hpp>              // for basic_json<>::object_t
#include <map>                            // for map<>::mapped_type, map
#include <string>                         // for string, to_string, move, allocator, basic_string

#include "dumbo/scaffold/http/httpbin.h"  // for MapString, HttpBin, json

// https://whoshuu.github.io/cpr/

TEST_CASE("[Cpr]: simple test") {
  auto r = cpr::Get(cpr::Url("http://httpbin.org/get"));
  CAPTURE(r.text);
  REQUIRE(r.status_code == 200);
}

TEST_CASE("[Cpr]: get") {
  HttpBin::check_get([](std::string url, MapString headers, MapString params) {
    cpr::Header pheaders(headers.begin(), headers.end());
    cpr::Parameters pparams{{"key", std::move(params["key"])}};
    auto r = cpr::Get(cpr::Url(url), pheaders, pparams);
    return MapString{{"code", std::to_string(r.status_code)}, {"body", r.text}};
  });
}

TEST_CASE("[Cpr]: post") {
  HttpBin::check_post_text([](std::string url, MapString headers, std::string data) {
    cpr::Header pheaders(headers.begin(), headers.end());
    cpr::Body pdata(data);
    cpr::Response r = cpr::Post(cpr::Url(url), pheaders, pdata);
    return MapString{{"code", std::to_string(r.status_code)}, {"body", r.text}};
  });
  HttpBin::check_post_form([](std::string url, MapString headers, MapString data) {
    cpr::Header pheaders(headers.begin(), headers.end());
    cpr::Payload pdata{{"key", std::move(data["key"])}};
    cpr::Response r = cpr::Post(cpr::Url(url), pheaders, pdata);
    return MapString{{"code", std::to_string(r.status_code)}, {"body", r.text}};
  });
  HttpBin::check_post_json([](std::string url, MapString headers, MapString data) {
    cpr::Header pheaders(headers.begin(), headers.end());
    cpr::Body pdata(json(data).dump());
    cpr::Response r = cpr::Post(cpr::Url(url), pheaders, pdata);
    return MapString{{"code", std::to_string(r.status_code)}, {"body", r.text}};
  });
}

TEST_CASE("[Cpr]: basic auth") {
  HttpBin::check_basic_auth([](std::string url, std::string username, std::string password) {
    cpr::Response r =
        cpr::Get(cpr::Url(url), cpr::Authentication{std::move(username), std::move(password)});
    return MapString{{"code", std::to_string(r.status_code)}, {"body", r.text}};
  });
}

TEST_CASE("[Cpr]: cookies") {
  HttpBin::check_cookies([](std::string url, MapString cookies) {
    cpr::Response r = cpr::Get(cpr::Url(url), cpr::Cookies{{"key", cookies["key"]}});
    return MapString{{"code", std::to_string(r.status_code)}, {"body", r.text}};
  });
}
