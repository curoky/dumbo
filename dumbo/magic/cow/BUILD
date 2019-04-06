load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cow_string",
    srcs = ["cow_string.h"],
)

cc_test(
    name = "cow_string_test",
    srcs = ["cow_string_test.cc"],
    deps = [
        ":cow_string",
        "@com_github_catchorg_catch2//:catch2",
    ],
)
