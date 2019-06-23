load("@rules_cc//cc:defs.bzl", "cc_binary")

common_copts = [
    "-g",
    "-O0",
    "-fno-omit-frame-pointer",
]


cc_binary(
    name = "case0",
    srcs = [
        "case0.cc",
    ],
    deps = [
        "@com_github_gflags_gflags//:gflags",
    ],
)

cc_binary(
    name = "asm",
    srcs = [
        "asm.cc",
    ],
    copts = common_copts,
    deps = [
        "@com_github_gflags_gflags//:gflags",
    ],
)
