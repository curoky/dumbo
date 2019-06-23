load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "example",
    testonly = False,
    srcs = glob(["*.cc"]),
    copts = ["-std=c++17"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_facebook_zstd//:zstd",
        "@com_github_google_snappy//:snappy",
    ],
)
