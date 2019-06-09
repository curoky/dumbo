load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "rpcmetadata",
    srcs = glob([
        "gen-cpp2/metadata*.cpp",
        "gen-cpp2/RpcMetadata*.cpp",
    ]),
    hdrs = glob([
        "gen-cpp2/metadata*.h",
        "gen-cpp2/metadata*.tcc",
        "gen-cpp2/RpcMetadata*.h",
        "gen-cpp2/RpcMetadata*.tcc",
    ]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    include_prefix = "thrift/lib/thrift",
    # includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        "@com_github_facebook_fbthrift//:gen",
        "@com_github_facebook_fbthrift//:thrift-core",
        "@com_github_facebook_folly//:folly",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)

cc_library(
    name = "reflection",
    srcs = glob([
        "gen-cpp2/reflection*.cpp",
    ]),
    hdrs = glob([
        "gen-cpp2/reflection*.h",
        "gen-cpp2/reflection*.tcc",
    ]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    include_prefix = "thrift/lib/thrift",
    # includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        "@com_github_facebook_fbthrift//:gen",
        # "@com_github_facebook_fbthrift//:thrift-core",
        # "@com_github_facebook_folly//:folly",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)

cc_library(
    name = "frozen",
    srcs = glob([
        "gen-cpp2/frozen*.cpp",
    ]),
    hdrs = glob([
        "gen-cpp2/frozen*.h",
        "gen-cpp2/frozen*.tcc",
    ]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    include_prefix = "thrift/lib/thrift",
    # includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        "@//third_party/fbthrift/extra:rpcmetadata",
        "@com_github_facebook_fbthrift//:gen",
        # "@com_github_facebook_fbthrift//:thrift-core",
        # "@com_github_facebook_folly//:folly",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)
