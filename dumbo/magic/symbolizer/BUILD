load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_binary(
    name = "stack_strace",
    srcs = ["stack_strace.cc"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "@boost//:stacktrace",
        "@com_github_facebook_folly//:folly",
    ],
)

cc_binary(
    name = "crash",
    srcs = ["crash.cc"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "@com_github_facebook_folly//:folly",
    ],
)

cc_binary(
    name = "small_sig_alt_stack_crash",
    srcs = ["small_sig_alt_stack_crash.cc"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "@com_github_facebook_folly//:folly",
    ],
)

cc_binary(
    name = "execinfo",
    srcs = ["execinfo.cc"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "@com_github_facebook_folly//:folly",
    ],
)
