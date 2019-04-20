load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "compression_example",
    srcs = glob(["*.cc"]),
    copts = ["-std=c++17"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_catchorg_catch2//:catch2",
        "@com_github_facebook_zstd//:libzstd",
        "@com_github_google_snappy//:snappy",
    ],
)
