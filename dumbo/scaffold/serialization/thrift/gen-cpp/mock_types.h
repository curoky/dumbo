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

#ifndef mock_TYPES_H
#define mock_TYPES_H

#include <stdint.h>  // for int32_t, uint32_t, int16_t, int64_t, int8_t
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>   // for TBase
#include <thrift/Thrift.h>  // for TException
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <iosfwd>  // for ostream
#include <map>     // for map, operator==
#include <memory>
#include <set>     // for operator==, set
#include <string>  // for string, operator==, basic_string
#include <vector>  // for operator==, vector

namespace apache::thrift::protocol {
class TProtocol;
}  // namespace apache::thrift::protocol

namespace idl {
namespace thrift {

struct EnumType {
  enum type { ZERO = 0, ONE = 1, TWO = 2, THREE = 3 };
};

extern const std::map<int, const char*> _EnumType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const EnumType::type& val);

std::string to_string(const EnumType::type& val);

typedef std::string StrType;

class MockException;
class MockRequest;
class MockResponse;
class UnionType;

typedef struct _UnionType__isset {
  _UnionType__isset() : var_i16(false), var_i32(false) {}
  bool var_i16 : 1;
  bool var_i32 : 1;
} _UnionType__isset;

class UnionType : public virtual ::apache::thrift::TBase {
 public:
  UnionType(const UnionType&);
  UnionType& operator=(const UnionType&);
  UnionType() : var_i16(0), var_i32(0) {}

  virtual ~UnionType() noexcept;
  int16_t var_i16;
  int32_t var_i32;

  _UnionType__isset __isset;

  void __set_var_i16(const int16_t val);

  void __set_var_i32(const int32_t val);

  bool operator==(const UnionType& rhs) const {
    if (__isset.var_i16 != rhs.__isset.var_i16)
      return false;
    else if (__isset.var_i16 && !(var_i16 == rhs.var_i16))
      return false;
    if (__isset.var_i32 != rhs.__isset.var_i32)
      return false;
    else if (__isset.var_i32 && !(var_i32 == rhs.var_i32))
      return false;
    return true;
  }
  bool operator!=(const UnionType& rhs) const { return !(*this == rhs); }

  bool operator<(const UnionType&) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(UnionType& a, UnionType& b);

std::ostream& operator<<(std::ostream& out, const UnionType& obj);

typedef struct _MockRequest__isset {
  _MockRequest__isset()
      : var_bool(false),
        var_byte(false),
        var_i16(false),
        var_i32(false),
        var_i64(false),
        var_double(false),
        var_string(false),
        var_binary(false),
        var_string_type(false),
        var_string_list(false),
        var_binary_list(false),
        var_string_set(false),
        var_string_binary_map(false),
        var_enum(false),
        var_enum_set(false),
        var_union(false),
        var_optional_i32(false) {}
  bool var_bool : 1;
  bool var_byte : 1;
  bool var_i16 : 1;
  bool var_i32 : 1;
  bool var_i64 : 1;
  bool var_double : 1;
  bool var_string : 1;
  bool var_binary : 1;
  bool var_string_type : 1;
  bool var_string_list : 1;
  bool var_binary_list : 1;
  bool var_string_set : 1;
  bool var_string_binary_map : 1;
  bool var_enum : 1;
  bool var_enum_set : 1;
  bool var_union : 1;
  bool var_optional_i32 : 1;
} _MockRequest__isset;

class MockRequest : public virtual ::apache::thrift::TBase {
 public:
  MockRequest(const MockRequest&);
  MockRequest& operator=(const MockRequest&);
  MockRequest()
      : var_bool(0),
        var_byte(0),
        var_i16(0),
        var_i32(0),
        var_i64(0),
        var_double(0),
        var_string(),
        var_binary(),
        var_string_type(),
        var_enum((EnumType::type)0),
        var_required_i32(0),
        var_optional_i32(0) {}

  virtual ~MockRequest() noexcept;
  bool var_bool;
  int8_t var_byte;
  int16_t var_i16;
  int32_t var_i32;
  int64_t var_i64;
  double var_double;
  std::string var_string;
  std::string var_binary;
  StrType var_string_type;
  std::vector<std::string> var_string_list;
  std::vector<std::string> var_binary_list;
  std::set<std::string> var_string_set;
  std::map<std::string, std::string> var_string_binary_map;
  EnumType::type var_enum;
  std::set<EnumType::type> var_enum_set;
  UnionType var_union;
  int32_t var_required_i32;
  int32_t var_optional_i32;

  _MockRequest__isset __isset;

  void __set_var_bool(const bool val);

  void __set_var_byte(const int8_t val);

  void __set_var_i16(const int16_t val);

  void __set_var_i32(const int32_t val);

  void __set_var_i64(const int64_t val);

  void __set_var_double(const double val);

  void __set_var_string(const std::string& val);

  void __set_var_binary(const std::string& val);

  void __set_var_string_type(const StrType& val);

  void __set_var_string_list(const std::vector<std::string>& val);

  void __set_var_binary_list(const std::vector<std::string>& val);

  void __set_var_string_set(const std::set<std::string>& val);

  void __set_var_string_binary_map(const std::map<std::string, std::string>& val);

  void __set_var_enum(const EnumType::type val);

  void __set_var_enum_set(const std::set<EnumType::type>& val);

  void __set_var_union(const UnionType& val);

  void __set_var_required_i32(const int32_t val);

  void __set_var_optional_i32(const int32_t val);

  bool operator==(const MockRequest& rhs) const {
    if (!(var_bool == rhs.var_bool)) return false;
    if (!(var_byte == rhs.var_byte)) return false;
    if (!(var_i16 == rhs.var_i16)) return false;
    if (!(var_i32 == rhs.var_i32)) return false;
    if (!(var_i64 == rhs.var_i64)) return false;
    if (!(var_double == rhs.var_double)) return false;
    if (!(var_string == rhs.var_string)) return false;
    if (!(var_binary == rhs.var_binary)) return false;
    if (!(var_string_type == rhs.var_string_type)) return false;
    if (!(var_string_list == rhs.var_string_list)) return false;
    if (!(var_binary_list == rhs.var_binary_list)) return false;
    if (!(var_string_set == rhs.var_string_set)) return false;
    if (!(var_string_binary_map == rhs.var_string_binary_map)) return false;
    if (!(var_enum == rhs.var_enum)) return false;
    if (!(var_enum_set == rhs.var_enum_set)) return false;
    if (!(var_union == rhs.var_union)) return false;
    if (!(var_required_i32 == rhs.var_required_i32)) return false;
    if (__isset.var_optional_i32 != rhs.__isset.var_optional_i32)
      return false;
    else if (__isset.var_optional_i32 && !(var_optional_i32 == rhs.var_optional_i32))
      return false;
    return true;
  }
  bool operator!=(const MockRequest& rhs) const { return !(*this == rhs); }

  bool operator<(const MockRequest&) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(MockRequest& a, MockRequest& b);

std::ostream& operator<<(std::ostream& out, const MockRequest& obj);

typedef struct _MockResponse__isset {
  _MockResponse__isset() : req(false) {}
  bool req : 1;
} _MockResponse__isset;

class MockResponse : public virtual ::apache::thrift::TBase {
 public:
  MockResponse(const MockResponse&);
  MockResponse& operator=(const MockResponse&);
  MockResponse() {}

  virtual ~MockResponse() noexcept;
  MockRequest req;

  _MockResponse__isset __isset;

  void __set_req(const MockRequest& val);

  bool operator==(const MockResponse& rhs) const {
    if (!(req == rhs.req)) return false;
    return true;
  }
  bool operator!=(const MockResponse& rhs) const { return !(*this == rhs); }

  bool operator<(const MockResponse&) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(MockResponse& a, MockResponse& b);

std::ostream& operator<<(std::ostream& out, const MockResponse& obj);

typedef struct _MockException__isset {
  _MockException__isset() : msg(false) {}
  bool msg : 1;
} _MockException__isset;

class MockException : public ::apache::thrift::TException {
 public:
  MockException(const MockException&);
  MockException& operator=(const MockException&);
  MockException() : msg() {}

  virtual ~MockException() noexcept;
  std::string msg;

  _MockException__isset __isset;

  void __set_msg(const std::string& val);

  bool operator==(const MockException& rhs) const {
    if (!(msg == rhs.msg)) return false;
    return true;
  }
  bool operator!=(const MockException& rhs) const { return !(*this == rhs); }

  bool operator<(const MockException&) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
  mutable std::string thriftTExceptionMessageHolder_;
  const char* what() const noexcept;
};

void swap(MockException& a, MockException& b);

std::ostream& operator<<(std::ostream& out, const MockException& obj);

}  // namespace thrift
}  // namespace idl

#endif
