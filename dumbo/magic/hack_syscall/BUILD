load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "hack",
    srcs = [
        "hack.cc",
        "hack.h",
    ],
    alwayslink = True,
)

cc_binary(
    name = "main",
    srcs = [
        "main.cc",
    ],
    deps = [":hack"],
    # linkopts = ["-lpthread"],
)
