load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "example",
    srcs = glob(["*.cc"]),
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_cpp_peglib//:peglib",
    ],
)
