package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "key_detector",
    deps = [
        "//code/programs/ide/settings/data:ide_settings",
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/peripheral/keyboard/state:key_state",
        "@imgui//:imgui_sdl_opengl3",
    ],
)
