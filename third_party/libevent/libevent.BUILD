load("@rules_cc//cc:defs.bzl", "cc_library")

licenses(["notice"])

cc_library(
    name = "libevent",
    srcs = [
        "buffer.c",
        "epoll.c",
        "evbuffer.c",
        "evdns.c",
        "evdns.h",
        "event.c",
        "event-internal.h",
        "event_tagging.c",
        "evrpc.h",
        "evrpc-internal.h",
        "evsignal.h",
        "evutil.c",
        "evutil.h",
        "http.c",
        "http-internal.h",
        "log.c",
        "log.h",
        "min_heap.h",
        "poll.c",
        "select.c",
        "signal.c",
        "strlcpy.c",
        "strlcpy-internal.h",
    ],
    hdrs = [
        "event.h",
        "evhttp.h",
    ],
    copts = [
        "-DHAVE_CONFIG_H",
        "-Wno-unused-but-set-variable",
    ],
    includes = [
        ".",
    ],
    visibility = ["//visibility:public"],
    deps = ["@//third_party/libevent/extra:config"],
)
