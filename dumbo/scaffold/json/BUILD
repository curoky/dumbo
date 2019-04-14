load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "json_example",
    srcs = glob([
        "*.h",
        "*.cc",
    ]),
    copts = ["-std=c++17"],
    deps = [
        "//dumbo/utilities:catch2_main",
        "@com_github_catchorg_catch2//:catch2",
        "@com_github_cjson//:cjson",
        "@com_github_jsoncpp//:jsoncpp",
        "@com_github_nlohmann_json//:json",
        "@com_github_tencent_rapidjson//:rapidjson",
    ],
)
