load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "taskflow",
    hdrs = glob(
        [
            "taskflow/*.hpp",
            "taskflow/**/*.hpp",
            "taskflow/**/**/*.hpp",
        ],
    ),
    includes = ["."],
    visibility = ["//visibility:public"],
)
