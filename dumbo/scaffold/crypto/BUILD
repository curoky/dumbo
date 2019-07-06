load("@rules_cc//cc:defs.bzl", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_test(
    name = "example",
    testonly = False,
    srcs = glob(["**/*.cc"]),
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_aappleby_murmurhash//:murmurhash",
        "@com_github_google_cityhash//:city",
        "@com_github_google_crc32c//:crc32c",
        "@org_openssl//:crypto",
        "@org_openssl//:ssl",
    ],
)
