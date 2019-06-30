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

#include <thrift/lib/cpp2/gen/module_types_h.h>

namespace apache {
namespace thrift {
namespace tag {
struct var_i16;
struct var_i32;
struct var_bool;
struct var_byte;
struct var_i16;
struct var_i32;
struct var_i64;
struct var_double;
struct var_string;
struct var_binary;
struct var_string_type;
struct var_string_list;
struct var_binary_list;
struct var_string_set;
struct var_string_binary_map;
struct var_enum;
struct var_enum_set;
struct var_union;
struct var_required_i32;
struct var_optional_i32;
struct req;
struct msg;
}  // namespace tag
namespace detail {
#ifndef APACHE_THRIFT_ACCESSOR_var_i16
#define APACHE_THRIFT_ACCESSOR_var_i16
APACHE_THRIFT_DEFINE_ACCESSOR(var_i16);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_i32
#define APACHE_THRIFT_ACCESSOR_var_i32
APACHE_THRIFT_DEFINE_ACCESSOR(var_i32);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_bool
#define APACHE_THRIFT_ACCESSOR_var_bool
APACHE_THRIFT_DEFINE_ACCESSOR(var_bool);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_byte
#define APACHE_THRIFT_ACCESSOR_var_byte
APACHE_THRIFT_DEFINE_ACCESSOR(var_byte);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_i16
#define APACHE_THRIFT_ACCESSOR_var_i16
APACHE_THRIFT_DEFINE_ACCESSOR(var_i16);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_i32
#define APACHE_THRIFT_ACCESSOR_var_i32
APACHE_THRIFT_DEFINE_ACCESSOR(var_i32);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_i64
#define APACHE_THRIFT_ACCESSOR_var_i64
APACHE_THRIFT_DEFINE_ACCESSOR(var_i64);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_double
#define APACHE_THRIFT_ACCESSOR_var_double
APACHE_THRIFT_DEFINE_ACCESSOR(var_double);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_string
#define APACHE_THRIFT_ACCESSOR_var_string
APACHE_THRIFT_DEFINE_ACCESSOR(var_string);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_binary
#define APACHE_THRIFT_ACCESSOR_var_binary
APACHE_THRIFT_DEFINE_ACCESSOR(var_binary);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_string_type
#define APACHE_THRIFT_ACCESSOR_var_string_type
APACHE_THRIFT_DEFINE_ACCESSOR(var_string_type);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_string_list
#define APACHE_THRIFT_ACCESSOR_var_string_list
APACHE_THRIFT_DEFINE_ACCESSOR(var_string_list);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_binary_list
#define APACHE_THRIFT_ACCESSOR_var_binary_list
APACHE_THRIFT_DEFINE_ACCESSOR(var_binary_list);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_string_set
#define APACHE_THRIFT_ACCESSOR_var_string_set
APACHE_THRIFT_DEFINE_ACCESSOR(var_string_set);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_string_binary_map
#define APACHE_THRIFT_ACCESSOR_var_string_binary_map
APACHE_THRIFT_DEFINE_ACCESSOR(var_string_binary_map);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_enum
#define APACHE_THRIFT_ACCESSOR_var_enum
APACHE_THRIFT_DEFINE_ACCESSOR(var_enum);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_enum_set
#define APACHE_THRIFT_ACCESSOR_var_enum_set
APACHE_THRIFT_DEFINE_ACCESSOR(var_enum_set);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_union
#define APACHE_THRIFT_ACCESSOR_var_union
APACHE_THRIFT_DEFINE_ACCESSOR(var_union);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_required_i32
#define APACHE_THRIFT_ACCESSOR_var_required_i32
APACHE_THRIFT_DEFINE_ACCESSOR(var_required_i32);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_var_optional_i32
#define APACHE_THRIFT_ACCESSOR_var_optional_i32
APACHE_THRIFT_DEFINE_ACCESSOR(var_optional_i32);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_req
#define APACHE_THRIFT_ACCESSOR_req
APACHE_THRIFT_DEFINE_ACCESSOR(req);
#endif
#ifndef APACHE_THRIFT_ACCESSOR_msg
#define APACHE_THRIFT_ACCESSOR_msg
APACHE_THRIFT_DEFINE_ACCESSOR(msg);
#endif
}  // namespace detail
}  // namespace thrift
}  // namespace apache

// BEGIN declare_enums
namespace idl {
namespace thrift {
namespace cpp2 {

enum class EnumType {
  ZERO = 0,
  ONE = 1,
  TWO = 2,
  THREE = 3,
};

}
}  // namespace thrift
}  // namespace idl
namespace std {

template <>
struct hash<typename ::idl::thrift::cpp2::EnumType>
    : public apache::thrift::detail::enum_hash<typename ::idl::thrift::cpp2::EnumType> {};
template <>
struct equal_to<typename ::idl::thrift::cpp2::EnumType>
    : public apache::thrift::detail::enum_equal_to<typename ::idl::thrift::cpp2::EnumType> {};

}  // namespace std

namespace apache {
namespace thrift {

template <>
struct TEnumDataStorage<::idl::thrift::cpp2::EnumType>;

template <>
struct TEnumTraits<::idl::thrift::cpp2::EnumType> {
  using type = ::idl::thrift::cpp2::EnumType;

  static constexpr std::size_t const size = 4;
  static folly::Range<type const*> const values;
  static folly::Range<folly::StringPiece const*> const names;

  static char const* findName(type value);
  static bool findValue(char const* name, type* out);

  static constexpr type min() { return type::ZERO; }
  static constexpr type max() { return type::THREE; }
};

}  // namespace thrift
}  // namespace apache

namespace idl {
namespace thrift {
namespace cpp2 {

using _EnumType_EnumMapFactory = apache::thrift::detail::TEnumMapFactory<EnumType>;
[[deprecated(
    "use apache::thrift::util::enumNameSafe, apache::thrift::util::enumName, or "
    "apache::thrift::TEnumTraits")]] extern const _EnumType_EnumMapFactory::ValuesToNamesMapType
    _EnumType_VALUES_TO_NAMES;
[[deprecated(
    "use apache::thrift::TEnumTraits")]] extern const _EnumType_EnumMapFactory::NamesToValuesMapType
    _EnumType_NAMES_TO_VALUES;

}  // namespace cpp2
}  // namespace thrift
}  // namespace idl

// END declare_enums
// BEGIN forward_declare
namespace idl {
namespace thrift {
namespace cpp2 {
class UnionType;
class MockRequest;
class MockResponse;
class MockException;
}  // namespace cpp2
}  // namespace thrift
}  // namespace idl
// END forward_declare
// BEGIN typedefs
namespace idl {
namespace thrift {
namespace cpp2 {
typedef ::std::string StrType;

}
}  // namespace thrift
}  // namespace idl
// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace idl {
namespace thrift {
namespace cpp2 {
class UnionType final {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = UnionType;
  static constexpr bool __fbthrift_cpp2_is_union = true;

 public:
  enum Type : int {
    __EMPTY__ = 0,
    var_i16 = 1,
    var_i32 = 2,
  };

  UnionType() : type_(Type::__EMPTY__) {}

  UnionType(UnionType&& rhs) : type_(Type::__EMPTY__) {
    if (this == &rhs) {
      return;
    }
    if (rhs.type_ == Type::__EMPTY__) {
      return;
    }
    switch (rhs.type_) {
      case Type::var_i16: {
        set_var_i16(std::move(rhs.value_.var_i16));
        break;
      }
      case Type::var_i32: {
        set_var_i32(std::move(rhs.value_.var_i32));
        break;
      }
      default: {
        assert(false);
        break;
      }
    }
    rhs.__clear();
  }

  UnionType(const UnionType& rhs) : type_(Type::__EMPTY__) {
    if (this == &rhs) {
      return;
    }
    if (rhs.type_ == Type::__EMPTY__) {
      return;
    }
    switch (rhs.type_) {
      case Type::var_i16: {
        set_var_i16(rhs.value_.var_i16);
        break;
      }
      case Type::var_i32: {
        set_var_i32(rhs.value_.var_i32);
        break;
      }
      default: {
        assert(false);
        break;
      }
    }
  }

  UnionType& operator=(UnionType&& rhs) {
    if (this == &rhs) {
      return *this;
    }
    __clear();
    if (rhs.type_ == Type::__EMPTY__) {
      return *this;
    }
    switch (rhs.type_) {
      case Type::var_i16: {
        set_var_i16(std::move(rhs.value_.var_i16));
        break;
      }
      case Type::var_i32: {
        set_var_i32(std::move(rhs.value_.var_i32));
        break;
      }
      default: {
        assert(false);
        break;
      }
    }
    rhs.__clear();
    return *this;
  }

  UnionType& operator=(const UnionType& rhs) {
    if (this == &rhs) {
      return *this;
    }
    __clear();
    if (rhs.type_ == Type::__EMPTY__) {
      return *this;
    }
    switch (rhs.type_) {
      case Type::var_i16: {
        set_var_i16(rhs.value_.var_i16);
        break;
      }
      case Type::var_i32: {
        set_var_i32(rhs.value_.var_i32);
        break;
      }
      default: {
        assert(false);
        break;
      }
    }
    return *this;
  }
  void __clear();

  ~UnionType() { __clear(); }
  union storage_type {
    int16_t var_i16;
    int32_t var_i32;

    storage_type() {}
    ~storage_type() {}
  };
  bool operator==(const UnionType& rhs) const;
#ifndef SWIG
  friend bool operator!=(const UnionType& __x, const UnionType& __y) { return !(__x == __y); }
#endif
  bool operator<(const UnionType& rhs) const;
#ifndef SWIG
  friend bool operator>(const UnionType& __x, const UnionType& __y) { return __y < __x; }
  friend bool operator<=(const UnionType& __x, const UnionType& __y) { return !(__y < __x); }
  friend bool operator>=(const UnionType& __x, const UnionType& __y) { return !(__x < __y); }
#endif

  int16_t& set_var_i16(int16_t t = int16_t()) {
    __clear();
    type_ = Type::var_i16;
    ::new (std::addressof(value_.var_i16)) int16_t(t);
    return value_.var_i16;
  }

  int32_t& set_var_i32(int32_t t = int32_t()) {
    __clear();
    type_ = Type::var_i32;
    ::new (std::addressof(value_.var_i32)) int32_t(t);
    return value_.var_i32;
  }

  int16_t const& get_var_i16() const {
    assert(type_ == Type::var_i16);
    return value_.var_i16;
  }

  int32_t const& get_var_i32() const {
    assert(type_ == Type::var_i32);
    return value_.var_i32;
  }

  int16_t& mutable_var_i16() {
    assert(type_ == Type::var_i16);
    return value_.var_i16;
  }

  int32_t& mutable_var_i32() {
    assert(type_ == Type::var_i32);
    return value_.var_i32;
  }

  int16_t move_var_i16() {
    assert(type_ == Type::var_i16);
    return std::move(value_.var_i16);
  }

  int32_t move_var_i32() {
    assert(type_ == Type::var_i32);
    return std::move(value_.var_i32);
  }

  template <typename..., typename T = int16_t>
  FOLLY_ERASE ::apache::thrift::union_field_ref<const T&> var_i16_ref() const& {
    return {value_.var_i16, type_, var_i16, this,
            ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = int16_t>
  FOLLY_ERASE ::apache::thrift::union_field_ref<const T&&> var_i16_ref() const&& {
    return {std::move(value_.var_i16), type_, var_i16, this,
            ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = int16_t>
  FOLLY_ERASE ::apache::thrift::union_field_ref<T&> var_i16_ref() & {
    return {value_.var_i16, type_, var_i16, this,
            ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = int16_t>
  FOLLY_ERASE ::apache::thrift::union_field_ref<T&&> var_i16_ref() && {
    return {std::move(value_.var_i16), type_, var_i16, this,
            ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }
  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::union_field_ref<const T&> var_i32_ref() const& {
    return {value_.var_i32, type_, var_i32, this,
            ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::union_field_ref<const T&&> var_i32_ref() const&& {
    return {std::move(value_.var_i32), type_, var_i32, this,
            ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::union_field_ref<T&> var_i32_ref() & {
    return {value_.var_i32, type_, var_i32, this,
            ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::union_field_ref<T&&> var_i32_ref() && {
    return {std::move(value_.var_i32), type_, var_i32, this,
            ::apache::thrift::detail::union_field_ref_owner_vtable_for<decltype(*this)>};
  }
  Type getType() const { return static_cast<Type>(type_); }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 protected:
  template <class T>
  void destruct(T& val) {
    (&val)->~T();
  }

  storage_type value_;
  std::underlying_type_t<Type> type_;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<UnionType>;
  friend void swap(UnionType& a, UnionType& b);
};

template <class Protocol_>
uint32_t UnionType::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

}  // namespace cpp2
}  // namespace thrift
}  // namespace idl
namespace idl {
namespace thrift {
namespace cpp2 {
class MockRequest final {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = MockRequest;
  static constexpr bool __fbthrift_cpp2_is_union = false;

 public:
  MockRequest();
  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN

  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]] MockRequest(
      apache::thrift::FragileConstructor, bool var_bool__arg, int8_t var_byte__arg,
      int16_t var_i16__arg, int32_t var_i32__arg, int64_t var_i64__arg, double var_double__arg,
      ::std::string var_string__arg, ::std::string var_binary__arg,
      ::idl::thrift::cpp2::StrType var_string_type__arg,
      ::std::vector<::std::string> var_string_list__arg,
      ::std::vector<::std::string> var_binary_list__arg,
      ::std::set<::std::string> var_string_set__arg,
      ::std::map<::std::string, ::std::string> var_string_binary_map__arg,
      ::idl::thrift::cpp2::EnumType var_enum__arg,
      ::std::set<::idl::thrift::cpp2::EnumType> var_enum_set__arg,
      ::idl::thrift::cpp2::UnionType var_union__arg, int32_t var_required_i32__arg,
      int32_t var_optional_i32__arg);

  MockRequest(MockRequest&&) = default;

  MockRequest(const MockRequest&) = default;

  MockRequest& operator=(MockRequest&&) = default;

  MockRequest& operator=(const MockRequest&) = default;
  THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();

  ~MockRequest();

 private:
  bool var_bool;

 private:
  int8_t var_byte;

 private:
  int16_t var_i16;

 private:
  int32_t var_i32;

 private:
  int64_t var_i64;

 private:
  double var_double;

 private:
  ::std::string var_string;

 private:
  ::std::string var_binary;

 private:
  ::idl::thrift::cpp2::StrType var_string_type;

 private:
  ::std::vector<::std::string> var_string_list;

 private:
  ::std::vector<::std::string> var_binary_list;

 private:
  ::std::set<::std::string> var_string_set;

 private:
  ::std::map<::std::string, ::std::string> var_string_binary_map;

 private:
  ::idl::thrift::cpp2::EnumType var_enum;

 private:
  ::std::set<::idl::thrift::cpp2::EnumType> var_enum_set;

 private:
  ::idl::thrift::cpp2::UnionType var_union;

 public:
  int32_t var_required_i32;

 private:
  int32_t var_optional_i32;

 public:
  [[deprecated(
      "__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]] struct
      __isset {
    bool var_bool;
    bool var_byte;
    bool var_i16;
    bool var_i32;
    bool var_i64;
    bool var_double;
    bool var_string;
    bool var_binary;
    bool var_string_type;
    bool var_string_list;
    bool var_binary_list;
    bool var_string_set;
    bool var_string_binary_map;
    bool var_enum;
    bool var_enum_set;
    bool var_union;
    bool var_optional_i32;
  } __isset = {};
  bool operator==(const MockRequest& rhs) const;
#ifndef SWIG
  friend bool operator!=(const MockRequest& __x, const MockRequest& __y) { return !(__x == __y); }
#endif
  bool operator<(const MockRequest& rhs) const;
#ifndef SWIG
  friend bool operator>(const MockRequest& __x, const MockRequest& __y) { return __y < __x; }
  friend bool operator<=(const MockRequest& __x, const MockRequest& __y) { return !(__y < __x); }
  friend bool operator>=(const MockRequest& __x, const MockRequest& __y) { return !(__x < __y); }
#endif

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_bool_ref() const& {
    return {this->var_bool, __isset.var_bool};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_bool_ref() const&& {
    return {std::move(this->var_bool), __isset.var_bool};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_bool_ref() & {
    return {this->var_bool, __isset.var_bool};
  }

  template <typename..., typename T = bool>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_bool_ref() && {
    return {std::move(this->var_bool), __isset.var_bool};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = int8_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_byte_ref() const& {
    return {this->var_byte, __isset.var_byte};
  }

  template <typename..., typename T = int8_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_byte_ref() const&& {
    return {std::move(this->var_byte), __isset.var_byte};
  }

  template <typename..., typename T = int8_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_byte_ref() & {
    return {this->var_byte, __isset.var_byte};
  }

  template <typename..., typename T = int8_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_byte_ref() && {
    return {std::move(this->var_byte), __isset.var_byte};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_i16_ref() const& {
    return {this->var_i16, __isset.var_i16};
  }

  template <typename..., typename T = int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_i16_ref() const&& {
    return {std::move(this->var_i16), __isset.var_i16};
  }

  template <typename..., typename T = int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_i16_ref() & {
    return {this->var_i16, __isset.var_i16};
  }

  template <typename..., typename T = int16_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_i16_ref() && {
    return {std::move(this->var_i16), __isset.var_i16};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_i32_ref() const& {
    return {this->var_i32, __isset.var_i32};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_i32_ref() const&& {
    return {std::move(this->var_i32), __isset.var_i32};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_i32_ref() & {
    return {this->var_i32, __isset.var_i32};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_i32_ref() && {
    return {std::move(this->var_i32), __isset.var_i32};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_i64_ref() const& {
    return {this->var_i64, __isset.var_i64};
  }

  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_i64_ref() const&& {
    return {std::move(this->var_i64), __isset.var_i64};
  }

  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_i64_ref() & {
    return {this->var_i64, __isset.var_i64};
  }

  template <typename..., typename T = int64_t>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_i64_ref() && {
    return {std::move(this->var_i64), __isset.var_i64};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = double>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_double_ref() const& {
    return {this->var_double, __isset.var_double};
  }

  template <typename..., typename T = double>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_double_ref() const&& {
    return {std::move(this->var_double), __isset.var_double};
  }

  template <typename..., typename T = double>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_double_ref() & {
    return {this->var_double, __isset.var_double};
  }

  template <typename..., typename T = double>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_double_ref() && {
    return {std::move(this->var_double), __isset.var_double};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_string_ref() const& {
    return {this->var_string, __isset.var_string};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_string_ref() const&& {
    return {std::move(this->var_string), __isset.var_string};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_string_ref() & {
    return {this->var_string, __isset.var_string};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_string_ref() && {
    return {std::move(this->var_string), __isset.var_string};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_binary_ref() const& {
    return {this->var_binary, __isset.var_binary};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_binary_ref() const&& {
    return {std::move(this->var_binary), __isset.var_binary};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_binary_ref() & {
    return {this->var_binary, __isset.var_binary};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_binary_ref() && {
    return {std::move(this->var_binary), __isset.var_binary};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::idl::thrift::cpp2::StrType>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_string_type_ref() const& {
    return {this->var_string_type, __isset.var_string_type};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::StrType>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_string_type_ref() const&& {
    return {std::move(this->var_string_type), __isset.var_string_type};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::StrType>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_string_type_ref() & {
    return {this->var_string_type, __isset.var_string_type};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::StrType>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_string_type_ref() && {
    return {std::move(this->var_string_type), __isset.var_string_type};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::vector<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_string_list_ref() const& {
    return {this->var_string_list, __isset.var_string_list};
  }

  template <typename..., typename T = ::std::vector<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_string_list_ref() const&& {
    return {std::move(this->var_string_list), __isset.var_string_list};
  }

  template <typename..., typename T = ::std::vector<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_string_list_ref() & {
    return {this->var_string_list, __isset.var_string_list};
  }

  template <typename..., typename T = ::std::vector<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_string_list_ref() && {
    return {std::move(this->var_string_list), __isset.var_string_list};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::vector<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_binary_list_ref() const& {
    return {this->var_binary_list, __isset.var_binary_list};
  }

  template <typename..., typename T = ::std::vector<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_binary_list_ref() const&& {
    return {std::move(this->var_binary_list), __isset.var_binary_list};
  }

  template <typename..., typename T = ::std::vector<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_binary_list_ref() & {
    return {this->var_binary_list, __isset.var_binary_list};
  }

  template <typename..., typename T = ::std::vector<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_binary_list_ref() && {
    return {std::move(this->var_binary_list), __isset.var_binary_list};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::set<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_string_set_ref() const& {
    return {this->var_string_set, __isset.var_string_set};
  }

  template <typename..., typename T = ::std::set<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_string_set_ref() const&& {
    return {std::move(this->var_string_set), __isset.var_string_set};
  }

  template <typename..., typename T = ::std::set<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_string_set_ref() & {
    return {this->var_string_set, __isset.var_string_set};
  }

  template <typename..., typename T = ::std::set<::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_string_set_ref() && {
    return {std::move(this->var_string_set), __isset.var_string_set};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::map<::std::string, ::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_string_binary_map_ref() const& {
    return {this->var_string_binary_map, __isset.var_string_binary_map};
  }

  template <typename..., typename T = ::std::map<::std::string, ::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_string_binary_map_ref() const&& {
    return {std::move(this->var_string_binary_map), __isset.var_string_binary_map};
  }

  template <typename..., typename T = ::std::map<::std::string, ::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_string_binary_map_ref() & {
    return {this->var_string_binary_map, __isset.var_string_binary_map};
  }

  template <typename..., typename T = ::std::map<::std::string, ::std::string>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_string_binary_map_ref() && {
    return {std::move(this->var_string_binary_map), __isset.var_string_binary_map};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::idl::thrift::cpp2::EnumType>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_enum_ref() const& {
    return {this->var_enum, __isset.var_enum};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::EnumType>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_enum_ref() const&& {
    return {std::move(this->var_enum), __isset.var_enum};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::EnumType>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_enum_ref() & {
    return {this->var_enum, __isset.var_enum};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::EnumType>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_enum_ref() && {
    return {std::move(this->var_enum), __isset.var_enum};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::set<::idl::thrift::cpp2::EnumType>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_enum_set_ref() const& {
    return {this->var_enum_set, __isset.var_enum_set};
  }

  template <typename..., typename T = ::std::set<::idl::thrift::cpp2::EnumType>>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_enum_set_ref() const&& {
    return {std::move(this->var_enum_set), __isset.var_enum_set};
  }

  template <typename..., typename T = ::std::set<::idl::thrift::cpp2::EnumType>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_enum_set_ref() & {
    return {this->var_enum_set, __isset.var_enum_set};
  }

  template <typename..., typename T = ::std::set<::idl::thrift::cpp2::EnumType>>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_enum_set_ref() && {
    return {std::move(this->var_enum_set), __isset.var_enum_set};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::idl::thrift::cpp2::UnionType>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> var_union_ref() const& {
    return {this->var_union, __isset.var_union};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::UnionType>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> var_union_ref() const&& {
    return {std::move(this->var_union), __isset.var_union};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::UnionType>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> var_union_ref() & {
    return {this->var_union, __isset.var_union};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::UnionType>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> var_union_ref() && {
    return {std::move(this->var_union), __isset.var_union};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END
  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::required_field_ref<const T&> var_required_i32_ref() const& {
    return ::apache::thrift::required_field_ref<const T&>{this->var_required_i32};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::required_field_ref<const T&&> var_required_i32_ref() const&& {
    return ::apache::thrift::required_field_ref<const T&&>{std::move(this->var_required_i32)};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::required_field_ref<T&> var_required_i32_ref() & {
    return ::apache::thrift::required_field_ref<T&>{this->var_required_i32};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::required_field_ref<T&&> var_required_i32_ref() && {
    return ::apache::thrift::required_field_ref<T&&>{std::move(this->var_required_i32)};
  }

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<const T&> var_optional_i32_ref() const& {
    return {this->var_optional_i32, __isset.var_optional_i32};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<const T&&> var_optional_i32_ref() const&& {
    return {std::move(this->var_optional_i32), __isset.var_optional_i32};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<T&> var_optional_i32_ref() & {
    return {this->var_optional_i32, __isset.var_optional_i32};
  }

  template <typename..., typename T = int32_t>
  FOLLY_ERASE ::apache::thrift::optional_field_ref<T&&> var_optional_i32_ref() && {
    return {std::move(this->var_optional_i32), __isset.var_optional_i32};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  bool get_var_bool() const { return var_bool; }

  bool& set_var_bool(bool var_bool_) {
    var_bool = var_bool_;
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_bool = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_bool;
  }

  int8_t get_var_byte() const { return var_byte; }

  int8_t& set_var_byte(int8_t var_byte_) {
    var_byte = var_byte_;
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_byte = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_byte;
  }

  int16_t get_var_i16() const { return var_i16; }

  int16_t& set_var_i16(int16_t var_i16_) {
    var_i16 = var_i16_;
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_i16 = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_i16;
  }

  int32_t get_var_i32() const { return var_i32; }

  int32_t& set_var_i32(int32_t var_i32_) {
    var_i32 = var_i32_;
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_i32 = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_i32;
  }

  int64_t get_var_i64() const { return var_i64; }

  int64_t& set_var_i64(int64_t var_i64_) {
    var_i64 = var_i64_;
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_i64 = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_i64;
  }

  double get_var_double() const { return var_double; }

  double& set_var_double(double var_double_) {
    var_double = var_double_;
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_double = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_double;
  }

  const ::std::string& get_var_string() const& { return var_string; }

  ::std::string get_var_string() && { return std::move(var_string); }

  template <typename T_MockRequest_var_string_struct_setter = ::std::string>
  ::std::string& set_var_string(T_MockRequest_var_string_struct_setter&& var_string_) {
    var_string = std::forward<T_MockRequest_var_string_struct_setter>(var_string_);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_string = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_string;
  }

  const ::std::string& get_var_binary() const& { return var_binary; }

  ::std::string get_var_binary() && { return std::move(var_binary); }

  template <typename T_MockRequest_var_binary_struct_setter = ::std::string>
  ::std::string& set_var_binary(T_MockRequest_var_binary_struct_setter&& var_binary_) {
    var_binary = std::forward<T_MockRequest_var_binary_struct_setter>(var_binary_);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_binary = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_binary;
  }

  const ::idl::thrift::cpp2::StrType& get_var_string_type() const& { return var_string_type; }

  ::idl::thrift::cpp2::StrType get_var_string_type() && { return std::move(var_string_type); }

  template <typename T_MockRequest_var_string_type_struct_setter = ::idl::thrift::cpp2::StrType>
  ::idl::thrift::cpp2::StrType& set_var_string_type(
      T_MockRequest_var_string_type_struct_setter&& var_string_type_) {
    var_string_type = std::forward<T_MockRequest_var_string_type_struct_setter>(var_string_type_);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_string_type = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_string_type;
  }
  const ::std::vector<::std::string>& get_var_string_list() const&;
  ::std::vector<::std::string> get_var_string_list() &&;

  template <typename T_MockRequest_var_string_list_struct_setter = ::std::vector<::std::string>>
  ::std::vector<::std::string>& set_var_string_list(
      T_MockRequest_var_string_list_struct_setter&& var_string_list_) {
    var_string_list = std::forward<T_MockRequest_var_string_list_struct_setter>(var_string_list_);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_string_list = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_string_list;
  }
  const ::std::vector<::std::string>& get_var_binary_list() const&;
  ::std::vector<::std::string> get_var_binary_list() &&;

  template <typename T_MockRequest_var_binary_list_struct_setter = ::std::vector<::std::string>>
  ::std::vector<::std::string>& set_var_binary_list(
      T_MockRequest_var_binary_list_struct_setter&& var_binary_list_) {
    var_binary_list = std::forward<T_MockRequest_var_binary_list_struct_setter>(var_binary_list_);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_binary_list = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_binary_list;
  }
  const ::std::set<::std::string>& get_var_string_set() const&;
  ::std::set<::std::string> get_var_string_set() &&;

  template <typename T_MockRequest_var_string_set_struct_setter = ::std::set<::std::string>>
  ::std::set<::std::string>& set_var_string_set(
      T_MockRequest_var_string_set_struct_setter&& var_string_set_) {
    var_string_set = std::forward<T_MockRequest_var_string_set_struct_setter>(var_string_set_);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_string_set = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_string_set;
  }
  const ::std::map<::std::string, ::std::string>& get_var_string_binary_map() const&;
  ::std::map<::std::string, ::std::string> get_var_string_binary_map() &&;

  template <typename T_MockRequest_var_string_binary_map_struct_setter =
                ::std::map<::std::string, ::std::string>>
  ::std::map<::std::string, ::std::string>& set_var_string_binary_map(
      T_MockRequest_var_string_binary_map_struct_setter&& var_string_binary_map_) {
    var_string_binary_map =
        std::forward<T_MockRequest_var_string_binary_map_struct_setter>(var_string_binary_map_);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_string_binary_map = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_string_binary_map;
  }

  ::idl::thrift::cpp2::EnumType get_var_enum() const { return var_enum; }

  ::idl::thrift::cpp2::EnumType& set_var_enum(::idl::thrift::cpp2::EnumType var_enum_) {
    var_enum = var_enum_;
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_enum = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_enum;
  }
  const ::std::set<::idl::thrift::cpp2::EnumType>& get_var_enum_set() const&;
  ::std::set<::idl::thrift::cpp2::EnumType> get_var_enum_set() &&;

  template <
      typename T_MockRequest_var_enum_set_struct_setter = ::std::set<::idl::thrift::cpp2::EnumType>>
  ::std::set<::idl::thrift::cpp2::EnumType>& set_var_enum_set(
      T_MockRequest_var_enum_set_struct_setter&& var_enum_set_) {
    var_enum_set = std::forward<T_MockRequest_var_enum_set_struct_setter>(var_enum_set_);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_enum_set = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_enum_set;
  }
  const ::idl::thrift::cpp2::UnionType& get_var_union() const&;
  ::idl::thrift::cpp2::UnionType get_var_union() &&;

  template <typename T_MockRequest_var_union_struct_setter = ::idl::thrift::cpp2::UnionType>
  ::idl::thrift::cpp2::UnionType& set_var_union(
      T_MockRequest_var_union_struct_setter&& var_union_) {
    var_union = std::forward<T_MockRequest_var_union_struct_setter>(var_union_);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_union = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_union;
  }

  int32_t get_var_required_i32() const { return var_required_i32; }

  int32_t& set_var_required_i32(int32_t var_required_i32_) {
    var_required_i32 = var_required_i32_;
    return var_required_i32;
  }

  const int32_t* get_var_optional_i32() const& {
    return var_optional_i32_ref() ? std::addressof(var_optional_i32) : nullptr;
  }

  int32_t* get_var_optional_i32() & {
    return var_optional_i32_ref() ? std::addressof(var_optional_i32) : nullptr;
  }
  int32_t* get_var_optional_i32() && = delete;

  int32_t& set_var_optional_i32(int32_t var_optional_i32_) {
    var_optional_i32 = var_optional_i32_;
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.var_optional_i32 = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return var_optional_i32;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<MockRequest>;
  friend void swap(MockRequest& a, MockRequest& b);
};

template <class Protocol_>
uint32_t MockRequest::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

}  // namespace cpp2
}  // namespace thrift
}  // namespace idl
namespace idl {
namespace thrift {
namespace cpp2 {
class MockResponse final {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = MockResponse;
  static constexpr bool __fbthrift_cpp2_is_union = false;

 public:
  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  MockResponse() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]] MockResponse(
      apache::thrift::FragileConstructor, ::idl::thrift::cpp2::MockRequest req__arg);

  MockResponse(MockResponse&&) = default;

  MockResponse(const MockResponse&) = default;

  MockResponse& operator=(MockResponse&&) = default;

  MockResponse& operator=(const MockResponse&) = default;
  THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();

 private:
  ::idl::thrift::cpp2::MockRequest req;

 public:
  [[deprecated(
      "__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]] struct
      __isset {
    bool req;
  } __isset = {};
  bool operator==(const MockResponse& rhs) const;
#ifndef SWIG
  friend bool operator!=(const MockResponse& __x, const MockResponse& __y) { return !(__x == __y); }
#endif
  bool operator<(const MockResponse& rhs) const;
#ifndef SWIG
  friend bool operator>(const MockResponse& __x, const MockResponse& __y) { return __y < __x; }
  friend bool operator<=(const MockResponse& __x, const MockResponse& __y) { return !(__y < __x); }
  friend bool operator>=(const MockResponse& __x, const MockResponse& __y) { return !(__x < __y); }
#endif

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::idl::thrift::cpp2::MockRequest>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> req_ref() const& {
    return {this->req, __isset.req};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::MockRequest>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> req_ref() const&& {
    return {std::move(this->req), __isset.req};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::MockRequest>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> req_ref() & {
    return {this->req, __isset.req};
  }

  template <typename..., typename T = ::idl::thrift::cpp2::MockRequest>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> req_ref() && {
    return {std::move(this->req), __isset.req};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END
  const ::idl::thrift::cpp2::MockRequest& get_req() const&;
  ::idl::thrift::cpp2::MockRequest get_req() &&;

  template <typename T_MockResponse_req_struct_setter = ::idl::thrift::cpp2::MockRequest>
  ::idl::thrift::cpp2::MockRequest& set_req(T_MockResponse_req_struct_setter&& req_) {
    req = std::forward<T_MockResponse_req_struct_setter>(req_);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.req = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return req;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<MockResponse>;
  friend void swap(MockResponse& a, MockResponse& b);
};

template <class Protocol_>
uint32_t MockResponse::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

}  // namespace cpp2
}  // namespace thrift
}  // namespace idl
namespace idl {
namespace thrift {
namespace cpp2 {
class MockException final : public apache::thrift::TException {
 private:
  friend struct ::apache::thrift::detail::st::struct_private_access;

  //  used by a static_assert in the corresponding source
  static constexpr bool __fbthrift_cpp2_gen_json = false;
  static constexpr bool __fbthrift_cpp2_gen_nimble = false;
  static constexpr bool __fbthrift_cpp2_gen_has_thrift_uri = false;

 public:
  using __fbthrift_cpp2_type = MockException;
  static constexpr bool __fbthrift_cpp2_is_union = false;

 public:
  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  MockException() {}
  // FragileConstructor for use in initialization lists only.
  [[deprecated("This constructor is deprecated")]] MockException(apache::thrift::FragileConstructor,
                                                                 ::std::string msg__arg);

  MockException(MockException&&) = default;

  MockException(const MockException&) = default;

  MockException& operator=(MockException&&) = default;

  MockException& operator=(const MockException&) = default;
  THRIFT_IGNORE_ISSET_USE_WARNING_END
  void __clear();

 private:
  ::std::string msg;

 public:
  [[deprecated(
      "__isset field is deprecated in Thrift struct. Use _ref() accessors instead.")]] struct
      __isset {
    bool msg;
  } __isset = {};
  bool operator==(const MockException& rhs) const;
#ifndef SWIG
  friend bool operator!=(const MockException& __x, const MockException& __y) {
    return !(__x == __y);
  }
#endif
  bool operator<(const MockException& rhs) const;
#ifndef SWIG
  friend bool operator>(const MockException& __x, const MockException& __y) { return __y < __x; }
  friend bool operator<=(const MockException& __x, const MockException& __y) {
    return !(__y < __x);
  }
  friend bool operator>=(const MockException& __x, const MockException& __y) {
    return !(__x < __y);
  }
#endif

  THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&> msg_ref() const& {
    return {this->msg, __isset.msg};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<const T&&> msg_ref() const&& {
    return {std::move(this->msg), __isset.msg};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&> msg_ref() & {
    return {this->msg, __isset.msg};
  }

  template <typename..., typename T = ::std::string>
  FOLLY_ERASE ::apache::thrift::field_ref<T&&> msg_ref() && {
    return {std::move(this->msg), __isset.msg};
  }
  THRIFT_IGNORE_ISSET_USE_WARNING_END

  const ::std::string& get_msg() const& { return msg; }

  ::std::string get_msg() && { return std::move(msg); }

  template <typename T_MockException_msg_struct_setter = ::std::string>
  ::std::string& set_msg(T_MockException_msg_struct_setter&& msg_) {
    msg = std::forward<T_MockException_msg_struct_setter>(msg_);
    THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
    __isset.msg = true;
    THRIFT_IGNORE_ISSET_USE_WARNING_END
    return msg;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

  const char* what() const noexcept override { return "::idl::thrift::cpp2::MockException"; }

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops<MockException>;
  friend void swap(MockException& a, MockException& b);
};

template <class Protocol_>
uint32_t MockException::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCursorPosition();
  readNoXfer(iprot);
  return iprot->getCursorPosition() - _xferStart;
}

}  // namespace cpp2
}  // namespace thrift
}  // namespace idl

namespace apache {
namespace thrift {

template <>
struct TEnumDataStorage<::idl::thrift::cpp2::UnionType::Type>;

template <>
struct TEnumTraits<::idl::thrift::cpp2::UnionType::Type> {
  using type = ::idl::thrift::cpp2::UnionType::Type;

  static constexpr std::size_t const size = 2;
  static folly::Range<type const*> const values;
  static folly::Range<folly::StringPiece const*> const names;

  static char const* findName(type value);
  static bool findValue(char const* name, type* out);
};
}  // namespace thrift
}  // namespace apache
