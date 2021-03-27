load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = [
        "//code/utilities/graphics/opengl/loader:opengl_loader",
        "@imgui//:imgui_sdl_opengl3",
    ],
)
