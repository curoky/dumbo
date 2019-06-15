load("@rules_cc//cc:defs.bzl", "cc_library")

# proxygen/lib/http
genrule(
    name = "gen_http_common_headers",
    srcs = [
        "proxygen/lib/http/gen_HTTPCommonHeaders.sh",
        "proxygen/lib/http/HTTPCommonHeaders.txt",
        "proxygen/lib/utils/gen_perfect_hash_table.sh",
        "proxygen/lib/utils/perfect_hash_table_template.h",
        "proxygen/lib/utils/perfect_hash_table_template.cpp.gperf",
    ],
    outs = [
        "proxygen/lib/http/HTTPCommonHeaders.h",
        "proxygen/lib/http/HTTPCommonHeaders.cpp",
    ],
    cmd = "mkdir -p $(@D)/proxygen/lib/http/ && " +
          "$(location proxygen/lib/http/gen_HTTPCommonHeaders.sh) " +
          "$(location proxygen/lib/http/HTTPCommonHeaders.txt) " +
          "external/com_github_facebook_proxygen " +
          "$(@D)/proxygen/lib/http/ ",
)

# proxygen/lib/utils
genrule(
    name = "gen_trace_event_constants",
    srcs = [
        "proxygen/lib/utils/gen_trace_event_constants.py",
        "proxygen/lib/utils/samples/TraceFieldType.txt",
        "proxygen/lib/utils/samples/TraceEventType.txt",
    ],
    outs = [
        "proxygen/lib/utils/TraceEventType.h",
        "proxygen/lib/utils/TraceEventType.cpp",
        "proxygen/lib/utils/TraceFieldType.h",
        "proxygen/lib/utils/TraceFieldType.cpp",
    ],
    cmd = "mkdir -p $(@D)/proxygen/lib/utils/ && " +
          "python $(location proxygen/lib/utils/gen_trace_event_constants.py) " +
          "--output_type=cpp " +
          "--input_files=$(location proxygen/lib/utils/samples/TraceFieldType.txt),$(location proxygen/lib/utils/samples/TraceEventType.txt) " +
          "--output_scope=proxygen " +
          "--header_path=proxygen/lib/utils " +
          "--fbcode_dir=external/com_github_facebook_proxygen " +
          "--install_dir=$(@D)/proxygen/lib/utils",
)

cc_library(
    name = "proxygen",
    srcs = glob(
        [
            "proxygen/external/**/*.cpp",
            "proxygen/lib/http/**/*.cpp",
            "proxygen/lib/utils/**/*.cpp",
        ],
        [
            "proxygen/lib/http/**/HQ*.cpp",
            "proxygen/lib/http/stats/*.cpp",
            "proxygen/lib/http/codec/compress/experimental/**",
            "proxygen/lib/http/SynchronizedLruQuicPskCache*.cpp",
            "proxygen/**/test/**/*.cpp",
            "proxygen/**/example/**/*.cpp",
        ],
    ) + [
        ":gen_http_common_headers",
        ":gen_trace_event_constants",
    ],
    hdrs = glob(["proxygen/**/*.h"]),
    copts = [
        "-std=c++17",
        "-Iexternal/com_github_google_double_conversion",
    ],
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        "@boost//:iostreams",
        "@com_github_facebook_folly//:folly",
        "@com_github_facebook_wangle//:wangle",
        "@com_github_google_double_conversion//:double-conversion",
    ],
)
