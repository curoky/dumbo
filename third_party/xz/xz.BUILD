load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "xz",
    srcs = glob(
        [
            "src/**/*.h",
            "src/**/*.c",
        ],
        [
            "src/xz/**",
            "src/liblzma/check/crc32_small.*",
        ],
    ),
    hdrs = glob(["src/**/*.h"]),
    copts = [
        "-Isrc/common",
        "-Isrc/liblzma/lz",
        "-Isrc/liblzma/common",
        "-Isrc/liblzma/check",
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        "src/common",
        "src/liblzma/api",
        "src/liblzma/check",
        "src/liblzma/common",
        "src/liblzma/delta",
        "src/liblzma/lz",
        "src/liblzma/lzma",
        "src/liblzma/rangecoder",
        "src/liblzma/simple",
    ],
    linkstatic = 1,
    visibility = ["//visibility:public"],
    deps = ["@//third_party/xz/extra:config"],
)
