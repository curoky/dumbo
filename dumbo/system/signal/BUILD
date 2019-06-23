load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "signal_kill",
    srcs = glob(["*.cc"]),
    copts = [
        "-g",
        "-std=c++17",
        "-fno-omit-frame-pointer",
        "-fsanitize=address",
    ],
    linkopts = [
        "-lpthread",
        "-fsanitize=address",
    ],
    deps = [
        "//dumbo/utilities:catch2_main",
    ],
)
