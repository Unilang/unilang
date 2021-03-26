package(default_visibility = ["//visibility:public"])

load("@io_bazel_rules_docker//cc:image.bzl", "cc_image")

cc_binary(
    name = "cc_binary",
    srcs = ["main.cpp"],
)

cc_image(
    name = "cc_image",
    binary = ":cc_binary",
)
