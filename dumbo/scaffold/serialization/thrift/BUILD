load("@rules_3rd//third_party/thrift:build_defs.bzl", "thrift_library")
load("@rules_cc//cc:defs.bzl", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

thrift_library(
    name = "mock_thrift",
    srcs = ["mock.thrift"],
    include_prefix = "dumbo/scaffold/serialization/thrift",
    services = ["EchoService"],
)

cc_test(
    name = "example",
    testonly = False,
    srcs = glob([
        "*.h",
        "*.cc",
    ]) + [":mock_thrift"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_apache_thrift//:thrift",
    ],
)
