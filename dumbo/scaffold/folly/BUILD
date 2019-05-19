load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "folly_example",
    srcs = glob(["*.cc"]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_facebook_folly//:folly",
    ],
)
