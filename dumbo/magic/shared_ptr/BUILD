load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_library(
    name = "shared_ptr",
    srcs = ["shared_ptr.h"],
    copts = DUMBO_TEST_COPTS,
)

cc_test(
    name = "shared_ptr_test",
    testonly = False,
    srcs = ["shared_ptr_test.cc"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        ":shared_ptr",
        "//dumbo/utilities:catch2_main",
    ],
)
