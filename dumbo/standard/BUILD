load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "standard_test",
    srcs = glob(["**/*.cc"]),
    copts = ["-std=c++2a"],
    linkopts = ["-latomic"],
    deps = [
        "//dumbo/utilities",
        "//dumbo/utilities:catch2_main",
        "@boost//:container_hash",
        "@boost//:functional",
        "@com_github_abseil_abseil//absl/algorithm",
        "@com_github_abseil_abseil//absl/debugging:demangle_internal",
        "@com_github_facebook_folly//:folly",
    ],
)
