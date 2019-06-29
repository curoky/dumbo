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
 * @file: serialize_helper.h
 * ----------------------------------------------------------------------------
 */

#pragma once
#include <stdint.h>                              // for uint8_t, uint32_t
#include <thrift/protocol/TBinaryProtocol.h>     // for TBinaryProtocol
#include <thrift/protocol/TCompactProtocol.h>
#include <thrift/protocol/TDebugProtocol.h>
#include <thrift/protocol/THeaderProtocol.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/transport/TBufferTransports.h>  // for TMemoryBuffer, TMemoryBuffer::COPY, TMemoryBuffer::MemoryPolicy
#include <memory>                                // for shared_ptr
#include <string>                                // for string

namespace apache::thrift::protocol {
class TDebugProtocol;
class TJSONProtocol;
}  // namespace apache::thrift::protocol
namespace apache::thrift::transport {
class TTransport;
}  // namespace apache::thrift::transport

using apache::thrift::protocol::TBinaryProtocol;
using apache::thrift::protocol::TDebugProtocol;
using apache::thrift::protocol::TJSONProtocol;

namespace detail {
template <typename ThriftStruct, typename Protocol>
std::string ThriftToString(const ThriftStruct& ts) {
  using apache::thrift::transport::TMemoryBuffer;
  using apache::thrift::transport::TTransport;
  TMemoryBuffer* buffer = new TMemoryBuffer;
  std::shared_ptr<TTransport> trans(buffer);
  Protocol protocol(trans);
  ts.write(&protocol);
  uint8_t* buf;
  uint32_t size;
  buffer->getBuffer(&buf, &size);
  return std::string((char*)buf, (unsigned int)size);
}

template <typename ThriftStruct, typename Protocol>
ThriftStruct StringToThrift(const std::string& str) {
  using apache::thrift::transport::TMemoryBuffer;
  using apache::thrift::transport::TTransport;
  uint8_t* buf = reinterpret_cast<uint8_t*>(const_cast<char*>(str.data()));
  TMemoryBuffer* buffer = new TMemoryBuffer(buf, str.size(), TMemoryBuffer::MemoryPolicy::COPY);
  std::shared_ptr<TTransport> trans(buffer);
  Protocol protocol(trans);
  ThriftStruct result;
  result.read(&protocol);
  return result;
}
}  // namespace detail

template <typename ThriftStruct>
const auto ThriftToJson = detail::ThriftToString<ThriftStruct, TJSONProtocol>;

template <typename ThriftStruct>
const auto ThriftToDebug = detail::ThriftToString<ThriftStruct, TDebugProtocol>;

template <typename ThriftStruct>
const auto ThriftToBinary = detail::ThriftToString<ThriftStruct, TBinaryProtocol>;

template <typename ThriftStruct>
const auto JsonToThrift = detail::StringToThrift<ThriftStruct, TJSONProtocol>;

// template <typename ThriftStruct>
// const auto DebugToThrift = detail::StringToThrift<ThriftStruct, TDebugProtocol>;

template <typename ThriftStruct>
const auto BinaryToThrift = detail::StringToThrift<ThriftStruct, TBinaryProtocol>;
