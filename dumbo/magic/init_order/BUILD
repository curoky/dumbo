load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_binary(
    name = "main",
    srcs = [
        "lib.cc",
        "lib.h",
        "main.cc",
    ],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    # hdrs = ["lib.h"],
    deps = ["@com_github_catchorg_catch2//:catch2"],
)
