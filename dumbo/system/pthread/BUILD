load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "thread_name",
    testonly = False,
    srcs = glob(["*.cc"]),
    copts = [
        "-std=c++17",
    ],
    linkopts = ["-lpthread"],
    deps = [
        "//dumbo/utilities:catch2_main",
    ],
)
