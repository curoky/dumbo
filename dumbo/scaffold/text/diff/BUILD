load("@rules_cc//cc:defs.bzl", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_test(
    name = "google-diff",
    testonly = False,
    srcs = ["google-diff.cc"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_google_diff_match_patch//:diff-match-patch",
        "@qt//:qt_core",
    ],
)
