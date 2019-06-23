load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "example",
    testonly = False,
    srcs = ["msgpack.cc"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_msgpack_msgpack//:msgpack",
    ],
)
