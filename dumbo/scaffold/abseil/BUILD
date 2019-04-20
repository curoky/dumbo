load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "abseil_example",
    srcs = glob(["**/*.cc"]),
    copts = ["-std=c++2a"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_abseil_abseil//absl/numeric:int128",
        "@com_github_catchorg_catch2//:catch2",
    ],
)
