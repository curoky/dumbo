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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <array>        // for array
#include <cstddef>      // for nullptr_t
#include <type_traits>  // for integral_constant<>::value, is_scalar_v, is_arithmetic_v, is_base_of, is_class, is_enum, is_trivial_v, is_union, is_const_v, is_floating_point, is_fundamental_v, is_integral, is_object_v, is_array, is_function, is_lvalue_reference_v, is_reference_v, is_rvalue_reference_v, is_member_pointer_v, is_null_pointer, is_pointer, is_pointer_v, is_void, is_volatile_v, is_compound_v, is_member_function_pointer_v, is_member_object_pointer_v, is_pod_v, remove_reference, remove_reference<>::type

namespace {
struct ClassType {
  void func() {}
};
union UnionType {};
enum EnumType {};
enum class EnumClassType {};
void func() {}
}  // namespace

TEST_CASE("[Type-properties]: primary type categories") {
  REQUIRE(std::is_void<void>::value == true);
  REQUIRE(std::is_void<int>::value == false);

  REQUIRE(std::is_null_pointer<std::nullptr_t>::value == true);
  REQUIRE(std::is_null_pointer<int*>::value == false);
  REQUIRE(std::is_pointer<std::nullptr_t>::value == false);
  REQUIRE(std::is_pointer<int*>::value == true);

  REQUIRE(std::is_integral<int>::value == true);
  REQUIRE(std::is_integral<bool>::value == true);
  REQUIRE(std::is_integral<char>::value == true);
  REQUIRE(std::is_integral<float>::value == false);

  REQUIRE(std::is_floating_point<float>::value == true);
  REQUIRE(std::is_floating_point<double>::value == true);
  REQUIRE(std::is_floating_point<long double>::value == true);
  REQUIRE(std::is_floating_point<int>::value == false);

  REQUIRE(std::is_array<int>::value == false);
  REQUIRE(std::is_array<int[]>::value == true);
  REQUIRE(std::is_array<std::array<int, 10>>::value == false);

  REQUIRE(std::is_enum<int>::value == false);
  REQUIRE(std::is_enum<EnumType>::value == true);
  REQUIRE(std::is_enum<EnumClassType>::value == true);
  REQUIRE(std::is_enum<UnionType>::value == false);
  REQUIRE(std::is_enum<ClassType>::value == false);

  REQUIRE(std::is_union<int>::value == false);
  REQUIRE(std::is_union<EnumType>::value == false);
  REQUIRE(std::is_union<EnumClassType>::value == false);
  REQUIRE(std::is_union<UnionType>::value == true);
  REQUIRE(std::is_union<ClassType>::value == false);

  REQUIRE(std::is_class<int>::value == false);
  REQUIRE(std::is_class<EnumType>::value == false);
  REQUIRE(std::is_class<EnumClassType>::value == false);
  REQUIRE(std::is_class<UnionType>::value == false);
  REQUIRE(std::is_class<ClassType>::value == true);

  REQUIRE(std::is_function<int>::value == false);
  REQUIRE(std::is_function<void()>::value == true);
  REQUIRE(std::is_function<decltype(func)>::value == true);
  // TODO(curoky): get member function type, not member function pointer type
  // REQUIRE(std::is_function<decltype(&ClassType::func)>::value == true);

  REQUIRE(std::is_reference_v<int> == false);
  REQUIRE(std::is_reference_v<int&> == true);
  REQUIRE(std::is_reference_v<int&&> == true);
  REQUIRE(std::is_lvalue_reference_v<int> == false);
  REQUIRE(std::is_lvalue_reference_v<int&> == true);
  REQUIRE(std::is_lvalue_reference_v<int&&> == false);
  REQUIRE(std::is_rvalue_reference_v<int> == false);
  REQUIRE(std::is_rvalue_reference_v<int&> == false);
  REQUIRE(std::is_rvalue_reference_v<int&&> == true);

  REQUIRE(std::is_pointer_v<int(ClassType::*)> == false);
  REQUIRE(std::is_pointer_v<decltype(&ClassType::func)> == false);
  REQUIRE(std::is_member_pointer_v<int(ClassType::*)> == true);
  REQUIRE(std::is_member_pointer_v<decltype(&ClassType::func)> == true);
  REQUIRE(std::is_member_object_pointer_v<int(ClassType::*)> == true);
  REQUIRE(std::is_member_function_pointer_v<decltype(&ClassType::func)> == true);
}

TEST_CASE("[Type-properties]: composite type categories") {
  // If T is a fundamental type (that is, arithmetic type, void, or nullptr_t)
  REQUIRE(std::is_fundamental_v<void> == true);
  REQUIRE(std::is_fundamental_v<void const> == true);
  REQUIRE(std::is_fundamental_v<std::nullptr_t> == true);
  REQUIRE(std::is_fundamental_v<void*> == false);

  // If T is an arithmetic type (that is, an integral type or a floating-point type) or a
  // cv-qualified version thereof
  REQUIRE(std::is_arithmetic_v<int> == true);
  REQUIRE(std::is_arithmetic_v<int const> == true);
  REQUIRE(std::is_arithmetic_v<int&> == false);
  REQUIRE(std::is_arithmetic_v<int*> == false);
  REQUIRE(std::is_arithmetic_v<char> == true);

  // If T is a scalar type (that is a possibly cv-qualified arithmetic, pointer, pointer to
  // member, enumeration, or std::nullptr_t type)
  REQUIRE(std::is_scalar_v<int*> == true);
  REQUIRE(std::is_scalar_v<std::nullptr_t> == true);
  REQUIRE(std::is_scalar_v<int&> == false);
  REQUIRE(std::is_scalar_v<void> == false);
  REQUIRE(std::is_scalar_v<void()> == false);
  REQUIRE(std::is_scalar_v<int(ClassType::*)> == true);
  REQUIRE(std::is_scalar_v<decltype(&ClassType::func)> == true);
  REQUIRE(std::is_scalar_v<decltype(func)> == false);

  // If T is an object type (that is any possibly cv-qualified type other than function,
  // reference, or void types)
  REQUIRE(std::is_object_v<int*> == true);
  REQUIRE(std::is_object_v<int&> == false);
  REQUIRE(std::is_object_v<void> == false);
  REQUIRE(std::is_object_v<void()> == false);

  // If T is a compound type (that is, array, function, object pointer, function pointer, member
  // object pointer, member function pointer, reference, class, union, or enumeration, including
  // any cv-qualified variants),
  // NOTE: Any C++ type is either fundamental or compound.
  REQUIRE(std::is_compound_v<int> == false);
}

namespace {
struct ClassEmpty {};
struct ClassMember {
  int member;
};
struct ClassConstructor {
  ClassConstructor() {}
};
struct ClassPrivate {
  int m1;

 private:
  int m2;
};
}  // namespace

TEST_CASE("[Type-properties]: type properties") {
  REQUIRE(std::is_const_v<const int*> == false);
  REQUIRE(std::is_const_v<int* const> == true);
  REQUIRE(std::is_const_v<const int&> == false);
  REQUIRE(std::is_const_v<typename std::remove_reference<const int&>::type> == true);

  REQUIRE(std::is_volatile_v<int> == false);
  REQUIRE(std::is_volatile_v<volatile int> == true);

  // If T is TrivialType (that is, a scalar type, a trivially copyable class with a trivial
  // default constructor, or array of such type/class, possibly cv-qualified)
  REQUIRE(std::is_trivial_v<int*> == true);
  REQUIRE(std::is_trivial_v<ClassEmpty> == true);
  REQUIRE(std::is_trivial_v<ClassMember> == true);
  REQUIRE(std::is_trivial_v<ClassPrivate> == true);
  REQUIRE(std::is_trivial_v<ClassConstructor> == false);

  // If T is a PODType ("plain old data type"), that is, both trivial and standard-layout
  REQUIRE(std::is_pod_v<ClassPrivate> == false);
  // std::is_empty_v
  // std::is_polymorphic_v
  // std::is_abstract_v
  // std::is_final_v
  // std::is_aggregate_v
  // std::is_unsigned_v
  // std::is_signed_v
  // std::is_bounded_array_v
  // std::is_unbounded_array_v
}

TEST_CASE("[Type-properties]: supported operations") {}

TEST_CASE("[Type-properties]: property queries") {}

TEST_CASE("[Type-properties]: type relationships") {
  using ParentA = struct {};
  using ParentB = struct {};
  using Child = struct : ParentA, ParentB {};
  REQUIRE((std::is_base_of<Child, Child>::value) == true);
  REQUIRE((std::is_base_of<Child, ParentA>::value) == false);
  REQUIRE((std::is_base_of<Child, ParentB>::value) == false);
  REQUIRE((std::is_base_of<ParentA, Child>::value) == true);
  REQUIRE((std::is_base_of<ParentB, Child>::value) == true);
}
