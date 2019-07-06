load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_library(
    name = "hack",
    srcs = [
        "hack.cc",
        "hack.h",
    ],
    copts = DUMBO_TEST_COPTS,
    alwayslink = True,
)

cc_binary(
    name = "main",
    srcs = [
        "main.cc",
    ],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [":hack"],
    # linkopts = ["-lpthread"],
)
