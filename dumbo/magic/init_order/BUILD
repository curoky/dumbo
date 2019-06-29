load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = [
        "lib.h",
        "lib.cc",
        "main.cc",
    ],
    # hdrs = ["lib.h"],
    deps = ["@com_github_catchorg_catch2//:catch2"],
)
