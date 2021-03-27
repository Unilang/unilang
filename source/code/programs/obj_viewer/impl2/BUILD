package(
    default_visibility = ["//visibility:public"],
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

# clang++ prenis/main.cpp -lGLEW -lGL -lGLU -lglut
#-lGLEW -lGL -lGLU -lglut
