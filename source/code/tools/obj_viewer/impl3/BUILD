package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hdrs = glob(
    include = [
        "*.hpp",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "*.cpp",
    ],
    exclude = [
        "main.cpp",
    ],
)

cc_library(
    name = "impl_lib",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
        "-DGL_GLEXT_PROTOTYPES",
    ],
    includes = [
        ".",
    ],
    linkopts = [
        # "-lGLEW",
        # "-GL",
        # "-lGLU",
        # "-lglut",
    ],
    deps = [
        "//code/utilities/graphics/glx:x11_to_opengl_binder",
        "//code/utilities/graphics/x11/main_state:setup_display_settings",
        "//code/utilities/graphics/x11/main_state:x11_main_state_creator",
        "@system//:EGL",
        "@system//:GL",
        "@system//:GLEW",
        "@system//:GLU",
        "@system//:GLX",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
        "@system//:OpenGL",
        "@system//:SDL",
        "@system//:SDL2",
        "@system//:SDL2_hdrs",
        "@system//:SDL_hdrs",
        "@system//:SDL_image",
        "@system//:X11",
        "@system//:X11_hdrs",
        "@system//:Xi",
        "@system//:glut",
        "@xscreensaver//:vroot",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGLEW",
        "-GL",
        "-lGLU",
        "-lglut",
    ],
    deps = [
        # "@GL",
        #"@glut",
        # "@x11",
        ":impl_lib",
        "//code/utilities/image:stb_image",
        "//code/utilities/data_structures/vector:vector3f",
        "//code/utilities/data_structures/matrix:matrix4x4f",
        #"@system//:GLEW_hdrs",
        "@system//:GLEW",
        "@system//:GL_hdrs",
        #"@system//:GL_hdr",
        "@system//:GL",
        #"@system//OpenGL",
        #"@system//:GLU_hdrs",
        "@system//:GLU",
        "@system//:KHR_hdrs",
        #"@system//:glut_hdrs",
        "@system//:glut",
        #"@system//:X11",
        #"@system//:GLX_mesa",
        #"@mesa_glu",
        #"@FreeGLUT",
        #"@mesa",
        "@tinyobjloader",
        "@glm",
        #"@xcb",
    ],
)
