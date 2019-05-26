load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "spdlog_example",
    srcs = glob(["*.cc"]),
    copts = [
        "-std=c++17",
    ],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_gabime_spdlog//:spdlog",
    ],
)
