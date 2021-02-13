#include    <stdio.h>
#include    <stdlib.h>
#include    <X11/Xlib.h>
#include    <GL/glx.h>
#include    <GL/gl.h>
#include "code/utilities/graphics/x11/main_state/setup_display_settings.hpp"
#include "code/utilities/graphics/x11/main_state/x11_main_state_creator.hpp"
#include "code/utilities/graphics/glx/x11_to_opengl_binder.hpp"

/* Prototypes */

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

void redraw(void);
void fatalError(char *);

static int  sngBuf[] = {    GLX_RGBA,
                GLX_RED_SIZE, 1,
                GLX_GREEN_SIZE, 1,
                GLX_BLUE_SIZE, 1,
                GLX_DEPTH_SIZE, 12,
                None };

static int  dblBuf[] = {    GLX_RGBA,
                GLX_RED_SIZE, 1,
                GLX_GREEN_SIZE, 1,
                GLX_BLUE_SIZE, 1,
                GLX_DEPTH_SIZE, 12,
                GLX_DOUBLEBUFFER,
                None };

Display     *dpy;
Window      win;
Bool        doubleBuffer = True;

/* Initial 3d box orientation. */

GLfloat     xAngle = 42.0, yAngle = 82.0, zAngle = 112.0;

int main(int argc, char **argv)
{
    XVisualInfo     *vi = NULL;
    Colormap        cmap;
    XSetWindowAttributes    swa;
    GLXContext      cx;
    XEvent          event;
    Bool            needRedraw = False, recalcModelView = True;
    int         dummy;

//Step 1.  Open a connection to the X server.  If an unexpected condition
//   occurs, fatalError will print an explanation and exit.

  if(!(dpy = XOpenDisplay(NULL)))
    fatalError("could not open display");

//Step 2.  Make sure OpenGL's GLX extension is supported.  The
//   glXQueryExtension also returns the GLX extension's error base and event
//   base.  For almost all OpenGL programs, this information is irrelevant;
//   hence the use of dummy.

  if(!glXQueryExtension(dpy, &dummy, &dummy))
    fatalError("X server has no OpenGL GLX extension");

//Step 3.  Find an appropriate OpenGL-capable visual.  Look for double
// buffering first; if it is not found, settle for a single buffered visual.

  if(!(vi = glXChooseVisual(dpy, DefaultScreen(dpy), dblBuf))) {
    if(!(vi = glXChooseVisual(dpy, DefaultScreen(dpy), sngBuf)))
      fatalError("no RGB visual with depth buffer");
    doubleBuffer = False;
  }
 // if(vi->class != TrueColor)
 //   fatalError("TrueColor visual required for this program");

// Step 4. Create an OpenGL rendering context.

  if(!(cx = glXCreateContext(dpy, vi,
        None,   // no sharing of display lists */
        True    //direct rendering if possible */
        )))
    fatalError("could not create rendering context");

// Step 5.  Create an X window with the selected visual.  Since the visual
// selected is likely not be the default, create an X colormap for use.

  cmap = XCreateColormap(dpy,RootWindow(dpy,vi->screen),vi->visual,AllocNone);
  swa.colormap = cmap;
  swa.border_pixel = 0;
  swa.event_mask = ExposureMask | ButtonPressMask | StructureNotifyMask;
  win = XCreateWindow(dpy,RootWindow(dpy,vi->screen),0,0,300,300,
        0,vi->depth,InputOutput,vi->visual,
        CWBorderPixel | CWColormap | CWEventMask,
        &swa);
  XSetStandardProperties(dpy,win,"glxsimple","glxsimple",None,argv,argc,NULL);

// Step 6.  Bind the rendering context to the window. */

  glXMakeCurrent(dpy, win, cx);

// Step 7.  Request that the X window be displayed on the screen. */

  XMapWindow(dpy, win);

// Step 8.  Configure the OpenGL context for rendering. */

  glEnable(GL_DEPTH_TEST);  /* enable depth buffering */
  glMatrixMode(GL_PROJECTION);  /* set up projection transform */
  glLoadIdentity();
  glFrustum(-1.0,1.0,-1.0,1.0,1.0,10.0);

/* Step 9.  Dispatch X events.  The program handles only three event types.
   A mouse ButtonPress event will rotate the cube.  Each button updates a
   different axis of rotation and sets the recalcModelView flag.  A
   ConfigureNotify event informs the program when the window is resized.
   In response, the program updates the OpenGL viewport to render to the
   full size of the window.  In an Expose event is received, indicating
   that the window needs to be redrawn, this is noted with the needRedraw
   flag.  To minimize the work to be done, we reas as many events as are
   ready to be received before acting on the events.
*/

  while(1) {
    do {
      XNextEvent(dpy, &event);
      switch(event.type) {
        case ButtonPress:
          recalcModelView = True;
          switch(event.xbutton.button) {
            case 1: xAngle += 10.0;     break;
            case 2: yAngle += 10.0;     break;
            case 3: zAngle += 10.0;     break;
          }
          break;
        case ConfigureNotify:
          glViewport(0,0,event.xconfigure.width,event.xconfigure.height);
          /* fall through */
        case Expose:
          needRedraw = True;
          break;
      }
    } while(XPending(dpy)); /* loop to compress events */

/* Once the outstanding events have been read, we update the OpenGL modelview
   matrix if the recalcModelView flag is set.  This ensures that any rotations
   from button presses will be applied.  Any time the modelview matrix changes,
   the scene should also be redrawn so needRedraw is set.

   After updating the modelview matrix, determine whether a redraw is needed by
   checking the needRedraw flag.  If it is, call the redraw routine to update
   the window's scene.
*/

    if(recalcModelView) {
      glMatrixMode(GL_MODELVIEW);   /* switch to model matrix stack */
      glLoadIdentity();         /* reset modelview matrix to identity */
      glTranslatef(0.0,0.0,-3.0);   /* move camera back 3 units */
      glRotatef(xAngle,0.1,0.0,0.0);    /* rotate by X angle */
      glRotatef(yAngle,0.0,0.1,0.0);    /* rotate by Y angle */
      glRotatef(zAngle,0.0,0.0,1.0);    /* rotate by Z angle */
      recalcModelView = False;
      needRedraw = True;
    }

    if(needRedraw) {
      redraw();
      needRedraw = False;
    }
  }
}


void redraw(void)
{
    static Bool displayListInited = False;

  if(displayListInited)
    glCallList(1);              /* if list exists, execute it */
  else {
    glNewList(1,GL_COMPILE_AND_EXECUTE);    /* else create and execute it */

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);

      /* Front face */
      glColor3f(0.0,0.7,0.1);           /* green */
      glVertex3f(-1.0, 1.0, 1.0);
      glVertex3f( 1.0, 1.0, 1.0);
      glVertex3f( 1.0,-1.0, 1.0);
      glVertex3f(-1.0,-1.0, 1.0);

      /* Back face */
      glColor3f(0.9,1.0,0.0);           /* yellow */
      glVertex3f(-1.0, 1.0,-1.0);
      glVertex3f( 1.0, 1.0,-1.0);
      glVertex3f( 1.0,-1.0,-1.0);
      glVertex3f(-1.0,-1.0,-1.0);

      /* Top side face */
      glColor3f(0.2,0.2,1.0);           /* blue */
      glVertex3f(-1.0, 1.0, 1.0);
      glVertex3f( 1.0, 1.0, 1.0);
      glVertex3f( 1.0, 1.0,-1.0);
      glVertex3f(-1.0, 1.0,-1.0);

      /* Bottom side face */
      glColor3f(0.7,0.0,0.1);           /* red */
      glVertex3f(-1.0,-1.0, 1.0);
      glVertex3f( 1.0,-1.0, 1.0);
      glVertex3f( 1.0,-1.0,-1.0);
      glVertex3f(-1.0,-1.0,-1.0);

    glEnd();

    glEndList();
    displayListInited = True;
  }

  if(doubleBuffer)
    glXSwapBuffers(dpy,win);        //buffer swap does implicit glFlush.
  else
    glFlush();              //explicit flush for single buf case
}


void fatalError(char *estr)
{
  fprintf(stderr,estr);
  exit(1);
}