load("@rules_cc//cc:defs.bzl", "cc_proto_library", "cc_test")
load("@rules_proto//proto:defs.bzl", "proto_library")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

proto_library(
    name = "mock_proto",
    srcs = ["mock.proto"],
    deps = ["@com_google_protobuf//:any_proto"],
)

cc_proto_library(
    name = "mock_cc_proto",
    deps = [":mock_proto"],
)

cc_test(
    name = "type_test",
    testonly = False,
    srcs = glob(["*.cc"]),
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        ":mock_cc_proto",
        "//dumbo/utilities:catch2_main",
    ],
)
