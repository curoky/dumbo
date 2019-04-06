load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "action_service",
    srcs = [
        "action_service.cc",
    ],
    linkopts = [
        "-ldl",
    ],
    deps = [
        "//dumbo/magic/dlopen_plugin/plugin:libaction",
    ],
)
