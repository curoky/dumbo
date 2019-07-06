load("@rules_cc//cc:defs.bzl", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_test(
    name = "example",
    testonly = False,
    srcs = glob(["**/*.cc"]),
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "//dumbo/utilities:catch2_main",
        "@boost//:algorithm",
        "@boost//:assign",
        "@boost//:foreach",
        "@boost//:interprocess",
        "@boost//:lexical_cast",
        "@boost//:pool",
        "@boost//:range",
    ],
)
