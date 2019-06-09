load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "cjson",
    srcs = glob([
        "*.h",
        "*.c",
    ]),
    hdrs = glob(["*.h"]),
    include_prefix = "cjson",
    includes = ["."],
    visibility = ["//visibility:public"],
)
