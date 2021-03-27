load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [],
    deps = [
        "//code/utilities/assets:chrome_drivers",
        "//code/utilities/filesystem/files/getting:lib",
    ],
)
