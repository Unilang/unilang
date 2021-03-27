#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <thread>
#include <iostream>

#include "vroot.h"

#define GLFW_EXPOSE_NATIVE_X11
#define GLFW_EXPOSE_NATIVE_GLX

#include <GLFW/glfw3native.h>
#include <X11/Xlib.h>

#include <X11/Xutil.h>
#include <GL/gl.h>
#include <GL/glx.h>

#define DEBUG 1
#define GLX_CONTEXT_MAJOR_VERSION_ARB       0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB       0x2092

typedef GLXContext (*glXCreateContextAttribsARBProc)(Display *, GLXFBConfig, GLXContext, Bool, const int *);

Window window;
Display *display;
GLXContext ctx;

void setup() {

    display = XOpenDisplay(nullptr);

    // Get the root window
    if (DEBUG == 0) {
        // Get the root window
        window = DefaultRootWindow(display);
    } else {
        // Let's create our own window.
        int screen = DefaultScreen(display);
        window = XCreateSimpleWindow(display, RootWindow(display, screen), 24, 48, 860,
                                     640, 1, BlackPixel(display, screen), WhitePixel(display, screen));
        XMapWindow(display, window);
    }

    // Get the window attributes
    XWindowAttributes wa;
    XGetWindowAttributes(display, window, &wa);

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
    GLXFBConfig *fbc = glXChooseFBConfig(display, DefaultScreen(display), visual_attribs, &fbcount);
    // Get a visual
    XVisualInfo *vi = glXGetVisualFromFBConfig(display, fbc[0]);
    //So we could get graphic context.
    glXCreateContextAttribsARBProc glXCreateContextAttribsARB = nullptr;
    glXCreateContextAttribsARB =
            (glXCreateContextAttribsARBProc)
                    glXGetProcAddress((const GLubyte *) "glXCreateContextAttribsARB");

    int context_attribs[] =
            {
                    GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
                    GLX_CONTEXT_MINOR_VERSION_ARB, 3,
                    None
            };

    ctx = glXCreateContextAttribsARB(display, fbc[0], nullptr, true, context_attribs);
    // Sync to ensure any errors generated are processed.
    XSync(display, false);
    glXMakeCurrent(display, window, ctx);
    // Be sure to free the FBConfig list allocated by glXChooseFBConfig()
    XFree(fbc);
    //Set viewport to parent window's width/height
    glViewport(0, 0, wa.width, wa.height);
}

int main() {

    setup();

    using namespace std::chrono_literals;
    float r = 0;
    while (true) {
        glClearColor(r, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glXSwapBuffers(display, window);
        std::this_thread::sleep_for(1s);
        r += 0.1f;
        if (r > 1) r = 0;
    }

}