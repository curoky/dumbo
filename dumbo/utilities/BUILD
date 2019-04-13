load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "utilities",
    hdrs = glob(["*.h"]),
    visibility = ["//visibility:public"],
    deps = ["@com_github_google_glog//:glog"],
)

cc_library(
    name = "catch2_main",
    srcs = ["catch2_main.cc"],
    visibility = ["//visibility:public"],
    deps = [
        "@com_github_catchorg_catch2//:catch2",
    ],
)
