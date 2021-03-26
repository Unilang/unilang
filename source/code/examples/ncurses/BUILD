load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "key_press",
    srcs = ["key_press.cpp"],
    deps = ["@ncurses"],
)

cc_binary(
    name = "arrow_keys",
    srcs = ["arrow_keys.cpp"],
    deps = ["@ncurses"],
)
