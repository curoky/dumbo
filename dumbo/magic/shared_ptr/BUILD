load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "shared_ptr",
    srcs = ["shared_ptr.h"],
)

cc_test(
    name = "shared_ptr_test",
    srcs = ["shared_ptr_test.cc"],
    deps = [
        ":shared_ptr",
        "//dumbo/utilities:catch2_main",
    ],
)
