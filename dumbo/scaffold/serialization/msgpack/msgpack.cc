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

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE
#include <msgpack.hpp>       // for tuple, object, pack, unpack, object_handle

#include <istream>  // for stringstream, basic_istream::seekg
#include <string>   // for string

TEST_CASE("[Msgpack]: simple test") {
  msgpack::type::tuple<int, bool, std::string> src(1, true, "example");

  // serialize the object into the buffer.
  // any classes that implements write(const char*,size_t) can be a buffer.
  std::stringstream buffer;
  msgpack::pack(buffer, src);

  // send the buffer ...
  buffer.seekg(0);

  // deserialize the buffer into msgpack::object instance.
  std::string str(buffer.str());

  msgpack::object_handle oh = msgpack::unpack(str.data(), str.size());

  // deserialized object is valid during the msgpack::object_handle instance is alive.
  msgpack::object deserialized = oh.get();

  // msgpack::object supports ostream.
  // std::cout << deserialized << std::endl;

  // convert msgpack::object instance into the original type.
  // if the type is mismatched, it throws msgpack::type_error exception.
  msgpack::type::tuple<int, bool, std::string> dst;
  deserialized.convert(dst);

  // or create the new instance
  msgpack::type::tuple<int, bool, std::string> dst2 =
      deserialized.as<msgpack::type::tuple<int, bool, std::string>>();
}
