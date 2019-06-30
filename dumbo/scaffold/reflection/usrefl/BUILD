load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "usrefl_example",
    testonly = False,
    srcs = glob(["*.cc"]),
    copts = [
        "-std=c++17",
        "-DUBPA_USREFL_USE_NAMEOF",
    ],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_neargye_nameof//:nameof",
        "@com_github_ubpa_usrefl//:usrefl",
    ],
)
