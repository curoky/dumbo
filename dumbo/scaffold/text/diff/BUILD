load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "google-diff",
    srcs = ["google-diff.cc"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_google_diff_match_patch//:diff-match-patch",
        "@qt//:qt_core",
    ],
)
