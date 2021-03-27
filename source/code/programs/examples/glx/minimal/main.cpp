#include <GL/glx.h>
#include <GL/gl.h>
#include <unistd.h>
#include <iostream>

#define GLX_CONTEXT_MAJOR_VERSION_ARB       0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB       0x2092
typedef GLXContext (*GLXCREATECONTEXTATTRIBSARBPROC)(Display*, GLXFBConfig, GLXContext, Bool, const int*);


int main (int argc, char ** argv){
    
    std::cout << "0" << std::endl;
    Display *dpy = XOpenDisplay(0);

    std::cout << "1" << std::endl;
    int nelements;
    GLXFBConfig *fbc = glXChooseFBConfig(dpy, DefaultScreen(dpy), 0, &nelements);
    std::cout << "2" << std::endl;

    static int attributeList[] = { GLX_RGBA, GLX_DOUBLEBUFFER, GLX_RED_SIZE, 1, GLX_GREEN_SIZE, 1, GLX_BLUE_SIZE, 1, None };
    XVisualInfo *vi = glXChooseVisual(dpy, DefaultScreen(dpy),attributeList);
    std::cout << "3" << std::endl;

    XSetWindowAttributes swa;
    swa.colormap = XCreateColormap(dpy, RootWindow(dpy, vi->screen), vi->visual, AllocNone);
    swa.border_pixel = 0;
    swa.event_mask = StructureNotifyMask;
    Window win = XCreateWindow(dpy, RootWindow(dpy, vi->screen), 0, 0, 100, 100, 0, vi->depth, InputOutput, vi->visual, CWBorderPixel|CWColormap|CWEventMask, &swa);

    XMapWindow (dpy, win);

    //oldstyle context:
    //  GLXContext ctx = glXCreateContext(dpy, vi, 0, GL_TRUE);

    std::cout << "glXCreateContextAttribsARB " << (void*) glXGetProcAddress((const GLubyte*)"glXCreateContextAttribsARB") << std::endl;
    GLXCREATECONTEXTATTRIBSARBPROC glXCreateContextAttribsARB = (GLXCREATECONTEXTATTRIBSARBPROC) glXGetProcAddress((const GLubyte*)"glXCreateContextAttribsARB");

    int attribs[] = {
        GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
        GLX_CONTEXT_MINOR_VERSION_ARB, 0,
        0};

    GLXContext ctx = glXCreateContextAttribsARB(dpy, *fbc, 0, true, attribs);

    glXMakeCurrent (dpy, win, ctx);

        glClearColor (0, 0.5, 1, 1);
        glClear (GL_COLOR_BUFFER_BIT);
        glXSwapBuffers (dpy, win);

        sleep(1);

        glClearColor (1, 0.5, 0, 1);
        glClear (GL_COLOR_BUFFER_BIT);
        glXSwapBuffers (dpy, win);

        sleep(1);

    ctx = glXGetCurrentContext(); 
    glXDestroyContext(dpy, ctx); 
    }
