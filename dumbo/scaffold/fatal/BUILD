load("@rules_cc//cc:defs.bzl", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS")

cc_test(
    name = "example",
    testonly = False,
    srcs = glob(["*.cc"]),
    copts = [
        "-g",
        "-fno-omit-frame-pointer",
        # "-fsanitize=address",
        "-std=c++17",
    ],
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_facebook_fatal//:fatal",
    ],
)
