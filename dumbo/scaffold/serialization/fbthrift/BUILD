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
        "-Iexternal/com_github_google_double_conversion",
    ],
    deps = [
        "@com_github_google_double_conversion//:double-conversion",
        "@com_github_facebook_fbthrift//:thriftcpp2",
    ],
)
