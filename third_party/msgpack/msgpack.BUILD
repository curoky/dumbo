load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "msgpack",
    hdrs = glob(["include/**/*.hpp"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = [
        "@boost//:assert",
        "@boost//:fusion",
        "@boost//:numeric_conversion",
        "@boost//:operators",
        "@boost//:predef",
        "@boost//:preprocessor",
        "@boost//:variant",
    ],
)
