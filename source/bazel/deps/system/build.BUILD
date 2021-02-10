package(
    default_visibility = ["//visibility:public"],
)

# Ideally we don't want to create these, but sometimes things are too hard to build from source,
# Or there are problems with the built from-source versions and we want to easily compare them with the system installed versions.
# Because this is unhermetic, the paths may need to be changed depending on where your libraries get installed.
# For example: "usr/lib/foo.so",

#shared objects
cc_import(
    name = "glib",
    shared_library = "usr/lib/x86_64-linux-gnu/libglib-2.0.so",
)

cc_import(
    name = "libcpp",
    shared_library = "usr/lib/x86_64-linux-gnu/libstdc++.so.6",
)

cc_import(
    name = "libc",
    shared_library = "usr/lib/x86_64-linux-gnu/libc.so",
)

cc_import(
    name = "GL",
    shared_library = "usr/lib/x86_64-linux-gnu/libGL.so",
)

cc_import(
    name = "GLEW",
    shared_library = "usr/lib/x86_64-linux-gnu/libGLEW.so",
)

cc_import(
    name = "GLU",
    shared_library = "usr/lib/x86_64-linux-gnu/libGLU.so",
)

cc_import(
    name = "glut",
    shared_library = "usr/lib/x86_64-linux-gnu/libglut.so",
)

cc_import(
    name = "EGL",
    shared_library = "usr/lib/x86_64-linux-gnu/libEGL.so",
)

cc_import(
    name = "OpenGL",
    shared_library = "usr/lib/x86_64-linux-gnu/libOpenGL.so",
)

cc_import(
    name = "GLdispatch",
    shared_library = "usr/lib/x86_64-linux-gnu/libGLdispatch.so",
)

cc_import(
    name = "GLX",
    shared_library = "usr/lib/x86_64-linux-gnu/libGLX.so",
)

cc_import(
    name = "GLX_mesa",
    shared_library = "usr/lib/x86_64-linux-gnu/libGLX_mesa.so.0",
)

cc_import(
    name = "EGL_mesa",
    shared_library = "usr/lib/x86_64-linux-gnu/libEGL_mesa.so.0",
)

cc_import(
    name = "SDL_mixer",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL_mixer.so",
)

cc_import(
    name = "SDL_image",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL_image.so",
)

cc_import(
    name = "SDL",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL.so",
)

cc_import(
    name = "openal",
    shared_library = "usr/lib/x86_64-linux-gnu/libopenal.so",
)

cc_import(
    name = "SDL2",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL2.so",
)

cc_import(
    name = "SDL2_image",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL2_image.so",
)

cc_import(
    name = "SDL2_mixer",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL2_mixer.so",
)

cc_import(
    name = "SDL2_net",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL2_net.so",
)

cc_import(
    name = "glfw",
    shared_library = "usr/lib/x86_64-linux-gnu/libglfw.so",
)

cc_import(
    name = "SFML_audio",
    shared_library = "usr/lib/x86_64-linux-gnu/libsfml-audio.so",
)

cc_import(
    name = "SFML_graphics",
    shared_library = "usr/lib/x86_64-linux-gnu/libsfml-graphics.so",
)

cc_import(
    name = "SFML_network",
    shared_library = "usr/lib/x86_64-linux-gnu/libsfml-network.so",
)

cc_import(
    name = "SFML_system",
    shared_library = "usr/lib/x86_64-linux-gnu/libsfml-system.so",
)

cc_import(
    name = "SFML_window",
    shared_library = "usr/lib/x86_64-linux-gnu/libsfml-window.so",
)

cc_import(
    name = "gmp",
    shared_library = "usr/lib/x86_64-linux-gnu/libgmp.so",
)

cc_import(
    name = "gmpxx",
    shared_library = "usr/lib/x86_64-linux-gnu/libgmpxx.so",
)

cc_import(
    name = "libgudev",
    shared_library = "usr/lib/x86_64-linux-gnu/libgudev-1.0.so.0",
)

cc_import(
    name = "sndio",
    shared_library = "usr/lib/x86_64-linux-gnu/libsndio.so",
)

cc_import(
    name = "uuid",
    shared_library = "usr/lib/x86_64-linux-gnu/libuuid.so",
)

cc_import(
    name = "asound",
    shared_library = "usr/lib/x86_64-linux-gnu/libasound.so",
)

cc_import(
    name = "X11",
    shared_library = "usr/lib/x86_64-linux-gnu/libX11.so",
)

cc_import(
    name = "Xrandr",
    shared_library = "usr/lib/x86_64-linux-gnu/libXrandr.so",
)

cc_import(
    name = "Xi",
    shared_library = "usr/lib/x86_64-linux-gnu/libXi.so",
)


cc_import(
    name = "SM",
    shared_library = "usr/lib/x86_64-linux-gnu/libSM.so",
)
cc_import(
    name = "ICE",
    shared_library = "usr/lib/x86_64-linux-gnu/libICE.so",
)
cc_import(
    name = "Xft",
    shared_library = "usr/lib/x86_64-linux-gnu/libXft.so",
)
cc_import(
    name = "Xt",
    shared_library = "usr/lib/x86_64-linux-gnu/libXt.so",
)

cc_import(
    name = "Xmu",
    shared_library = "usr/lib/x86_64-linux-gnu/libXmu.so",
)
cc_import(
    name = "Xext",
    shared_library = "usr/lib/x86_64-linux-gnu/libXext.so",
)

cc_import(
    name = "xkbcommon",
    shared_library = "usr/lib/x86_64-linux-gnu/libxkbcommon.so",
)

cc_import(
    name = "libXxf86vm",
    shared_library = "usr/lib/x86_64-linux-gnu/libXxf86vm.so",
)

cc_library(
    name = "xkbcommon_hdrs",
    hdrs = glob(["usr/include/xkbcommon/**/*.h"]),
    includes = ["usr/include"],
)

#headers
cc_library(
    name = "GL_hdrs",
    hdrs = glob(["usr/include/GL/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "GLES2_hdrs",
    hdrs = glob(["usr/include/GLES2/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "GLES3_hdrs",
    hdrs = glob(["usr/include/GLES3/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "GL_hdr",
    hdrs = glob(["usr/include/GL/gl.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "GLEW_hdrs",
    hdrs = glob(["usr/include/GL/glew.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "GLU_hdrs",
    hdrs = glob(["usr/include/GL/glu.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "glut_hdrs",
    hdrs = glob(["usr/include/GL/glut.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "X11_hdrs",
    hdrs = glob(["usr/include/X11/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "KHR_hdrs",
    hdrs = glob(["usr/include/KHR/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "SDL_hdrs",
    hdrs = glob(["usr/include/SDL/**/*.h"]),
    includes = ["usr/include/SDL"],
)

cc_library(
    name = "SDL2_hdrs",
    hdrs = glob(["usr/include/SDL2/**/*.h"]),
    includes = ["usr/include/SDL2"],
)

cc_library(
    name = "EGL_hdrs",
    hdrs = glob(["usr/include/EGL/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "openal_hdrs",
    hdrs = glob(["usr/include/AL/**/*.h"]),
    includes = ["usr/include/AL"],
)

cc_library(
    name = "asoundLib_hdr",
    hdrs = ["usr/include/sys/asoundlib.h"],
    includes = ["usr/include"],
)

cc_library(
    name = "alsa_hdrs",
    hdrs = glob(["usr/include/alsa/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "SFML_hdrs",
    hdrs = glob([
        "usr/include/SFML/**/*.hpp",
        "usr/include/SFML/**/*.inl",
    ]),
    includes = ["usr/include"],
)
