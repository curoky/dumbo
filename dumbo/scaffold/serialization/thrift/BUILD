load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "mock_thrift",
    srcs = glob(["gen-cpp/*.cc"]),
    hdrs = glob(["gen-cpp/*.h"]),
    deps = [
        "@com_github_apache_thrift//:thrift",
    ],
)

cc_test(
    name = "example",
    testonly = False,
    srcs = glob([
        "*.h",
        "*.cc",
    ]),
    copts = [
        "-g",
        "-std=c++17",
    ],
    deps = [
        ":mock_thrift",
        "//dumbo/utilities:catch2_main",
        "@com_github_apache_thrift//:thrift",
    ],
)
