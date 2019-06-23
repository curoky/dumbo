load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "cow_string",
    srcs = ["cow_string.h"],
)

cc_test(
    name = "cow_string_test",
    testonly = False,
    srcs = ["cow_string_test.cc"],
    deps = [
        ":cow_string",
        "//dumbo/utilities:catch2_main",
    ],
)
