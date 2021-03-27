load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "two_inf",
)

cpp_main(
    name = "boost_thread_pool",
    deps = ["@boost//:asio"],
)

cpp_main(
    name = "boost_thread_pool2",
    deps = [
        "//code/utilities/execution:thread_pool_getter",
        "//code/utilities/execution:thread_pool_loop",
        "@boost//:asio",
    ],
)
