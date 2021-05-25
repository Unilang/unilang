load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "gen",
    deps = [
        "@openssl//:crypto",
        "@secp256k1//:lib",
    ],
)
