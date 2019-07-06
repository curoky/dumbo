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

/*
 * CULR:
 * Question 1: When is curl_global_init() necessary at all?
 * +>: https://stackoverflow.com/questions/6087886/when-is-curl-global-init-necessary-at-all
 *
 */
#include <catch2/catch.hpp>  // for StringRef, SourceLineInfo, AssertionHandler, operator""_catch_sr, CAPTURE, Capturer, REQUIRE, TEST_CASE
#include <curl/curl.h>  // for CURLE_OK, curl_easy_cleanup, curl_easy_init, curl_easy_perform, curl_easy_setopt, curl_global_cleanup, curl_global_init

#include <string>  // for allocator, string, size_t

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
  ((std::string*)userp)->append((char*)contents, size * nmemb);  // NOLINT
  return size * nmemb;
}

TEST_CASE("[Curl]: simple test") {
  CURL* curl;
  std::string readBuffer;
  curl_global_init(CURL_GLOBAL_DEFAULT);

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://httpbin.org/get");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    CURLcode res_code = curl_easy_perform(curl);
    REQUIRE(res_code == CURLE_OK);
    curl_easy_cleanup(curl);
    CAPTURE(readBuffer);
    std::string res = R"~({
  "args": {},
  "headers": {
    "Accept": "*/*",
    "Host": "httpbin.org"
  },
  "origin": "103.136.220.72, 103.136.220.72",
  "url": "https://httpbin.org/get"
})~";
    // REQUIRE(readBuffer == res);
    // std::cout << readBuffer << std::endl;
  }
  curl_global_cleanup();
}
