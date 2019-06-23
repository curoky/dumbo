load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "nameof_example",
    srcs = glob(["*.cc"]),
    copts = [
        "-std=c++17",
    ],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_neargye_nameof//:nameof",
    ],
)
