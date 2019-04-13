load("@rules_cc//cc:defs.bzl", "cc_test")
load("@com_github_google_flatbuffers//:build_defs.bzl", "flatbuffer_cc_library")

flatbuffer_cc_library(
    name = "mock_flat",
    srcs = ["mock.fbs"],
)

cc_test(
    name = "type_test",
    srcs = ["type.cc"],
    deps = [
        ":mock_flat",
        "//dumbo/utilities:catch2_main",
        "@com_github_catchorg_catch2//:catch2",
    ],
)
