load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "openssl_example",
    srcs = glob(["*.cc"]),
    copts = ["-std=c++17"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_catchorg_catch2//:catch2",
        "@org_openssl//:crypto",
        "@org_openssl//:ssl",
    ],
)
