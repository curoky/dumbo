workspace(name = "com_github_curoky_dumbo")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

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
