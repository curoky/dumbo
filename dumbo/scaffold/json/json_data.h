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
 * @file: json_data.h
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <string>

static const std::string json_data = R"~(
{
    "key_int": 1,
    "key_str": "value2",
    "key_bool": false,
    "key_null": null,
    "key_double": 1.1e+100,
    "key_double2": -0.123,
    "key_list_eq": [1, 2, 3],
    "key_list_mix": ["1", 2, 3],
    "key_map_eq": {
        "kk1": "1",
        "kk2": "2"
    },
    "key_map_mix": {
        "kk1": 1,
        "kk2": "2",
        "kk3": [1, 2, 3]
    }
}
)~";
