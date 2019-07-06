load("@rules_cc//cc:defs.bzl", "cc_test")
load("@rules_3rd//third_party/fbthrift:build_defs.bzl", "fbthrift_library")

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
    copts = [
        "-g",
        "-std=c++17",
    ],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_facebook_fbthrift//:fbthrift",
    ],
)
