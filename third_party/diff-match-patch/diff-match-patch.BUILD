load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "diff-match-patch",
    srcs = ["cpp/diff_match_patch.cpp"],
    hdrs = ["cpp/diff_match_patch.h"],
    includes = ["cpp"],
    visibility = ["//visibility:public"],
    deps = ["@qt//:qt_core"],
)
