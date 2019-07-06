load("@rules_cc//cc:defs.bzl", "cc_test")
load("@rules_3rd//third_party/thrift:build_defs.bzl", "thrift_library")

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
    copts = [
        "-g",
        "-std=c++17",
    ],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_apache_thrift//:thrift",
    ],
)
