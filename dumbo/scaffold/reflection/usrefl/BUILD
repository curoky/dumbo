load("@rules_cc//cc:defs.bzl", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_test(
    name = "example",
    testonly = False,
    srcs = glob(["*.cc"]),
    copts = DUMBO_TEST_COPTS + [
        "-DUBPA_USREFL_USE_NAMEOF",
    ],
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_neargye_nameof//:nameof",
        "@com_github_ubpa_usrefl//:usrefl",
    ],
)
