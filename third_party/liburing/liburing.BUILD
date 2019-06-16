load("@rules_cc//cc:defs.bzl", "cc_library")

# genrule(
#     name = "config_h",
#     srcs = [
#         "configure",
#     ] + glob(["**/*.in"]),
#     outs = ["src/include/liburing/compat.h"],
#     cmd = "./$(location configure) " +
#           "&& cp config.h $(location config.h)",
# )

cc_library(
    name = "liburing",
    srcs = glob(["src/*.c"]),
    hdrs = glob(["src/**/*.h"]),
    includes = ["src/include"],
    linkstatic = 1,
    visibility = ["//visibility:public"],
    deps = ["@//third_party/liburing/extra:compat"],
)
