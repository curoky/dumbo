load("@rules_cc//cc:defs.bzl", "cc_library")

licenses(["notice"])

exports_files(["LICENSE"])

package(
    default_visibility = ["//visibility:public"],
)

genrule(
    name = "snappy_stubs_public_h",
    srcs = ["@//third_party/snappy/extra:snappy-stubs-public.h"],
    outs = ["snappy-stubs-public.h"],
    cmd = "cp $< $@",
)

genrule(
    name = "config_h",
    srcs = ["@//third_party/snappy/extra:config.h"],
    outs = ["config.h"],
    cmd = "cp $< $@",
)

cc_library(
    name = "snappy",
    srcs = glob(
        ["**/*.cc"],
        exclude = [
            "snappy-test.cc",
            "snappy_unittest.cc",
        ],
    ),
    hdrs = glob(
        ["**/*.h"],
        exclude = ["snappy-test.h"],
    ) + [
        ":config_h",
        ":snappy_stubs_public_h",
    ],
    defines = ["HAVE_CONFIG_H"],
    includes = ["."],
)
