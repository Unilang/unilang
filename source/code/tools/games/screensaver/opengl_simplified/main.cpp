#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <thread>
#include <iostream>

//#include "vroot.h"

// #define GLFW_EXPOSE_NATIVE_X11
// #define GLFW_EXPOSE_NATIVE_GLX

#include <GLFW/glfw3native.h>
#include <X11/Xlib.h>

#include <X11/Xutil.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include "code/utilities/graphics/x11/main_state/setup_display_settings.hpp"
#include "code/utilities/graphics/x11/main_state/x11_main_state_creator.hpp"

typedef GLXContext (*glXCreateContextAttribsARBProc)(Display *, GLXFBConfig, GLXContext, Bool, const int *);

Main_X11_State setup() {

    Setup_Display_Settings settings;
    settings.window.use_root = false;
    settings.window.pos.x = 0;
    settings.window.pos.y = 0;
    settings.window.dim.width = 860;
    settings.window.dim.height = 640;
    settings.window.border_width = 1;
    settings.window.border = 0;
    settings.window.background = 0;
    auto x11 = X11_Main_State_Creator::Create(settings);
    
    return x11;
}

void bind_to_opengl(Main_X11_State & x11){

    // Get the window attributes
    XWindowAttributes wa;
    XGetWindowAttributes(x11.d, x11.root, &wa);

    // Get a matching FB config
    static int visual_attribs[] =
            {
                    GLX_X_RENDERABLE, true,
                    GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
                    GLX_RENDER_TYPE, GLX_RGBA_BIT,
                    GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
                    GLX_RED_SIZE, 8,
                    GLX_GREEN_SIZE, 8,
                    GLX_BLUE_SIZE, 8,
                    GLX_ALPHA_SIZE, 8,
                    GLX_DEPTH_SIZE, 24,
                    GLX_STENCIL_SIZE, 8,
                    GLX_DOUBLEBUFFER, true,
                    //GLX_SAMPLE_BUFFERS  , 1,
                    //GLX_SAMPLES         , 4,
                    None
            };

    //Get framebuffer config
    int fbcount;
    GLXFBConfig *fbc = glXChooseFBConfig(x11.d, DefaultScreen(x11.d), visual_attribs, &fbcount);
    // Get a visual
    XVisualInfo *vi = glXGetVisualFromFBConfig(x11.d, fbc[0]);
    //So we could get graphic context.
    glXCreateContextAttribsARBProc glXCreateContextAttribsARB = nullptr;
    glXCreateContextAttribsARB =
            (glXCreateContextAttribsARBProc)
                    glXGetProcAddress((const GLubyte *) "glXCreateContextAttribsARB");

    #define GLX_CONTEXT_MAJOR_VERSION_ARB       0x2091
    #define GLX_CONTEXT_MINOR_VERSION_ARB       0x2092
    int context_attribs[] =
            {
                    GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
                    GLX_CONTEXT_MINOR_VERSION_ARB, 3,
                    None
            };

    GLXContext ctx = glXCreateContextAttribsARB(x11.d, fbc[0], nullptr, true, context_attribs);
    // Sync to ensure any errors generated are processed.
    XSync(x11.d, false);
    glXMakeCurrent(x11.d, x11.root, ctx);
    // Be sure to free the FBConfig list allocated by glXChooseFBConfig()
    XFree(fbc);
    //Set viewport to parent window's width/height
    glViewport(0, 0, wa.width, wa.height);
}

int main() {

    auto x11 = setup();
    bind_to_opengl(x11);

    using namespace std::chrono_literals;
    float r = 0;
    while (true) {
        glClearColor(r, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glXSwapBuffers(x11.d, x11.root);
        std::this_thread::sleep_for(1s);
        r += 0.1f;
        if (r > 1) r = 0;
    }

}