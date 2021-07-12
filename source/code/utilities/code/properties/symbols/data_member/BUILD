package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "token_data_member_state_attribute_settings")

hcp(
    name = "token_data_member_attribute_settings",
    deps = [
        "token_data_member_state_attribute_settings",
        "//code/utilities/code/properties/symbols/shared:token_access_attribute_settings",
    ],
)
