load("@rules_cc//cc:defs.bzl", "cc_binary")

common_copts = [
    "-g",
    "-fno-omit-frame-pointer",
    "-fsanitize=thread",
]

common_linkopts = ["-fsanitize=thread"]

cc_binary(
    name = "simple_race",
    srcs = ["simple_race.cc"],
    copts = common_copts,
    linkopts = common_linkopts,
)
