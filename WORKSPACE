workspace(name = "com_github_curoky_dumbo")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "rules_3rd",
    branch = "master",
    # branch = "dev",
    remote = "https://github.com/curoky/rules_cc",
)

# local_repository(
#     name = "rules_3rd",
#     path = "/home/curoky/repos/cpp/rules_cc",
# )

load("@rules_3rd//:defs.bzl", "register")

register()

load("@rules_3rd//:load.bzl", "loads")

loads()

git_repository(
    name = "com_github_google_benchmark_O2",
    branch = "master",
    # patch_args = ["-p1"],
    # patches = [
    #     "@//:third_party/google_benchmark/force_release.patch",  # -O2 -DNDEBUG
    # ],
    remote = "https://github.com/google/benchmark.git",
)

# local_repository(
#     name = "com_github_curoky_iwyu_imp",
#     path = "/home/curoky/repos/cpp/iwyu-imp",
# )

git_repository(
    name = "com_github_curoky_iwyu_imp",
    branch = "master",
    remote = "https://github.com/curoky/iwyu-imp.git",
)
