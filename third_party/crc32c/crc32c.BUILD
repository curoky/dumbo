load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "crc32c",
    srcs = glob(
        [
            "src/*.cc",
            "src/*.h",
        ],
        [
            "src/*test.cc",
            "src/*benchmark.cc",
            "src/*test_main.cc",
        ],
    ),
    hdrs = glob(["include/crc32c/*.h"]),
    copts = [
        "-Isrc",
    ],
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = ["@//third_party/crc32c/extra:config"],
)
