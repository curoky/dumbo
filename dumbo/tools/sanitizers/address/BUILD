load("@rules_cc//cc:defs.bzl", "cc_binary")

common_copts = [
    "-g",
    "-fno-omit-frame-pointer",
    "-fsanitize=address",
]

common_linkopts = ["-fsanitize=address"]

cc_binary(
    name = "use-after-free",
    srcs = ["use-after-free.cc"],
    copts = common_copts,
    linkopts = common_linkopts,
)

cc_binary(
    name = "heap-buffer-overflow",
    srcs = ["heap-buffer-overflow.cc"],
    copts = common_copts,
    linkopts = common_linkopts,
)

cc_binary(
    name = "global-buffer-overflow",
    srcs = ["global-buffer-overflow.cc"],
    copts = common_copts,
    linkopts = common_linkopts,
)

cc_binary(
    name = "stack-buffer-overflow",
    srcs = ["stack-buffer-overflow.cc"],
    copts = common_copts,
    linkopts = common_linkopts,
)

cc_binary(
    name = "use-after-return",
    srcs = ["use-after-return.cc"],
    copts = common_copts,
    linkopts = common_linkopts,
)

cc_binary(
    name = "use-after-scope",
    srcs = ["use-after-scope.cc"],
    copts = common_copts,
    linkopts = common_linkopts,
)

cc_binary(
    name = "memory-leaks",
    srcs = ["memory-leaks.cc"],
    copts = common_copts,
    linkopts = common_linkopts,
)
