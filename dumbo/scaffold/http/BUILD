load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "http_example",
    srcs = glob([
        "*.h",
        "*.cc",
    ]),
    copts = ["-std=c++17"],
    linkopts = ["-lpthread"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_cpp_httplib//:httplib",
        "@com_github_curl//:curl",
        "@com_github_nlohmann_json//:json",
        "@com_github_restclient//:restclient",
        "@com_github_whoshuu_cpr//:cpr",
    ],
)
