"""dumbo specific copts.
"""

DUMBO_DEFAULT_COPTS = [
    "-g",
    "-fno-omit-frame-pointer",
    "-fsanitize=address",
    "-std=c++2a",

    # for lldb
    # https://stackoverflow.com/questions/58578615/cannot-inspect-a-stdstring-variable-in-lldb
    # "-fstandalone-debug",
]

DUMBO_TEST_COPTS = DUMBO_DEFAULT_COPTS + [
    "-O0",
]

DUMBO_DEFAULT_LINKOPTS = [
    "-fsanitize=address",
    "-latomic",
    "-lpthread",
]
