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

#include "mock_types.h"

#include <bits/exception.h>             // for exception
#include <stddef.h>                     // for NULL
#include <thrift/TToString.h>           // for to_string
#include <thrift/protocol/TProtocol.h>  // for TProtocol, T_STRING, T_I32, TType, TInputRecursionTracker, TOutputRecursionTracker, T_I16, T_LIST
#include <thrift/protocol/TProtocolException.h>  // for TProtocolException, TProtocolException::INVALID_DATA

#include <ostream>  // for operator<<, basic_ostream, char_traits, basic_ostream::operator<<
#include <utility>  // for swap

namespace idl {
namespace thrift {

int _kEnumTypeValues[] = {EnumType::ZERO, EnumType::ONE, EnumType::TWO, EnumType::THREE};
const char* _kEnumTypeNames[] = {"ZERO", "ONE", "TWO", "THREE"};
const std::map<int, const char*> _EnumType_VALUES_TO_NAMES(
    ::apache::thrift::TEnumIterator(4, _kEnumTypeValues, _kEnumTypeNames),
    ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const EnumType::type& val) {
  std::map<int, const char*>::const_iterator it = _EnumType_VALUES_TO_NAMES.find(val);
  if (it != _EnumType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const EnumType::type& val) {
  std::map<int, const char*>::const_iterator it = _EnumType_VALUES_TO_NAMES.find(val);
  if (it != _EnumType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

UnionType::~UnionType() noexcept {}

void UnionType::__set_var_i16(const int16_t val) {
  this->var_i16 = val;
  __isset.var_i16 = true;
}

void UnionType::__set_var_i32(const int32_t val) {
  this->var_i32 = val;
  __isset.var_i32 = true;
}
std::ostream& operator<<(std::ostream& out, const UnionType& obj) {
  obj.printTo(out);
  return out;
}

uint32_t UnionType::read(::apache::thrift::protocol::TProtocol* iprot) {
  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid) {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->var_i16);
          this->__isset.var_i16 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->var_i32);
          this->__isset.var_i32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t UnionType::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("UnionType");

  if (this->__isset.var_i16) {
    xfer += oprot->writeFieldBegin("var_i16", ::apache::thrift::protocol::T_I16, 1);
    xfer += oprot->writeI16(this->var_i16);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.var_i32) {
    xfer += oprot->writeFieldBegin("var_i32", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->var_i32);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(UnionType& a, UnionType& b) {
  using ::std::swap;
  swap(a.var_i16, b.var_i16);
  swap(a.var_i32, b.var_i32);
  swap(a.__isset, b.__isset);
}

UnionType::UnionType(const UnionType& other0) {
  var_i16 = other0.var_i16;
  var_i32 = other0.var_i32;
  __isset = other0.__isset;
}
UnionType& UnionType::operator=(const UnionType& other1) {
  var_i16 = other1.var_i16;
  var_i32 = other1.var_i32;
  __isset = other1.__isset;
  return *this;
}
void UnionType::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "UnionType(";
  out << "var_i16=";
  (__isset.var_i16 ? (out << to_string(var_i16)) : (out << "<null>"));
  out << ", "
      << "var_i32=";
  (__isset.var_i32 ? (out << to_string(var_i32)) : (out << "<null>"));
  out << ")";
}

MockRequest::~MockRequest() noexcept {}

void MockRequest::__set_var_bool(const bool val) { this->var_bool = val; }

void MockRequest::__set_var_byte(const int8_t val) { this->var_byte = val; }

void MockRequest::__set_var_i16(const int16_t val) { this->var_i16 = val; }

void MockRequest::__set_var_i32(const int32_t val) { this->var_i32 = val; }

void MockRequest::__set_var_i64(const int64_t val) { this->var_i64 = val; }

void MockRequest::__set_var_double(const double val) { this->var_double = val; }

void MockRequest::__set_var_string(const std::string& val) { this->var_string = val; }

void MockRequest::__set_var_binary(const std::string& val) { this->var_binary = val; }

void MockRequest::__set_var_string_type(const StrType& val) { this->var_string_type = val; }

void MockRequest::__set_var_string_list(const std::vector<std::string>& val) {
  this->var_string_list = val;
}

void MockRequest::__set_var_binary_list(const std::vector<std::string>& val) {
  this->var_binary_list = val;
}

void MockRequest::__set_var_string_set(const std::set<std::string>& val) {
  this->var_string_set = val;
}

void MockRequest::__set_var_string_binary_map(const std::map<std::string, std::string>& val) {
  this->var_string_binary_map = val;
}

void MockRequest::__set_var_enum(const EnumType::type val) { this->var_enum = val; }

void MockRequest::__set_var_enum_set(const std::set<EnumType::type>& val) {
  this->var_enum_set = val;
}

void MockRequest::__set_var_union(const UnionType& val) { this->var_union = val; }

void MockRequest::__set_var_required_i32(const int32_t val) { this->var_required_i32 = val; }

void MockRequest::__set_var_optional_i32(const int32_t val) {
  this->var_optional_i32 = val;
  __isset.var_optional_i32 = true;
}
std::ostream& operator<<(std::ostream& out, const MockRequest& obj) {
  obj.printTo(out);
  return out;
}

uint32_t MockRequest::read(::apache::thrift::protocol::TProtocol* iprot) {
  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_var_required_i32 = false;

  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid) {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->var_bool);
          this->__isset.var_bool = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->var_byte);
          this->__isset.var_byte = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->var_i16);
          this->__isset.var_i16 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->var_i32);
          this->__isset.var_i32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->var_i64);
          this->__isset.var_i64 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->var_double);
          this->__isset.var_double = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->var_string);
          this->__isset.var_string = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->var_binary);
          this->__isset.var_binary = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->var_string_type);
          this->__isset.var_string_type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->var_string_list.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _etype5;
            xfer += iprot->readListBegin(_etype5, _size2);
            this->var_string_list.resize(_size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6) {
              xfer += iprot->readString(this->var_string_list[_i6]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.var_string_list = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->var_binary_list.clear();
            uint32_t _size7;
            ::apache::thrift::protocol::TType _etype10;
            xfer += iprot->readListBegin(_etype10, _size7);
            this->var_binary_list.resize(_size7);
            uint32_t _i11;
            for (_i11 = 0; _i11 < _size7; ++_i11) {
              xfer += iprot->readBinary(this->var_binary_list[_i11]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.var_binary_list = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_SET) {
          {
            this->var_string_set.clear();
            uint32_t _size12;
            ::apache::thrift::protocol::TType _etype15;
            xfer += iprot->readSetBegin(_etype15, _size12);
            uint32_t _i16;
            for (_i16 = 0; _i16 < _size12; ++_i16) {
              std::string _elem17;
              xfer += iprot->readString(_elem17);
              this->var_string_set.insert(_elem17);
            }
            xfer += iprot->readSetEnd();
          }
          this->__isset.var_string_set = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->var_string_binary_map.clear();
            uint32_t _size18;
            ::apache::thrift::protocol::TType _ktype19;
            ::apache::thrift::protocol::TType _vtype20;
            xfer += iprot->readMapBegin(_ktype19, _vtype20, _size18);
            uint32_t _i22;
            for (_i22 = 0; _i22 < _size18; ++_i22) {
              std::string _key23;
              xfer += iprot->readString(_key23);
              std::string& _val24 = this->var_string_binary_map[_key23];
              xfer += iprot->readBinary(_val24);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.var_string_binary_map = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 14:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast25;
          xfer += iprot->readI32(ecast25);
          this->var_enum = (EnumType::type)ecast25;
          this->__isset.var_enum = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 15:
        if (ftype == ::apache::thrift::protocol::T_SET) {
          {
            this->var_enum_set.clear();
            uint32_t _size26;
            ::apache::thrift::protocol::TType _etype29;
            xfer += iprot->readSetBegin(_etype29, _size26);
            uint32_t _i30;
            for (_i30 = 0; _i30 < _size26; ++_i30) {
              EnumType::type _elem31;
              int32_t ecast32;
              xfer += iprot->readI32(ecast32);
              _elem31 = (EnumType::type)ecast32;
              this->var_enum_set.insert(_elem31);
            }
            xfer += iprot->readSetEnd();
          }
          this->__isset.var_enum_set = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 16:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->var_union.read(iprot);
          this->__isset.var_union = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 17:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->var_required_i32);
          isset_var_required_i32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 18:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->var_optional_i32);
          this->__isset.var_optional_i32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_var_required_i32) throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t MockRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MockRequest");

  xfer += oprot->writeFieldBegin("var_bool", ::apache::thrift::protocol::T_BOOL, 1);
  xfer += oprot->writeBool(this->var_bool);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_byte", ::apache::thrift::protocol::T_BYTE, 2);
  xfer += oprot->writeByte(this->var_byte);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_i16", ::apache::thrift::protocol::T_I16, 3);
  xfer += oprot->writeI16(this->var_i16);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_i32", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->var_i32);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_i64", ::apache::thrift::protocol::T_I64, 5);
  xfer += oprot->writeI64(this->var_i64);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_double", ::apache::thrift::protocol::T_DOUBLE, 6);
  xfer += oprot->writeDouble(this->var_double);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_string", ::apache::thrift::protocol::T_STRING, 7);
  xfer += oprot->writeString(this->var_string);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_binary", ::apache::thrift::protocol::T_STRING, 8);
  xfer += oprot->writeBinary(this->var_binary);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_string_type", ::apache::thrift::protocol::T_STRING, 9);
  xfer += oprot->writeString(this->var_string_type);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_string_list", ::apache::thrift::protocol::T_LIST, 10);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING,
                                  static_cast<uint32_t>(this->var_string_list.size()));
    std::vector<std::string>::const_iterator _iter33;
    for (_iter33 = this->var_string_list.begin(); _iter33 != this->var_string_list.end();
         ++_iter33) {
      xfer += oprot->writeString((*_iter33));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_binary_list", ::apache::thrift::protocol::T_LIST, 11);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING,
                                  static_cast<uint32_t>(this->var_binary_list.size()));
    std::vector<std::string>::const_iterator _iter34;
    for (_iter34 = this->var_binary_list.begin(); _iter34 != this->var_binary_list.end();
         ++_iter34) {
      xfer += oprot->writeBinary((*_iter34));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_string_set", ::apache::thrift::protocol::T_SET, 12);
  {
    xfer += oprot->writeSetBegin(::apache::thrift::protocol::T_STRING,
                                 static_cast<uint32_t>(this->var_string_set.size()));
    std::set<std::string>::const_iterator _iter35;
    for (_iter35 = this->var_string_set.begin(); _iter35 != this->var_string_set.end(); ++_iter35) {
      xfer += oprot->writeString((*_iter35));
    }
    xfer += oprot->writeSetEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_string_binary_map", ::apache::thrift::protocol::T_MAP, 13);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING,
                                 ::apache::thrift::protocol::T_STRING,
                                 static_cast<uint32_t>(this->var_string_binary_map.size()));
    std::map<std::string, std::string>::const_iterator _iter36;
    for (_iter36 = this->var_string_binary_map.begin();
         _iter36 != this->var_string_binary_map.end(); ++_iter36) {
      xfer += oprot->writeString(_iter36->first);
      xfer += oprot->writeBinary(_iter36->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_enum", ::apache::thrift::protocol::T_I32, 14);
  xfer += oprot->writeI32((int32_t)this->var_enum);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_enum_set", ::apache::thrift::protocol::T_SET, 15);
  {
    xfer += oprot->writeSetBegin(::apache::thrift::protocol::T_I32,
                                 static_cast<uint32_t>(this->var_enum_set.size()));
    std::set<EnumType::type>::const_iterator _iter37;
    for (_iter37 = this->var_enum_set.begin(); _iter37 != this->var_enum_set.end(); ++_iter37) {
      xfer += oprot->writeI32((int32_t)(*_iter37));
    }
    xfer += oprot->writeSetEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_union", ::apache::thrift::protocol::T_STRUCT, 16);
  xfer += this->var_union.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("var_required_i32", ::apache::thrift::protocol::T_I32, 17);
  xfer += oprot->writeI32(this->var_required_i32);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.var_optional_i32) {
    xfer += oprot->writeFieldBegin("var_optional_i32", ::apache::thrift::protocol::T_I32, 18);
    xfer += oprot->writeI32(this->var_optional_i32);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MockRequest& a, MockRequest& b) {
  using ::std::swap;
  swap(a.var_bool, b.var_bool);
  swap(a.var_byte, b.var_byte);
  swap(a.var_i16, b.var_i16);
  swap(a.var_i32, b.var_i32);
  swap(a.var_i64, b.var_i64);
  swap(a.var_double, b.var_double);
  swap(a.var_string, b.var_string);
  swap(a.var_binary, b.var_binary);
  swap(a.var_string_type, b.var_string_type);
  swap(a.var_string_list, b.var_string_list);
  swap(a.var_binary_list, b.var_binary_list);
  swap(a.var_string_set, b.var_string_set);
  swap(a.var_string_binary_map, b.var_string_binary_map);
  swap(a.var_enum, b.var_enum);
  swap(a.var_enum_set, b.var_enum_set);
  swap(a.var_union, b.var_union);
  swap(a.var_required_i32, b.var_required_i32);
  swap(a.var_optional_i32, b.var_optional_i32);
  swap(a.__isset, b.__isset);
}

MockRequest::MockRequest(const MockRequest& other38) {
  var_bool = other38.var_bool;
  var_byte = other38.var_byte;
  var_i16 = other38.var_i16;
  var_i32 = other38.var_i32;
  var_i64 = other38.var_i64;
  var_double = other38.var_double;
  var_string = other38.var_string;
  var_binary = other38.var_binary;
  var_string_type = other38.var_string_type;
  var_string_list = other38.var_string_list;
  var_binary_list = other38.var_binary_list;
  var_string_set = other38.var_string_set;
  var_string_binary_map = other38.var_string_binary_map;
  var_enum = other38.var_enum;
  var_enum_set = other38.var_enum_set;
  var_union = other38.var_union;
  var_required_i32 = other38.var_required_i32;
  var_optional_i32 = other38.var_optional_i32;
  __isset = other38.__isset;
}
MockRequest& MockRequest::operator=(const MockRequest& other39) {
  var_bool = other39.var_bool;
  var_byte = other39.var_byte;
  var_i16 = other39.var_i16;
  var_i32 = other39.var_i32;
  var_i64 = other39.var_i64;
  var_double = other39.var_double;
  var_string = other39.var_string;
  var_binary = other39.var_binary;
  var_string_type = other39.var_string_type;
  var_string_list = other39.var_string_list;
  var_binary_list = other39.var_binary_list;
  var_string_set = other39.var_string_set;
  var_string_binary_map = other39.var_string_binary_map;
  var_enum = other39.var_enum;
  var_enum_set = other39.var_enum_set;
  var_union = other39.var_union;
  var_required_i32 = other39.var_required_i32;
  var_optional_i32 = other39.var_optional_i32;
  __isset = other39.__isset;
  return *this;
}
void MockRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MockRequest(";
  out << "var_bool=" << to_string(var_bool);
  out << ", "
      << "var_byte=" << to_string(var_byte);
  out << ", "
      << "var_i16=" << to_string(var_i16);
  out << ", "
      << "var_i32=" << to_string(var_i32);
  out << ", "
      << "var_i64=" << to_string(var_i64);
  out << ", "
      << "var_double=" << to_string(var_double);
  out << ", "
      << "var_string=" << to_string(var_string);
  out << ", "
      << "var_binary=" << to_string(var_binary);
  out << ", "
      << "var_string_type=" << to_string(var_string_type);
  out << ", "
      << "var_string_list=" << to_string(var_string_list);
  out << ", "
      << "var_binary_list=" << to_string(var_binary_list);
  out << ", "
      << "var_string_set=" << to_string(var_string_set);
  out << ", "
      << "var_string_binary_map=" << to_string(var_string_binary_map);
  out << ", "
      << "var_enum=" << to_string(var_enum);
  out << ", "
      << "var_enum_set=" << to_string(var_enum_set);
  out << ", "
      << "var_union=" << to_string(var_union);
  out << ", "
      << "var_required_i32=" << to_string(var_required_i32);
  out << ", "
      << "var_optional_i32=";
  (__isset.var_optional_i32 ? (out << to_string(var_optional_i32)) : (out << "<null>"));
  out << ")";
}

MockResponse::~MockResponse() noexcept {}

void MockResponse::__set_req(const MockRequest& val) { this->req = val; }
std::ostream& operator<<(std::ostream& out, const MockResponse& obj) {
  obj.printTo(out);
  return out;
}

uint32_t MockResponse::read(::apache::thrift::protocol::TProtocol* iprot) {
  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid) {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->req.read(iprot);
          this->__isset.req = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MockResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MockResponse");

  xfer += oprot->writeFieldBegin("req", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->req.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MockResponse& a, MockResponse& b) {
  using ::std::swap;
  swap(a.req, b.req);
  swap(a.__isset, b.__isset);
}

MockResponse::MockResponse(const MockResponse& other40) {
  req = other40.req;
  __isset = other40.__isset;
}
MockResponse& MockResponse::operator=(const MockResponse& other41) {
  req = other41.req;
  __isset = other41.__isset;
  return *this;
}
void MockResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MockResponse(";
  out << "req=" << to_string(req);
  out << ")";
}

MockException::~MockException() noexcept {}

void MockException::__set_msg(const std::string& val) { this->msg = val; }
std::ostream& operator<<(std::ostream& out, const MockException& obj) {
  obj.printTo(out);
  return out;
}

uint32_t MockException::read(::apache::thrift::protocol::TProtocol* iprot) {
  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid) {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msg);
          this->__isset.msg = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MockException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MockException");

  xfer += oprot->writeFieldBegin("msg", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->msg);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MockException& a, MockException& b) {
  using ::std::swap;
  swap(a.msg, b.msg);
  swap(a.__isset, b.__isset);
}

MockException::MockException(const MockException& other42) : TException() {
  msg = other42.msg;
  __isset = other42.__isset;
}
MockException& MockException::operator=(const MockException& other43) {
  msg = other43.msg;
  __isset = other43.__isset;
  return *this;
}
void MockException::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MockException(";
  out << "msg=" << to_string(msg);
  out << ")";
}

const char* MockException::what() const noexcept {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: MockException";
  }
}

}  // namespace thrift
}  // namespace idl
