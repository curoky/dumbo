load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "openssl_example",
    srcs = glob(["*.cc"]),
    copts = ["-std=c++17"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@org_openssl//:crypto",
        "@org_openssl//:ssl",
    ],
)
