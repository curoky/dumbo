load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "cpr",
    srcs = glob(["cpr/*.cpp"]),
    hdrs = glob(["include/cpr/*.h"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = ["@com_github_curl//:curl"],
)
