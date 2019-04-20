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
 * @file: deprecated.cc
 * ----------------------------------------------------------------------------
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

[[deprecated("请使用新接口")]] void func() {}

// class/struct/union:

struct [[deprecated]] Echo {};

[[deprecated]] typedef Echo* Echo_ptr;

template <typename T>
struct [[deprecated]] People {};

template <>
struct [[deprecated]] People<int> {};

enum [[deprecated]] E{};

enum class Person { A, B [[deprecated]] = 42 };

#pragma GCC diagnostic pop
