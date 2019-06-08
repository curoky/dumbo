# load("@rules_cc//cc:defs.bzl", "cc_library")

# licenses(["notice"])

# exports_files(
#     visibility = ["//visibility:public"],
# )

load("@rules_cc//cc:defs.bzl", "cc_library")

licenses(["notice"])

cc_library(
    name = "config",
    hdrs = ["event-config.h"],
    include_prefix = "event2",
    includes = ["."],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "config-private",
    hdrs = ["evconfig-private.h"],
    includes = ["."],
    visibility = ["//visibility:public"],
)
