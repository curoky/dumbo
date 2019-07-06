load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_binary(
    name = "solution",
    srcs = ["solution.cc"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
)
