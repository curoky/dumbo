load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "taskflow_example",
    srcs = glob(["*.cc"]),
    copts = ["-std=c++17"],
    linkopts = ["-lpthread"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_taskflow_taskflow//:taskflow",
    ],
)
