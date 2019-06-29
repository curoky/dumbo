load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "example",
    testonly = False,
    srcs = glob(["**/*.cc"]),
    copts = ["-std=c++17"],
    linkopts = ["-lpthread"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@boost//:serialization",
        # "@boost//:foreach",
        # "@boost//:interprocess",
        # "@boost//:lexical_cast",
        # "@boost//:pool",
    ],
)
