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

// &&    and
// &=    and_eq
// &    bitand
// |    bitor
// ~    compl
// !    not
// !=    not_eq
// ||    or
// |=    or_eq
// ^    xor
// ^=    xor_eq
// {    <%
// }    %>
// [    <:
// ]    :>
// #    %:
// ##    %:%:

// clang-format off
%:include <catch2/catch.hpp>

// %:include <iostream>

namespace <%
struct X <%
    compl X() <%%>  // destructor
    X() <%%>
    X(const X bitand) = delete;  // copy constructor

    bool operator not_eq(const X bitand other) <%
       return this not_eq bitand other;
    %>
%>;
%>

TEST_CASE("[OperatorAlternative]: ") <%
    // lambda with reference-capture:
    auto greet = <:bitand:>(const char* name) <%
        return "hello";
    %>;
    (void)greet;
%>

    // clang-format on
