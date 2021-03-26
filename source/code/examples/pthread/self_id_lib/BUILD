load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = [],
    deps = [
        ":lib",
    ],
)
