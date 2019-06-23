load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "example",
    testonly = False,
    srcs = glob(["*.cc"]),
    deps = [
        "//dumbo/utilities:catch2_main",
        "@boost//:coroutine2",
    ],
)
