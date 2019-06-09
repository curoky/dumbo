load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

"""
load("@rules_flex//flex:flex.bzl", "flex")
load("@rules_bison//bison:bison.bzl", "bison")
flex(
    name = "thriftl_srcs",
    src = "thrift/compiler/parse/thriftl.ll",
)

bison(
    name = "thrifty_srcs",
    src = "thrift/compiler/parse/thriftl.yy",
)

cc_library(
    name = "compiler",
    srcs = glob(
        ["thrift/compiler/**/*.cc"],
        [
            "thrift/compiler/**/test/**",
            "thrift/compiler/**/example/**",
            "thrift/compiler/**/benchmark/**",
        ],
    ) + [
        ":thriftl_srcs",
        ":thrifty_srcs",
    ],
    hdrs = glob([
        "thrift/compiler/**/*.h",
    ]),
    copts = [
        "-std=c++17",
        # "-DTHRIFTY_HH=",
        "-DTHRIFT_HAVE_LIBSNAPPY=0",
    ],
    includes = ["."],
    deps = [
        "@com_github_facebook_folly//:folly",
    ],
)
"""

# from cpp
cc_library(
    name = "thrift-core",
    srcs = [
        "thrift/lib/cpp/Thrift.cpp",
        "thrift/lib/cpp2/FieldRef.cpp",
    ],
    hdrs = glob([
        "thrift/lib/thrift/*.h",
        "thrift/lib/cpp/**/*.h",
        "thrift/lib/cpp2/**/*.h",
    ]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    includes = ["."],
    deps = [
        "@com_github_facebook_folly//:folly",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)

cc_library(
    name = "concurrency",
    srcs = glob([
        "thrift/lib/cpp/concurrency/*.cpp",
    ]),
    hdrs = glob([
        "thrift/lib/cpp/**/*.h",
        "thrift/lib/cpp2/**/*.h",
    ]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    includes = ["."],
    deps = [
        "@com_github_facebook_folly//:folly",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)

cc_library(
    name = "transport",
    srcs = glob([
        "thrift/lib/cpp/transport/*.cpp",
    ]) + [
        "thrift/lib/cpp/util/VarintUtils.cpp",
        "thrift/lib/cpp/util/THttpParser.cpp",
        "thrift/lib/cpp/util/PausableTimer.cpp",
    ],
    hdrs = glob([
        "thrift/lib/cpp/**/*.h",
        "thrift/lib/cpp2/**/*.h",
    ]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    includes = ["."],
    deps = [
        "@//third_party/fbthrift/extra:rpcmetadata",
        "@com_github_facebook_folly//:folly",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)

cc_library(
    name = "async",
    srcs = glob([
        "thrift/lib/cpp/async/*.cpp",
    ]) + [
        "thrift/lib/cpp/ContextStack.cpp",
        "thrift/lib/cpp/EventHandlerBase.cpp",
        "thrift/lib/cpp/server/TServerObserver.cpp",
    ],
    hdrs = glob([
        "thrift/lib/cpp/**/*.h",
        "thrift/lib/cpp2/**/*.h",
    ]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    includes = ["."],
    deps = [
        "@//third_party/fbthrift/extra:rpcmetadata",
        "@com_github_facebook_folly//:folly",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)

cc_library(
    name = "thrift",
    deps = [
        ":async",
        ":concurrency",
        ":thriftprotocol",
        ":transport",
    ],
)

cc_library(
    name = "thriftmetadata",
)

cc_library(
    name = "thriftfrozen2",
)

cc_library(
    name = "gen",
    srcs = glob([
        "thrift/lib/cpp2/gen/*.cpp",
    ]),
    hdrs = glob([
        "thrift/lib/cpp/**/*.h",
        "thrift/lib/cpp2/**/*.h",
    ]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    includes = ["."],
    deps = [
        "@com_github_facebook_folly//:folly",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)

cc_library(
    name = "thriftprotocol",
    srcs = glob([
        "thrift/lib/cpp/protocol/*.cpp",
        "thrift/lib/cpp2/protocol/*.cpp",
    ]),
    hdrs = glob([
        "thrift/lib/cpp/**/*.h",
        "thrift/lib/cpp2/**/*.h",
    ]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    includes = ["."],
    deps = [
        "@//third_party/fbthrift/extra:frozen",
        "@//third_party/fbthrift/extra:reflection",
        "@com_github_facebook_folly//:folly",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)

cc_library(
    name = "thriftcpp2",
    srcs = glob(
        [
            "thrift/lib/cpp2/async/*.cpp",
            "thrift/lib/cpp2/security/**/*.cpp",
            "thrift/lib/cpp2/server/*.cpp",
            "thrift/lib/cpp2/server/peeking/*.cpp",
            "thrift/lib/cpp2/transport/**/*.cpp",
            "thrift/lib/cpp2/util/*.cpp",
            "thrift/lib/cpp2/*.cpp",
        ],
        [
            "thrift/lib/cpp2/async/HTTP*.cpp",
            "thrift/lib/cpp2/transport/core/testutil/*.cpp",
            "thrift/lib/cpp2/**/test/**/*.cpp",
            "thrift/lib/cpp2/**/testutil/**/*.cpp",
        ],
    ),
    hdrs = glob([
        "thrift/lib/cpp2/**/*.h",
    ]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    includes = ["."],
    deps = [
        ":concurrency",
        ":thrift",
        ":thriftprotocol",
        "@//third_party/fbthrift/extra:rpcmetadata",
        "@com_github_facebook_folly//:folly",
        "@com_github_facebook_proxygen//:proxygen",
        "@com_github_facebook_wangle//:wangle",
        "@com_github_google_double_conversion//:double-conversion",
        "@zlib",
    ],
)
