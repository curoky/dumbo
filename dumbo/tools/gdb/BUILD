load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")
load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "container",
    srcs = ["container.cc"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
)
