load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "libaio",
    srcs = glob(["src/*.c"]),
    hdrs = glob(["src/*.h"]),
    includes = ["src"],
    linkstatic = 1,
    # linkopts = ["-Wl,--version-script=external/com_pagure_libaio/src/libaio.map"],
    visibility = ["//visibility:public"],
)
