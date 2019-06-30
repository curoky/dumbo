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

// 空基类优化-
// 参考：https:// www.jianshu.com/p/ff9eb9c381c1
// 注：MultiDerived5的内存布局分析错了，只占5个字节，MultiDerived1 的 Empty 与 Empty 不是连续的
// http://www.cantrip.org/emptyopt.html

/*
 * 空类就是没有静态成员变量的类，却通常带有 typedef 和成员函数。
 * 为保证不同的对象的地址是不同的，C++ 要求空类的大小不能为零。
 * 通常情况下，空基类的长度为1，对齐严格个情况下可能会是8
 * 但在某些情况下，空基类占用的空间会被优化掉
 */

#include <catch2/catch.hpp>
#pragma pack(push)  // 保存对齐状态
#pragma pack(1)     // 设定为1字节对齐

// clang-format off
TEST_CASE("[EmptyClass]: SizeOfTest") {
    // 空类占用 1个字节
    // 虚空类占用 8 个字节(虚指针)
    class Empty {};
    class EmptyVirtual { virtual void func() {} };
    REQUIRE(sizeof(Empty)== 1);
    REQUIRE(sizeof(EmptyVirtual)== 8);
}

TEST_CASE("[EmptyClass]: ExtendTest") {
    // 虽然父类占用了1个字节，但子类没有额外多出1个字节，仍然只占用一个字节
    class Parent {};
    class Child1 : public Parent {};
    class Child2 : public Parent { int size; };

    REQUIRE(sizeof(Parent)== 1);
    REQUIRE(sizeof(Child1)== 1);
    REQUIRE(sizeof(Child2)== 4);
}

namespace {
class Base { static const int size = 1; };
TEST_CASE("[EmptyClass]: StaticTest") {
    // static 对象不占用类空间
    REQUIRE(sizeof(Base)== 1);
}
}  // namespace

TEST_CASE("[EmptyClass]: NotWorkTest") {
    // 在某些情况下空基类优化失效
    class Parent {};
    class Child1 : public Parent { Parent p; };
    class Child2 : public Parent { int size; Parent p; };

    // 1. 当基类作为子类的成员变量时。内存模型如下：
    // +--------+
    // | 1 Byte | --> Parent
    // +-------->                  +-> Child1
    // | 1 Byte | --> Member Parent
    // +--------+
    REQUIRE(sizeof(Child1)== 2);

    // 2. 依然进行了空基类优化。因为基类 Parent 与子类中的成员 Parent 的地址空间不是相连的，
    // 不发生冲突（注意此时优化掉了基类 Parent 的一个字节，并没有优化子类成员变量 Parent）
    // 在子类成员 Parent 后补齐三个字节，所以整体占用的空间是八个字节。
    // +--------+
    // |        |
    // |        |
    // | 4 Byte | -->      int
    // |        |
    // +--------+                  +-> Child2
    // | 1 Byte | --> Member Parent
    // +--------+
    REQUIRE(sizeof(Child2)== 5);
}

TEST_CASE("[EmptyClass]: MultiExtend") {
    class Parent1 {};
    class Parent2 {};
    class Parent3 {};
    class Child : public Parent1, Parent2, Parent3 {};
    // 编译器认为不同的空类在子类的内存空间是不会发生冲突的。
    REQUIRE(sizeof(Child)== 1);
}
TEST_CASE("[EmptyClass]: DiamondInheritanceTest") {
    // 菱形继承时不会进行空基类优化。
    class A {};
    class B1 : public A {};
    class B2 : public A {};
    class C : public B1, B2 {};
    REQUIRE(sizeof(B1)== 1);
    REQUIRE(sizeof(B2)== 1);
    // 由于A是一个空基类，B1/B2也是空基类，并且B1/B2在子类C的内存空间中是连续的，
    // 此时如果进行了空基类优化，则两个A就无法区分
    // +--------+
    // | 1 Byte | --> B1
    // +-------->         +-> C
    // | 1 Byte | --> B2
    // +--------+
    REQUIRE(sizeof(C)== 2);

    class NotEmpty { int size; };
    // B1 中的A与成员A直接隔了NotEmpty，内存上不冲突，因此可以优化
    // +--------+
    // |        |
    // |        |
    // | 4 Byte | --> NotEmpty
    // |        |
    // +--------+                +-> D1
    // | 1 Byte | --> Member A
    // +--------+
    class D1 : public B1, NotEmpty { A a; };
    REQUIRE(sizeof(D1)== 5);

    // B1 中的A与成员A是*不连续*的，会进行优化
    // +--------+
    // |        |
    // |        |
    // | 4 Byte | --> NotEmpty
    // |        |
    // +--------+                +-> D2
    // | 1 Byte | --> Member A
    // +--------+
    class D2 : public NotEmpty, B1 { A a; };
    REQUIRE(sizeof(D2)== 5);

    // 进行了空基类优化，因为B1中的A不与其它A冲突
    // +--------+
    // |        |
    // |        |
    // | 4 Byte | --> NotEmpty  +-> D3
    // |        |
    // +--------+
    class D3 : public NotEmpty, B1 {};
    REQUIRE(sizeof(D3)== 4);
}
// clang-format on
#pragma pack(pop)  // 恢复对齐状态
