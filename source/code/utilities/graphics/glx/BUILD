package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "x11_to_opengl_bind_settings",
    deps = [
    ],
)

hcp(
    name = "x11_to_opengl_binder",
    deps = [
        "//code/utilities/graphics/glx:glx_data_getter",
        "//code/utilities/graphics/glx:glx_context_creator",
        "//code/utilities/graphics/glx:glx_fb_config_creator",
        "//code/utilities/graphics/glx:glx_visual_creator",
        "//code/utilities/graphics/glx:x11_to_opengl_bind_settings",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/graphics/glx/data:glx_data",
        "@system//:GL",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
    ],
)

hcp(
    name = "glx_data_getter",
    deps = [
        "//code/utilities/graphics/glx:glx_context_creator",
        "//code/utilities/graphics/glx:glx_fb_config_creator",
        "//code/utilities/graphics/glx:glx_visual_creator",
        "//code/utilities/graphics/glx:x11_to_opengl_bind_settings",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/graphics/glx/data:glx_data",
        "@system//:GL",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
    ],
)

hcp(
    name = "glx_fb_config_creator",
    deps = [
        "//code/utilities/graphics/glx:x11_to_opengl_bind_settings",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "@system//:GL",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
    ],
)

hcp(
    name = "glx_visual_creator",
    deps = [
        "//code/utilities/graphics/glx:x11_to_opengl_bind_settings",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "@system//:GL",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
    ],
)

hcp(
    name = "glx_context_creator",
    deps = [
        "//code/utilities/graphics/glx:x11_to_opengl_bind_settings",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "@system//:GL",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
    ],
)
