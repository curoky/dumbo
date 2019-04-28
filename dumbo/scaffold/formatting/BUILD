load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "formatting_example",
    srcs = glob(["*.cc"]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_abseil_abseil//absl/strings:str_format",
        "@com_github_catchorg_catch2//:catch2",
        "@com_github_facebook_folly//:folly",
        "@com_github_fmtlib_fmt//:fmt",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)
