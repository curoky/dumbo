load("@rules_cc//cc:defs.bzl", "cc_test")
load("//dumbo:copts.bzl", "DUMBO_DEFAULT_LINKOPTS", "DUMBO_TEST_COPTS")

cc_test(
    name = "example",
    testonly = False,
    srcs = glob([
        "*.h",
        "*.cc",
    ]),
    copts = DUMBO_TEST_COPTS,
    linkopts = DUMBO_DEFAULT_LINKOPTS,
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_cpp_httplib//:httplib",
        "@com_github_curl//:curl",
        "@com_github_nlohmann_json//:json",
        "@com_github_restclient//:restclient",
        "@com_github_whoshuu_cpr//:cpr",
    ],
)
