package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp_and_hcp_pos.bzl", "hcp_and_hcp_pos")

cpp_object(
    name = "stb_image",
    deps = [
        "@stb",
    ],
)

hcp(
    name = "stb_image_set_settings",
    deps = [
    ],
)

hcp(
    name = "texture_loader",
    deps = [
        "//code/utilities/graphics/opengl/loader:opengl_loaders",
        "//code/utilities/image:stb_image",
        "//code/utilities/streams/filestreams:lib",
        "@imgui//:imgui_sdl_opengl3",
        "@system//:KHR_hdrs",
    ],
)

hcp(
    name = "stb_image_setter",
    deps = [
        "//code/utilities/data_structures/graphics/image:positioned_image_data",
        "//code/utilities/image:stb_image",
        "//code/utilities/image:stb_image_set_settings",
        "//code/utilities/image:texture_loader",
        "//code/utilities/streams/filestreams:lib",
    ],
)

hcp(
    name = "stb_animated_image_setter",
    deps = [
        "//code/utilities/data_structures/graphics/image:positioned_animated_image_data",
        "//code/utilities/image:stb_image",
        "//code/utilities/image:stb_image_set_settings",
        "//code/utilities/image:texture_loader",
        "//code/utilities/streams/filestreams:lib",
    ],
)

hcp(
    name = "data_uri_getter",
    deps = [
        "//code/utilities/program/call:lib",
    ],
)
