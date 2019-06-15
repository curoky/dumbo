load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "fizz",
    srcs = glob(
        ["fizz/**/*.cpp"],
        [
            "fizz/**/test/**/*.cpp",
            "fizz/**/javacrypto/**/*.cpp",
        ],
    ),
    hdrs = glob(["fizz/**/*.h"]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        "@com_github_facebook_folly//:folly",
        "@com_github_facebook_zstd//:libzstd",
        "@com_github_google_brotli//:brotlidec",
        "@com_github_google_brotli//:brotlienc",
        "@com_github_google_double_conversion//:double-conversion",
        "@com_github_libsodium//:sodium",
    ],
)
