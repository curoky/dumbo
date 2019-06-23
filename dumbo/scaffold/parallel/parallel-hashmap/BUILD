load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "ph_example",
    testonly = False,
    srcs = glob(["*.cc"]),
    copts = ["-std=c++17"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_parallel_hashmap//:parallel_hashmap",
    ],
)
