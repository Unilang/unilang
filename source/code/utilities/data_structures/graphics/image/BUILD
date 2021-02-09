package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

hcp_and_hcp_pos(
    name = "image_data",
    deps = [
        "//code/utilities/graphics/opengl/loader:opengl_loaders",
        "//code/utilities/image:stb_image",
        "@imgui//:imgui_sdl_opengl3",
        "@system//:KHR_hdrs",
    ],
)

hcp_and_hcp_pos(
    name = "animated_image_data",
    deps = [
        "//code/utilities/graphics/opengl/loader:opengl_loaders",
        "//code/utilities/image:stb_image",
        "@imgui//:imgui_sdl_opengl3",
        "@system//:KHR_hdrs",
    ],
)

hcp_and_hcp_pos(
    name = "texture",
    deps = [
        "//code/utilities/graphics/opengl/loader:opengl_loaders",
        "//code/utilities/image:stb_image",
        "@imgui//:imgui_sdl_opengl3",
        "@system//:KHR_hdrs",
    ],
)
