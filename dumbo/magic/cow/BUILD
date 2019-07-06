load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_library(
    name = "cow_string",
    srcs = ["cow_string.h"],
    copts = DUMBO_TEST_COPTS,
)

cc_test(
    name = "cow_string_test",
    testonly = False,
    srcs = ["cow_string_test.cc"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        ":cow_string",
        "//dumbo/utilities:catch2_main",
    ],
)
