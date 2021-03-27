load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
)

cpp_main(
    name = "better",
    deps = [
        "//code/utilities/ncurses:scoped_getch",
        "@getch",
    ],
)

# cc_binary(
#     name = "getkey",
#     srcs = ["getkey.cpp"],
#     deps = ["@getch//:getch"],
# )
