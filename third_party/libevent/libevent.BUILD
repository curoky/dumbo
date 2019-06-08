load("@rules_cc//cc:defs.bzl", "cc_library")

licenses(["notice"])

cc_library(
    name = "libevent",
    srcs = glob(
        [
            "*.h",
            "*.c",
        ],
        [
            "arc4random.c",  # this is a header
            "bufferevent_async.c",
            "event_iocp.c",
            "buffer_iocp.c",
            "win32select.c",
            "evthread_win32.c",
        ],
    ),
    hdrs = glob(["include/**/*.h"]) + ["arc4random.c"],
    copts = [
        "-I.",
        "-DHAVE_CONFIG_H",
        "-Wno-unused-but-set-variable",
    ],
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = [
        "@//third_party/libevent/extra:config",
        "@//third_party/libevent/extra:config-private",
        "@org_openssl//:ssl",
    ],
)
