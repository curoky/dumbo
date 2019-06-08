load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "wangle",
    srcs = glob(
        ["wangle/**/*.cpp"],
        [
            "wangle/**/test/**/*.cpp",
            "wangle/**/example/**/*.cpp",
        ],
    ),
    hdrs = glob(["wangle/**/*.h"]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        "@com_github_facebook_folly//:folly",
        "@com_github_facebookincubator_fizz//:fizz",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)
