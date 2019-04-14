# copy from https://github.com/tensorflow/tensorflow/blob/master/third_party/jsoncpp.BUILD
load("@rules_cc//cc:defs.bzl", "cc_library")

licenses(["unencumbered"])  # Public Domain or MIT

exports_files(["LICENSE"])

cc_library(
    name = "jsoncpp",
    srcs = glob([
        "include/json/*.h",
        "src/lib_json/*.h",
        "src/lib_json/*.cpp",
    ]),
    hdrs = glob([
        "include/json/*.h",
    ]),
    copts = [
        "-DJSON_USE_EXCEPTION=0",
        "-DJSON_HAS_INT64",
    ],
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = [":private"],
)

cc_library(
    name = "private",
    textual_hdrs = ["src/lib_json/json_valueiterator.inl"],
)
