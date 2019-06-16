load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "liburing",
    srcs = glob(["src/*.c"]),
    hdrs = glob(["src/**/*.h"]),
    includes = ["src/include"],
    linkstatic = 1,
    visibility = ["//visibility:public"],
)
