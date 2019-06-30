load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "loop_unrolling",
    srcs = ["main.cc"],
    copts = [
        "-O2",
        "-DNDEBUG",
    ],
    deps = [
        "@com_github_google_benchmark_O2//:benchmark",
    ],
)

cc_binary(
    name = "loop_unrolling_O0",
    srcs = ["main.cc"],
    deps = [
        "@com_github_google_benchmark//:benchmark",
    ],
)
