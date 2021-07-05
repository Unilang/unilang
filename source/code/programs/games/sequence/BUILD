package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/cpp:main.bzl", "cpp_main")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(
    name = "task_executer",
    deps = [
        "//code/utilities/formats/html:basic_html_template_getter",
        "//code/utilities/image:data_uri_getter",
        "//code/utilities/program/call:lib",
        "//code/utilities/assets:playing_card",
        "@boost//:algorithm",
        "@boost//:asio",
        "@boost//:optional",
        "@crow",
    ],
)

cpp_main(
    name = "sequence",
    deps = [
        "//code/programs/games/sequence:task_executer",
        "//code/utilities/program/call:lib",
        "@boost//:algorithm",
        "@boost//:asio",
        "@boost//:optional",
        "@crow",
    ],
)
