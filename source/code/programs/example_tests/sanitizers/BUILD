load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_test")

cc_test(
    name = "asan_test",
    srcs = ["asan_test.cc"],
    tags = ["manual"],
)

cc_test(
    name = "tsan_test",
    srcs = ["tsan_test.cc"],
    tags = ["manual"],
)

cc_test(
    name = "msan_test",
    srcs = ["msan_test.cc"],
    tags = ["manual"],
)

cc_test(
    name = "ubsan_test",
    srcs = ["ubsan_test.cc"],
    tags = ["manual"],
)

cc_binary(
    name = "asan_fuzz_test",
    srcs = ["asan_fuzz_test.cc"],
    tags = ["manual"],
)
