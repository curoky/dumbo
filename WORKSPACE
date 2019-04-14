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
    branch = "master",
    remote = "https://github.com/catchorg/Catch2.git",
)

git_repository(
    name = "com_github_gflags_gflags",
    branch = "master",
    remote = "https://github.com/gflags/gflags.git",
)

http_archive(
    name = "zlib",
    build_file = "@//:third_party/zlib/zlib.BUILD",
    sha256 = "629380c90a77b964d896ed37163f5c3a34f6e6d897311f1df2a7016355c45eff",
    strip_prefix = "zlib-1.2.11",
    urls = ["https://github.com/madler/zlib/archive/v1.2.11.tar.gz"],
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
