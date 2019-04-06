load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "libaction",
    hdrs = [
        "action.h",
    ],
)

cc_library(
    name = "cat_action",
    srcs = [
        "cat_action.cc",
    ],
    deps = [
        ":libaction",
    ],
)

cc_library(
    name = "echo_action",
    srcs = [
        "echo_action.cc",
    ],
    deps = [
        ":libaction",
    ],
)
