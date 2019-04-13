load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "example",
    srcs = ["msgpack.cc"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_catchorg_catch2//:catch2",
        "@com_github_msgpack_msgpack//:msgpack",
    ],
)
