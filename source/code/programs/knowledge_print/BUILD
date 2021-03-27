package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

cpp_main(
    name = "knowledge_print",
    deps = [
        "//code/programs/knowledge_print:knowledge_runner",
    ],
)

hcp(
    name = "knowledge_runner",
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/wrappers/graphviz:graphviz_image_maker",
        "//code/utilities/semiotics/knowledge:dyadic_knowledge",
        "//code/utilities/semiotics/knowledge:triadic_knowledge",
        "//code/utilities/semiotics/knowledge_builders:traffic_sign_dyadic",
        "//code/utilities/semiotics/knowledge_builders:traffic_sign_triadic",
        "//code/utilities/semiotics/to_graphviz",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
