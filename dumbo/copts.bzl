"""dumbo specific copts.
"""

DUMBO_DEFAULT_COPTS = [
    "-g",
    "-fno-omit-frame-pointer",
    # "-fsanitize=address",
    "-std=c++2a",
]

DUMBO_TEST_COPTS = DUMBO_DEFAULT_COPTS + [
    "-O0",
]

DUMBO_DEFAULT_LINKOPTS = [
    "-fsanitize=address",
    "-latomic",
    "-lpthread",
]
