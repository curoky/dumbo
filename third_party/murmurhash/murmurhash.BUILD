load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "murmurhash",
    srcs = [
        "src/MurmurHash1.cpp",
        "src/MurmurHash2.cpp",
        "src/MurmurHash3.cpp",
    ],
    hdrs = [
        "src/MurmurHash1.h",
        "src/MurmurHash2.h",
        "src/MurmurHash3.h",
    ],
    includes = ["src/"],
    visibility = ["//visibility:public"],
)
