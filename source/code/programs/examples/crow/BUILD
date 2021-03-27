load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = [
        "@boost//:algorithm",
        "@boost//:asio",
        "@boost//:optional",
        "@crow",
    ],
)
