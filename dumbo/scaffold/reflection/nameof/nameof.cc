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

#include <bits/exception.h>  // for exception
#include <nameof.hpp>  // for cstring, operator<<, NAMEOF, nameof_type, nameof_enum, NAMEOF_TYPE, NAMEOF_TYPE_EXPR, nameof_enum_flag, nameof_full_type

#include <iostream>  // for endl, cout, basic_ostream, ostream, basic_ostream::put, operator<<, basic_ostream::operator<<, basic_ostream<>::__ostrea...
#include <stdexcept>  // for invalid_argument
#include <string>     // for operator<<, char_traits, operator+, string
#include <string_view>  // for operator<<, operator""sv, basic_string_view, string_view, string_view_literals
#include <utility>  // for declval

struct Base {
  virtual ~Base() = default;
};

struct Derived : Base {};

struct SomeStruct {
  int somefield = 0;

  void SomeMethod1(int i) { somefield = i; }

  int SomeMethod2() const { return somefield; }
};

void SomeMethod3() { std::cout << NAMEOF(SomeMethod3) << " no called!" << std::endl; }

template <typename T, typename U>
std::string SomeMethod4(U value) {
  auto function_name = NAMEOF(SomeMethod4<T, U>)
                           .str()
                           .append("<")
                           .append(NAMEOF_TYPE(T))
                           .append(", ")
                           .append(NAMEOF_TYPE(U))
                           .append(">(")
                           .append(NAMEOF_TYPE(U))
                           .append(" ")
                           .append(NAMEOF(value).data())
                           .append(")");

  return function_name;
}

template <typename T>
class SomeClass {
 public:
  void SomeMethod5() const { std::cout << nameof::nameof_type<T>() << std::endl; }

  template <typename C>
  C SomeMethod6() const {
    C t{};
    std::cout << NAMEOF_TYPE_EXPR(t) << std::endl;
    return t;
  }
};

struct Long {
  struct LL {
    int field = 0;
  };
  LL ll;
};

enum class Color { RED, GREEN, BLUE };

enum AnimalFlags { HasClaws = 1 << 0, CanFly = 1 << 1, EatsFish = 1 << 2, Endangered = 1 << 3 };

SomeStruct structvar;
Long othervar;
SomeStruct* ptrvar = &structvar;

void name_to_chars(const char* name) { std::cout << name << std::endl; }

void name_to_string(const std::string& name) { std::cout << name << std::endl; }

void name_to_string_view(std::string_view name) { std::cout << name << std::endl; }

int main() {
  // Compile-time.
  constexpr auto name = NAMEOF(structvar);
  using namespace std::literals::string_view_literals;
  static_assert("structvar"sv == name);

  name_to_chars(name.c_str());  // 'structvar'
  // or name_to_chars(name.data());
  // Note: c_str() return name as null-terminated C string, no memory allocation.

  name_to_string(name.str());  // 'structvar'
  // Note: str() occure memory allocation to copy name to std::string.
  // or name_to_string(std::string{name});
  // or name_to_string(static_cast<std::string>(name));
  // Note: cast to std::string occure memory allocation to copy name to std::string.

  name_to_string_view(name);  // 'structvar'
  // Note: Implicit cast to std::string_view, no memory allocation.

#if defined(NAMEOF_ENUM_SUPPORTED)
  // Nameof enum variable.
  auto color = Color::RED;
  std::cout << nameof::nameof_enum(color) << std::endl;           // 'RED'
  std::cout << NAMEOF_ENUM(color) << std::endl;                   // 'RED'
  std::cout << nameof::nameof_enum<Color::GREEN>() << std::endl;  // 'GREEN'

  // Nameof enum flags.
  auto flag = static_cast<AnimalFlags>(AnimalFlags::CanFly | AnimalFlags::EatsFish);
  std::cout << nameof::nameof_enum_flag(flag) << std::endl;  // 'CanFly|EatsFish'
  std::cout << NAMEOF_ENUM_FLAG(flag) << std::endl;          // 'CanFly|EatsFish'
#endif

  // Nameof.
  std::cout << NAMEOF(structvar) << std::endl;                // 'structvar'
  std::cout << NAMEOF(::structvar) << std::endl;              // 'structvar'
  std::cout << NAMEOF(structvar.somefield) << std::endl;      // 'somefield'
  std::cout << NAMEOF((&structvar)->somefield) << std::endl;  // 'somefield'
  std::cout << NAMEOF(othervar.ll.field) << std::endl;        // 'field'
  std::cout << NAMEOF(ptrvar) << std::endl;                   // 'ptrvar

  // Nameof function.
  std::cout << NAMEOF(&SomeStruct::SomeMethod1) << std::endl;                // 'SomeMethod1'
  std::cout << NAMEOF(structvar.SomeMethod2()) << std::endl;                 // 'SomeMethod2'
  std::cout << NAMEOF(SomeMethod3) << std::endl;                             // 'SomeMethod3'
  std::cout << NAMEOF(SomeMethod4<int, float>(1.0f)) << std::endl;           // 'SomeMethod4'
  std::cout << NAMEOF(&SomeClass<int>::SomeMethod5) << std::endl;            // 'SomeMethod5'
  std::cout << NAMEOF(&SomeClass<int>::SomeMethod6<long int>) << std::endl;  // 'SomeMethod6'

  // Nameof with template suffix.
  std::cout << NAMEOF_FULL(SomeMethod4<int, float>) << std::endl;  // 'SomeMethod4<int, float>'
  std::cout << NAMEOF_FULL(&SomeClass<int>::SomeMethod6<long int>)
            << std::endl;  // 'SomeMethod6<long int>'

  // Nameof type.
  std::cout << nameof::nameof_type<const Long::LL&>() << std::endl;       // 'Long::LL'
  std::cout << NAMEOF_TYPE(const Long::LL&) << std::endl;                 // 'Long::LL'
  std::cout << nameof::nameof_full_type<const Long::LL&>() << std::endl;  // 'const Long::LL &'
  std::cout << NAMEOF_FULL_TYPE(const Long::LL&) << std::endl;            // 'const Long::LL &'
  std::cout << NAMEOF_SHORT_TYPE(const Long::LL&) << std::endl;           // 'LL'
  std::cout << NAMEOF_SHORT_TYPE(const SomeClass<int>&) << std::endl;     // 'SomeClass'

  // Nameof variable type.
  std::cout << nameof::nameof_type<decltype(structvar)>() << std::endl;  // 'SomeStruct'
  std::cout << NAMEOF_TYPE_EXPR(structvar) << std::endl;                 // 'SomeStruct'
  std::cout << NAMEOF_TYPE_EXPR(std::declval<const SomeClass<int>>())
            << std::endl;  // 'SomeClass<int>'
  std::cout << NAMEOF_FULL_TYPE_EXPR(std::declval<const SomeClass<int>>())
            << std::endl;  // 'const SomeClass<int> &&'
  std::cout << NAMEOF_SHORT_TYPE_EXPR(std::declval<const SomeClass<int>>())
            << std::endl;  // 'SomeClass'

  // Nameof macro.
  std::cout << NAMEOF(__LINE__) << std::endl;  // '__LINE__'

  // Nameof raw.
  std::cout << NAMEOF_RAW(structvar.somefield) << std::endl;       // 'structvar.somefield'
  std::cout << NAMEOF_RAW(&SomeStruct::SomeMethod1) << std::endl;  // '&SomeStruct::SomeMethod1'

#if defined(NAMEOF_TYPE_RTTI_SUPPORTED)
  // Nameof type using RTTI.
  Base* ptr = new Derived();
  std::cout << NAMEOF_TYPE_RTTI(ptr) << std::endl;   // "Base *"
  std::cout << NAMEOF_TYPE_RTTI(*ptr) << std::endl;  // "Derived"
#endif

  // Some more complex example.

  std::cout << SomeMethod4<int>(structvar)
            << std::endl;  // 'SomeMethod4<int, SomeStruct>(SomeStruct value)'

  auto div = [](int x, int y) -> int {
    if (y == 0) {
      throw std::invalid_argument(NAMEOF(y).str() + " should not be zero!");
    }
    return x / y;
  };

  try {
    auto z = div(10, 0);
    std::cout << z << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;  // 'y should not be zero!'
  }

  /* Remarks */
#if 0
  // This expression does not have name.
  std::cout << NAMEOF(ptrvar[0]) << std::endl; // ''
  std::cout << NAMEOF(42.0) << std::endl; // ''
  std::cout << NAMEOF(42) << std::endl; // ''
  std::cout << NAMEOF(42.0_deg) << std::endl; // ''
  std::cout << NAMEOF((structvar)) << std::endl; // ''
  std::cout << NAMEOF((SomeMethod4<int, float>)(1.0f)) << std::endl; // ''
  std::cout << NAMEOF(42, 42, 42) << std::endl; // ''
  std::cout << NAMEOF(42 + 42) << std::endl; // ''
  std::cout << NAMEOF("Bad case"_string) << std::endl; // ''
  std::cout << NAMEOF("Bad case") << std::endl; // ''
  std::cout << NAMEOF("somevar.somefield") << std::endl; // ''
  std::cout << NAMEOF(42.f) << std::endl; // ''
  std::cout << NAMEOF(structvar.somefield++) << std::endl; // ''
  std::cout << NAMEOF(std::string{"test"}) << std::endl; // ''
#endif

  return 0;
}
