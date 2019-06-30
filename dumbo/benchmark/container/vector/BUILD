load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "vector_bm",
    srcs = ["drop-in.cc"],
    copts = [
        "-O2",
        "-DNDEBUG",
        "-std=c++17",
    ],
    deps = [
        "@com_github_abseil_abseil//absl/container:inlined_vector",
        "@com_github_facebook_folly//:folly",
        "@com_github_google_benchmark//:benchmark",
    ],
)
