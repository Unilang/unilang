load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

# cc_binary(
#    name = "bitmap",
#    srcs = ["bitmap.cpp"],
#    deps = ["@xcb","@Xau"],
# )

cc_binary(
    name = "graphics",
    srcs = ["graphics.cpp"],
    deps = [
        "@Xau",
        "@xcb",
    ],
)
