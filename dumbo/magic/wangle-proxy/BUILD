# Copyright 2020 curoky(cccuroky@gmail.com).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_binary(
    name = "wangle-proxy",
    srcs = glob([
        "*.h",
        "*.cc",
    ]),
    copts = DUMBO_TEST_COPTS + ["-I."],
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "@com_github_gflags_gflags//:gflags",
        "@org_openssl//:crypto",
        "@com_github_facebook_folly//:folly",
        "@com_github_facebook_wangle//:wangle",
        "@com_github_google_glog//:glog",
    ],
)
