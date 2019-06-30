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

#include <catch2/catch.hpp>  // for operator""_catch_sr, SourceLineInfo, StringRef, AssertionHandler, FAIL, REQUIRE_...

#include <exception>  // for current_exception, rethrow_exception, exception_ptr
#include <stdexcept>  // for out_of_range
#include <string>     // for string

TEST_CASE("[CaptureException]: simple test") {
  REQUIRE_THROWS_AS(std::string().at(1), std::out_of_range);
  try {
    std::exception_ptr eptr;
    try {
      std::string().at(1);  // this generates an std::out_of_range
    } catch (...) {
      eptr = std::current_exception();  // capture
    }
    std::rethrow_exception(eptr);
  } catch (const std::out_of_range&) {
  } catch (...) {
    FAIL();
  }
}
