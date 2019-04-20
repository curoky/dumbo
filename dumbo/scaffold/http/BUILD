load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "http_example",
    srcs = glob(["*.cc"]),
    copts = ["-std=c++17"],
    linkopts = ["-lpthread"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_cpp_httplib//:httplib",
        "@com_github_nlohmann_json//:json",
    ],
)
