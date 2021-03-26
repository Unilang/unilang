load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = [
        "//code/utilities/graphics/imgui/loop:mechanics",
        "//code/utilities/graphics/sdl:sdl_init_settings",
        "@imgui//:imgui_sdl_opengl3",
    ],
)
