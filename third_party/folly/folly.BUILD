load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "folly",
    srcs = [
        "folly/Demangle.cpp",
        "folly/FileUtil.cpp",
        "folly/ScopeGuard.cpp",
        "folly/detail/Demangle.cpp",
        "folly/lang/CString.cpp",
        "folly/net/NetOps.cpp",
        "folly/system/HardwareConcurrency.cpp",
    ],
    hdrs = glob(
        [
            "folly/*.h",
            "folly/**/*.h",
            "folly/**/**/*.h",
        ],
    ),
    copts = ["-std=c++14"],
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        "@//third_party/folly:config",
        "@boost//:preprocessor",
        "@libiberty",
    ],
)
