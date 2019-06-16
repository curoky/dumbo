load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "example",
    srcs = glob([
        "*.h",
        "*.cc",
    ]),
    copts = [
        "-g",
        "-std=c++17",
    ],
    deps = [
        "//dumbo/scaffold/serialization/fbthrift:mock_fbthrift",
        "//dumbo/utilities:catch2_main",
        "@com_github_facebook_fbthrift//:thriftcpp2",
    ],
)
