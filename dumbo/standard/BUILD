load("@rules_cc//cc:defs.bzl", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_test(
    name = "example",
    testonly = False,
    srcs = glob(["**/*.cc"]),
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "//dumbo/utilities",
        "//dumbo/utilities:catch2_main",
        "@boost//:container_hash",
        "@boost//:functional",
        "@com_github_abseil_abseil//absl/algorithm",
        "@com_github_abseil_abseil//absl/debugging:demangle_internal",
        "@com_github_facebook_folly//:folly",
    ],
)
