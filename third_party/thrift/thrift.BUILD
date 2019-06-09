load("@rules_cc//cc:defs.bzl", "cc_library")

licenses(["notice"])

cc_library(
    name = "thrift",
    srcs = glob(
        ["lib/cpp/src/thrift/**/*.cpp"],
        [
            "lib/cpp/src/thrift/windows/**",
            "lib/cpp/src/thrift/qt/**",
        ],
    ),
    hdrs = glob([
        "lib/cpp/src/thrift/**/*.h",
        "lib/cpp/src/thrift/**/*.tcc",
    ]),
    copts = [
        "-Ilib/cpp/src/",
    ],
    includes = ["lib/cpp/src"],
    visibility = ["//visibility:public"],
    deps = [
        "@//third_party/thrift/extra:config",
        "@boost//:algorithm",
        "@boost//:locale",
        "@boost//:noncopyable",
        "@boost//:numeric_conversion",
        "@boost//:scoped_array",
        "@boost//:shared_array",
        "@boost//:smart_ptr",
        "@boost//:tokenizer",
        "@com_github_libevent_libevent//:libevent",
        "@zlib",
    ],
)
