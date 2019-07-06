load("@rules_cc//cc:defs.bzl", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_test(
    name = "example",
    testonly = False,
    srcs = glob([
        "*.h",
        "*.cc",
    ]) + ["//dumbo/scaffold/serialization/fbthrift:mock_fbthrift"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        # "//dumbo/scaffold/serialization/fbthrift:mock_fbthrift",
        "//dumbo/utilities:catch2_main",
        "@com_github_facebook_fbthrift//:fbthrift",
    ],
)
