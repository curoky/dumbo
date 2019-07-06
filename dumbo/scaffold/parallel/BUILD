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
        "@com_github_cameron314_concurrentqueue//:concurrentqueue",
        "@com_github_parallel_hashmap//:parallel_hashmap",
        "@com_github_taskflow_taskflow//:taskflow",
        "@tbb",
    ],
)
