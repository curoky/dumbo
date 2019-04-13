load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library", "cc_test")

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
    srcs = glob(["*.cc"]),
    deps = [
        ":mock_cc_proto",
        "//dumbo/utilities:catch2_main",
        "@com_github_catchorg_catch2//:catch2",
    ],
)
