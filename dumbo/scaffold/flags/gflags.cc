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
 * @file: gflags.cc
 * ----------------------------------------------------------------------------
 */

// https://gflags.github.io/gflags/

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <gflags/gflags.h>  // for DEFINE_int32, DEFINE_bool, DEFINE_double, DEFINE_int64, DEFINE_string, DEFINE_uint32, DEFINE_uint64, DEFINE_validator
#include <stdint.h>         // for int32_t
#include <stdio.h>          // for printf

#include <string>  // for operator==, basic_string

DEFINE_bool(gbool, false, "");
DEFINE_int32(gint32, 1, "");
DEFINE_uint32(guint32, 1, "");
DEFINE_int64(gint64, 1, "");
DEFINE_uint64(guint64, 1, "");
DEFINE_string(gstring, "1", "");
DEFINE_double(gdouble, 1, "");

TEST_CASE("[Gflags]: type test") {
  REQUIRE(FLAGS_gbool == false);
  REQUIRE(FLAGS_gint32 == 1);
  REQUIRE(FLAGS_guint32 == 1);
  REQUIRE(FLAGS_gint64 == 1);
  REQUIRE(FLAGS_guint64 == 1);
  REQUIRE(FLAGS_gdouble == 1);
  REQUIRE(FLAGS_gstring == "1");
}
namespace {
static bool ValidatePort(const char* flagname, int32_t value) {
  if (value > 0 && value < 32768)  // value is ok
    return true;
  printf("Invalid value for --%s: %d\n", flagname, value);
  return false;
}
DEFINE_int32(port, 2333, "What port to listen on");
DEFINE_validator(port, &ValidatePort);
}  // namespace
