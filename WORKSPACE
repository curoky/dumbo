workspace(name = "com_github_curoky_dumbo")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_github_nelhage_rules_boost",
    branch = "master",
    remote = "https://github.com/nelhage/rules_boost.git",
)

git_repository(
    name = "rules_python",
    branch = "master",
    remote = "https://github.com/bazelbuild/rules_python.git",
)

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

load("@rules_3rd//:defs.bzl", "load_all_repo")

load_all_repo()
