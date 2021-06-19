load("//bazel/rules/cpp:gtest.bzl", "gtest")

package(
    default_visibility = ["//visibility:public"],
)

#A user can accidentally link an object with a main() function.
#The linker chooses it instead of the gtest main which is confusing.
#These targets are test this and see how to prevent it.

#https://github.com/bazelbuild/bazel/issues/6238
# This is just a reflection of the fact that Bazel links binaries dynamically by default and the Linux dynamic linking behavior.
# If you pass --dynamic_mode=off or set linkstatic = True in the cc_test rules, the linker will fail.

#main library
cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
)

#main program
cc_binary(
    name = "main2",
    srcs = ["main2.cpp"],
)

#normal test
gtest(
    name = "main",
    deps = [
        ":lib",
        ":main2",
    ],
)

#injected test
cc_test(
    name = "test",
    srcs = [
        "lib.hpp",
        "main.cpp",
        "main2.cpp",
    ],
    linkstatic = False,
    deps = [
        ":lib",
        ":main2",
        "@gtest//:main",
    ],
)
