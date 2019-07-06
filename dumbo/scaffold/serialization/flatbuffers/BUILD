load("@com_github_google_flatbuffers//:build_defs.bzl", "flatbuffer_cc_library")
load("@rules_cc//cc:defs.bzl", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

flatbuffer_cc_library(
    name = "mock_flat",
    srcs = ["mock.fbs"],
)

cc_test(
    name = "type_test",
    testonly = False,
    srcs = ["type.cc"],
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        ":mock_flat",
        "//dumbo/utilities:catch2_main",
    ],
)
