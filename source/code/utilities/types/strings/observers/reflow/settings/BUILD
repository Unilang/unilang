package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "reflow_algorithm",
    values = [
        "greedy",
        "knuth_plass",
    ],
)

hcp(name = "greedy_reflow_settings")

hcp(name = "knuth_plass_reflow_settings")

hcp(
    name = "comment_reflow_settings",
    deps = [
        "//code/utilities/types/strings/observers/reflow/settings:greedy_reflow_settings",
        "//code/utilities/types/strings/observers/reflow/settings:knuth_plass_reflow_settings",
        "//code/utilities/types/strings/observers/reflow/settings:reflow_algorithm",
    ],
)
