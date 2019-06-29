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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_...
#include <stdio.h>  // for printf

#include <iostream>  // for endl, operator<<, basic_ostream::operator<<, cout, ostream, basic_ostream, basic...
#include <string>  // for basic_string, operator==, string, allocator

TEST_CASE("[ExplicitCast]: StaticCastTest") {
  // 完成编译器认可的隐式类型转换
  // - 基本数据类型之间的转换
  // - 派生体系中向上转型:将派生类指针或引用转化为基类指针或引用(向上转型)
  double PI = 3.1415926;
  int x = static_cast<int>(PI);
  REQUIRE(x == 3);
}

TEST_CASE("[ExplicitCast]: DynamicCast") {
  // 执行派生类指针或引用与基类指针或引用之间的转换
  // - 其他三种都是编译时完成的, dynamic_cast是运行时处理的, 运行时要进行运行时类型检查
  // - 基类中要有虚函数, 因为运行时类型检查的类型信息在虚函数表中, 有虚函数才会有虚函数表
  // - 可以实现向上转型和向下转型, 前提是必须使用public或protected继承

  struct Base {
    Base() { std::cout << "Base" << std::endl; }
    virtual std::string info() { return "Parent::info"; }
    virtual ~Base() = default;
  };

  struct Derived : public Base {
    Derived() { std::cout << "Derived" << std::endl; }
    std::string info() override { return "Derived::info"; }
  };

  Base* a = new Base();
  Base* b = new Derived();
  Derived* c = new Derived();

  // 不安全 ,仍然返回 a 的地址
  REQUIRE(static_cast<Derived*>(a) != nullptr);
  REQUIRE(dynamic_cast<Derived*>(a) == nullptr);

  REQUIRE(static_cast<Derived*>(b) == dynamic_cast<Derived*>(b));

  REQUIRE(static_cast<Base*>(c) == dynamic_cast<Base*>(c));

  REQUIRE(static_cast<Base*>(c)->info() == "Derived::info");
  REQUIRE(dynamic_cast<Base*>(c)->info() == "Derived::info");

  delete a;
  delete b;
  delete c;
}

TEST_CASE("[ExplicitCast]: ConstCastTest") {
  // 只能对指针或者引用去除或者添加const属性, 对于变量直接类型不能使用const_cast
  // 不能用于不同类型之间的转换, 只能改变同种类型的const属性.
  int v = 0;
  const int& v1 = v;
  int& v3 = const_cast<int&>(v1);
  v3++;
  std::cout << v << std::endl;
}

TEST_CASE("[ExplicitCast]: ReinterpretCastTest") {
  // 从字面意思理解是一个“重新解释的类型转换”.
  // 也就是说对任意两个类型之间的变量我们都可以个使用reinterpret_cast在他们之间相互转换,
  // 无视类型信息.
  struct A {
    int m_a;
  };
  struct B {
    int m_b;
  };
  struct C : public A, public B {};
  C c;
  printf("%p, %p, %p", &c, reinterpret_cast<B*>(&c), static_cast<B*>(&c));
}
