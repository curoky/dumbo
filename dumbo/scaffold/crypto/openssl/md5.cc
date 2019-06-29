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

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE
#include <openssl/md5.h>  // for MD5, MD5_DIGEST_LENGTH

#include <string>  // for string, allocator

namespace {
std::string md5(const std::string& data) {
  std::string output;
  output.resize(MD5_DIGEST_LENGTH);
  MD5(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(),
      reinterpret_cast<unsigned char*>(output.data()));
  return output;
}
}  // namespace

TEST_CASE("[Md5]: md5") {
  std::string data = "123123123";
  std::string data_md5 = md5(data);
  REQUIRE(data_md5.size() == 16);
}

// https://wiki.openssl.org/index.php/EVP_Symmetric_Encryption_and_Decryption
