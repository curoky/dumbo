load("@rules_3rd//third_party/fbthrift:build_defs.bzl", "fbthrift_library")
load("@rules_cc//cc:defs.bzl", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

fbthrift_library(
    name = "mock_fbthrift",
    srcs = ["mock.thrift"],
    include_prefix = "dumbo/scaffold/serialization/fbthrift",
    services = ["EchoService"],
)

cc_test(
    name = "example",
    testonly = False,
    srcs = glob([
        "*.h",
        "*.cc",
    ]) + [":mock_fbthrift"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_facebook_fbthrift//:fbthrift",
    ],
)
