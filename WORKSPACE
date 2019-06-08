workspace(name = "com_github_curoky_dumbo")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_python",
    sha256 = "b5668cde8bb6e3515057ef465a35ad712214962f0b3a314e551204266c7be90c",
    strip_prefix = "rules_python-0.0.2",
    url = "https://github.com/bazelbuild/rules_python/releases/download/0.0.2/rules_python-0.0.2.tar.gz",
)

git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "1e3a69bf2d5cd10c34b74f066054cd335d033d71",
    remote = "https://github.com/nelhage/rules_boost",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

# https://github.com/nelhage/rules_boost/blob/master/BUILD.boost
boost_deps()

git_repository(
    name = "com_github_abseil_abseil",
    branch = "master",
    remote = "https://github.com/abseil/abseil-cpp",
)

git_repository(
    # [depend]: com_github_gflags_gflags
    name = "com_github_google_glog",
    branch = "master",
    remote = "https://github.com/google/glog.git",
)

git_repository(
    name = "com_github_catchorg_catch2",
    branch = "v2.x",
    remote = "https://github.com/catchorg/Catch2.git",
)

git_repository(
    name = "com_github_gflags_gflags",
    branch = "master",
    remote = "https://github.com/gflags/gflags.git",
)

# http_archive(
#     name = "zlib",
#     build_file = "@//:third_party/zlib/zlib.BUILD",
#     sha256 = "629380c90a77b964d896ed37163f5c3a34f6e6d897311f1df2a7016355c45eff",
#     strip_prefix = "zlib-1.2.11",
#     urls = ["https://github.com/madler/zlib/archive/v1.2.11.tar.gz"],
# )

new_git_repository(
    name = "zlib",
    branch = "master",
    build_file = "@//:third_party/zlib/zlib.BUILD",
    remote = "https://github.com/madler/zlib.git",
)

git_repository(
    # [depend]: zlib
    name = "com_google_protobuf",
    branch = "master",
    remote = "https://github.com/protocolbuffers/protobuf",
)

git_repository(
    name = "com_github_google_flatbuffers",
    branch = "master",
    remote = "https://github.com/google/flatbuffers.git",
)

new_git_repository(
    name = "com_github_msgpack_msgpack",
    branch = "cpp_master",
    build_file_content = """
cc_library(
    name = "msgpack",
    hdrs = glob(
        [
            "include/*.hpp",
            "include/**/*.hpp",
            "include/**/**/*.hpp",
            "include/**/**/**/*.hpp",
        ],
    ),
    deps = [
        "@boost//:predef",
        "@boost//:assert",
        "@boost//:fusion",
        "@boost//:variant",
        "@boost//:operators",
        "@boost//:preprocessor",
        "@boost//:numeric_conversion",
    ],
    includes = ["include"],
    visibility = ["//visibility:public"],
)
""",
    remote = "https://github.com/msgpack/msgpack-c",
)

git_repository(
    name = "com_github_google_benchmark",
    branch = "master",
    remote = "https://github.com/google/benchmark.git",
)

new_local_repository(
    name = "libiberty",
    build_file_content = """
cc_library(
    name = "libiberty",
    srcs = ["lib/x86_64-linux-gnu/libiberty.a"],
    hdrs = glob(["include/libiberty/*.h"]),
    visibility = ["//visibility:public"],
    includes = ["include/libiberty/"],
)
    """,
    path = "/usr",
)

new_local_repository(
    name = "brew_libiberty",
    build_file_content = """
cc_library(
    name = "libiberty",
    srcs = ["lib/gcc/10/libiberty.a"],
    hdrs = glob(["include/libiberty/*.h"]),
    visibility = ["//visibility:public"],
    includes = ["include/libiberty/"],
)
    """,
    path = "/home/linuxbrew/.linuxbrew/Cellar/gcc10/10.2.0",
)

new_git_repository(
    name = "com_github_facebook_folly",
    branch = "master",
    build_file = "@//:third_party/folly/folly.BUILD",
    remote = "https://github.com/facebook/folly.git",
)

new_git_repository(
    name = "com_github_facebookincubator_fizz",
    branch = "master",
    build_file = "@//:third_party/fizz/fizz.BUILD",
    remote = "https://github.com/facebookincubator/fizz.git",
)

new_git_repository(
    name = "com_github_facebook_proxygen",
    branch = "v2020.10.19.00",
    build_file = "@//:third_party/proxygen/proxygen.BUILD",
    remote = "https://github.com/facebook/proxygen.git",
)

new_git_repository(
    name = "com_github_facebook_wangle",
    branch = "v2020.10.19.00",
    build_file = "@//:third_party/wangle/wangle.BUILD",
    remote = "https://github.com/facebook/wangle.git",
)

new_git_repository(
    name = "com_github_parallel_hashmap",
    branch = "master",
    build_file = "@//:third_party/parallel-hashmap/parallel-hashmap.BUILD",
    remote = "https://github.com/greg7mdp/parallel-hashmap",
)

git_repository(
    name = "com_github_google_gtest",
    branch = "master",
    remote = "https://github.com/google/googletest.git",
)

git_repository(
    name = "com_justbuchanan_rules_qt",
    remote = "https://github.com/justbuchanan/bazel_rules_qt.git",
    branch = "master",
)

new_local_repository(
    name = "qt",
    build_file = "@com_justbuchanan_rules_qt//:qt.BUILD",
    path = "/usr/include/x86_64-linux-gnu/qt5",
    # path = "/home/linuxbrew/.linuxbrew/opt/qt/include",
)

new_git_repository(
    name = "com_github_google_diff_match_patch",
    branch = "master",
    patch_cmds = [
        'sed -i -e "s/<QtCore>/<QtCore\/QtCore>/g" cpp/diff_match_patch.cpp',
        'sed -i -e "s/toAscii()/toLatin1()/g" cpp/diff_match_patch.cpp',
    ],
    build_file_content = """
cc_library(
    name = "diff-match-patch",
    hdrs = ["cpp/diff_match_patch.h"],
    srcs = ["cpp/diff_match_patch.cpp"],
    deps = ["@qt//:qt_core"],
    includes = ["cpp"],
    visibility = ["//visibility:public"],
)
""",
    remote = "https://github.com/google/diff-match-patch.git",
)

new_git_repository(
    name = "com_github_nlohmann_json",
    branch = "master",
    build_file = "@//:third_party/nlohmann_json/json.BUILD",
    remote = "https://github.com/nlohmann/json",
)

new_git_repository(
    name = "com_github_cjson",
    branch = "master",
    build_file = "@//:third_party/cjson/cjson.BUILD",
    remote = "https://github.com/DaveGamble/cJSON",
)

new_git_repository(
    name = "com_github_tencent_rapidjson",
    branch = "master",
    build_file = "@//:third_party/rapidjson/rapidjson.BUILD",
    remote = "https://github.com/Tencent/rapidjson",
)

new_git_repository(
    name = "com_github_jsoncpp",
    branch = "master",
    build_file = "@//:third_party/jsoncpp/jsoncpp.BUILD",
    remote = "https://github.com/open-source-parsers/jsoncpp.git",
)

new_git_repository(
    name = "com_github_apache_thrift",
    branch = "0.13.0",
    build_file = "@//:third_party/thrift/thrift.BUILD",
    remote = "https://github.com/apache/thrift.git",
)

http_archive(
    name = "com_github_curl",
    build_file = "@//:third_party/curl/curl.BUILD",
    sha256 = "01ae0c123dee45b01bbaef94c0bc00ed2aec89cb2ee0fd598e0d302a6b5e0a98",
    # branch = "curl-7_69_1",
    strip_prefix = "curl-7.69.1",
    urls = ["https://curl.haxx.se/download/curl-7.69.1.tar.gz"],
)

# new_git_repository(
#     name = "com_github_curl",
#     # branch = "curl-7_69_1",
#     commit="b81e0b07784dc4c1e8d0a86194b9d28776d071c0",
#     build_file = "@//:third_party/curl/curl.BUILD",
#     remote = "https://github.com/curl/curl.git",
# )

new_git_repository(
    name = "com_github_cpp_httplib",
    branch = "master",
    build_file = "@//:third_party/cpp-httplib/cpp-httplib.BUILD",
    remote = "https://github.com/yhirose/cpp-httplib.git",
)

new_git_repository(
    name = "com_github_whoshuu_cpr",
    branch = "master",
    build_file = "@//:third_party/cpr/cpr.BUILD",
    remote = "https://github.com/whoshuu/cpr.git",
)

# http_archive(
#     name = "boringssl",
#     build_file = "@//:third_party/boringssl/boringssl.BUILD",
#     sha256 = "a9c3b03657d507975a32732f04563132b4553c20747cec6dc04de475c8bdf29f",
#     strip_prefix = "boringssl-80ca9f9f6ece29ab132cce4cf807a9465a18cfac",
#     # system_build_file = clean_dep("//third_party/systemlibs:boringssl.BUILD"),
#     urls = [
#         "https://github.com/google/boringssl/archive/80ca9f9f6ece29ab132cce4cf807a9465a18cfac.tar.gz",
#     ],
# )


git_repository(
    name = "com_github_google_boringssl",
    branch = "master-with-bazel",
    remote = "https://github.com/google/boringssl.git",
)

http_archive(
    name = "org_openssl",
    build_file = "@//:third_party/openssl/openssl.BUILD",
    sha256 = "ddb04774f1e32f0c49751e21b67216ac87852ceb056b75209af2443400636d46",
    strip_prefix = "openssl-1.1.1g",
    urls = ["https://www.openssl.org/source/openssl-1.1.1g.tar.gz"],
)

http_archive(
    name = "com_github_google_snappy",
    build_file = "@//:third_party/snappy/snappy.BUILD",
    strip_prefix = "snappy-ea660b57d65d68d521287c903459b6dd3b2804d0",
    urls = ["https://github.com/google/snappy/archive/ea660b57d65d68d521287c903459b6dd3b2804d0.tar.gz"],
)

http_archive(
    name = "com_github_facebook_zstd",
    build_file = "@//:third_party/zstd/zstd.BUILD",
    sha256 = "188ba167e7a507b545c5f455af4afe3a34b2cee5551949fa000a8218ff4fda67",
    strip_prefix = "zstd-bd2740f3476c46b9f69d59e49e7391c2762e04b3",
    urls = ["https://github.com/facebook/zstd/archive/bd2740f3476c46b9f69d59e49e7391c2762e04b3.tar.gz"],
)

new_git_repository(
    name = "com_github_google_crc32c",
    branch = "master",
    build_file = "@//:third_party/crc32c/crc32c.BUILD",
    remote = "https://github.com/google/crc32c.git",
)

new_git_repository(
    name = "com_github_fmtlib_fmt",
    branch = "master",
    build_file = "@//:third_party/fmtlib/fmt.BUILD",
    remote = "https://github.com/fmtlib/fmt.git",
)

new_git_repository(
    name = "com_github_gabime_spdlog",
    branch = "v1.x",
    build_file = "@//:third_party/spdlog/spdlog.BUILD",
    remote = "https://github.com/gabime/spdlog.git",
)

git_repository(
    name = "com_github_google_double_conversion",
    branch = "master",
    remote = "https://github.com/google/double-conversion",
)

new_git_repository(
    name = "com_github_cameron314_concurrentqueue",
    branch = "master",
    build_file = "@//:third_party/concurrentqueue/concurrentqueue.BUILD",
    remote = "https://github.com/cameron314/concurrentqueue",
)

new_git_repository(
    name = "com_github_libevent_libevent",
    branch = "5df3037d10556bfcb675bc73e516978b75fc7bc7", # release-2.1.12-stable
    build_file = "@//:third_party/libevent/libevent.BUILD",
    remote = "https://github.com/libevent/libevent",
)

new_git_repository(
    name = "com_github_cameron314_readerwriterqueue",
    branch = "master",
    build_file = "@//:third_party/readerwriterqueue/readerwriterqueue.BUILD",
    remote = "https://github.com/cameron314/readerwriterqueue",
)

new_git_repository(
    name = "com_github_taskflow_taskflow",
    branch = "master",
    build_file = "@//:third_party/taskflow/taskflow.BUILD",
    remote = "https://github.com/taskflow/taskflow",
)

new_git_repository(
    name = "com_github_aappleby_murmurhash",
    branch = "master",
    build_file = "@//:third_party/murmurhash/murmurhash.BUILD",
    remote = "https://github.com/aappleby/smhasher",
)

new_git_repository(
    name = "com_github_google_cityhash",
    branch = "master",
    build_file = "@//:third_party/cityhash/cityhash.BUILD",
    remote = "https://github.com/google/cityhash",
)

new_git_repository(
    name = "com_github_ubpa_usrefl",
    branch = "master",
    build_file = "@//:third_party/usrefl/usrefl.BUILD",
    remote = "https://github.com/Ubpa/USRefl",
)

new_git_repository(
    name = "com_github_neargye_nameof",
    branch = "master",
    build_file = "@//:third_party/nameof/nameof.BUILD",
    remote = "https://github.com/Neargye/nameof",
)

new_git_repository(
    name = "com_github_restclient",
    branch = "master",
    build_file = "@//:third_party/restclient/restclient.BUILD",
    remote = "https://github.com/mrtazz/restclient-cpp",
)

new_local_repository(
    name = "tbb",
    build_file_content = """
cc_library(
    name = "tbb",
    srcs = ["lib/libtbb.so.2"],
    hdrs = glob(["include/**/*.h"]),
    visibility = ["//visibility:public"],
    includes = ["include"],
)
    """,
    path = "/home/linuxbrew/.linuxbrew/opt/tbb",
)
