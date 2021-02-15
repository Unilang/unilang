package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

cpp_object(
    name = "image",
    deps = [
        "//code/utilities/data_structures/position",
        "//code/utilities/image:stb_image",
    ],
)

cpp_object(
    name = "positioned_image",
    deps = [
        "//code/utilities/data_structures/position",
        "//code/utilities/image:stb_image",
        "@imgui//:imgui_sdl_opengl3",
        "@system//:KHR_hdrs",
    ],
)
