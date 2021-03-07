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

#pragma once
#include <folly/SocketAddress.h>
#include <glog/logging.h>

#include <string>

enum ATYP { IPV4 = 1, IPV6 = 4, HOST = 3 };

static void parseHeader(const std::string& data, folly::SocketAddress& dest, int& header_length) {
  char atyp = data[0];
  int addrtype = static_cast<int>(atyp & 0b00001111);  // 0xf
  header_length = 0;
  if (addrtype == ATYP::HOST) {
    uint16_t port;
    if (data.length() > 2) {
      uint8_t addrlen = static_cast<uint8_t>(data[1]);
      if (data.size() >= static_cast<size_t>(2 + addrlen)) {
        port = folly::Endian::big<uint16_t>(
            *reinterpret_cast<const uint16_t*>(data.data() + 2 + addrlen));
        dest.setFromHostPort(data.substr(2, addrlen), port);
        header_length = 4 + addrlen;
      }
    }
  } else if (addrtype == ATYP::IPV4) {
    if (data.length() >= 7) {
      auto addr = folly::IPAddress::fromLong(*reinterpret_cast<const uint32_t*>(data.data() + 1));
      if (!addr.empty()) {
        header_length = 7;
        uint16_t port =
            folly::Endian::big<uint16_t>(*reinterpret_cast<const uint16_t*>(data.data() + 5));
        dest.setFromIpAddrPort(addr, port);
      }
    }
  } else if (addrtype == ATYP::IPV6) {
    if (data.length() >= 19) {
      folly::ByteRange br((unsigned char*)data.data() + 1, (unsigned char*)data.data() + 1 + 16);
      // Q_IPV6ADDR ipv6_addr;
      // memcpy(ipv6_addr.c, data.data() + 1, 16);
      // QHostAddress addr(ipv6_addr);
      auto addr = folly::IPAddress::fromBinary(br);
      if (!addr.empty()) {
        uint16_t port =
            folly::Endian::big<uint16_t>(*reinterpret_cast<const uint16_t*>(data.data() + 17));
        header_length = 19;
        dest.setFromIpAddrPort(addr, port);
        // dest.setIPAddress(addr);
        // dest.setPort(qFromBigEndian(*reinterpret_cast<const uint16_t*>(data.data() +
        // 17)));
      }
    }
  } else {
    LOG(ERROR) << "[parseHeader] unsuport type";
  }
}

template <typename T>
static void debugchar(const T* msg, size_t len) {
  for (size_t i = 0; i < len; ++i) printf("%02hhx", msg[i]);
  std::cout << std::endl;
}
