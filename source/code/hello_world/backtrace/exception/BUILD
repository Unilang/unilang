load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//code/utilities/program/common_actions/signals:all_signal_setter",
        "//code/utilities/program/common_actions/backtrace:backtrace",
        "//code/utilities/program/common_actions/backtrace:exceptions",
    ],
)
