load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "mock_fbthrift",
    srcs = glob(["gen-cpp2/*.cpp"]),
    hdrs = glob([
        "gen-cpp2/*.h",
        "gen-cpp2/*.tcc",
    ]),
    copts = [
        "-g",
        "-std=c++17",
    ],
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        "@com_github_facebook_fbthrift//:thriftcpp2",
    ],
)

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
        ":mock_fbthrift",
        "//dumbo/utilities:catch2_main",
        "@com_github_facebook_fbthrift//:thriftcpp2",
    ],
)
