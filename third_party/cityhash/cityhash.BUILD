load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "city",
    srcs = [
        "src/city.cc",
    ],
    hdrs = [
        "src/city.h",
        "src/citycrc.h",
    ],
    includes = ["src/"],
    visibility = ["//visibility:public"],
    deps = ["@//third_party/cityhash/extra:config"],
)
