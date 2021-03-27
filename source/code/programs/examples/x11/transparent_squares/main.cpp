/* This program creates a transparent window (using the XShape
* extension) and draw four white (opaque) squares in each corner of
* the window
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <unistd.h>
#include <X11/Xutil.h>
#include <X11/extensions/shape.h>

/* size of the window */
#define W_WIDTH 640
#define W_HEIGHT 480

/* size of the four rectangles that will be drawn in the window */
#define R_WIDTH 80
#define R_HEIGHT 60

/* the four rectangles that will be drawn: one in each corner of the
* window */
XRectangle rectangles[4] =
{
{ 0, 0, R_WIDTH, R_HEIGHT },
{ 0, W_HEIGHT-R_HEIGHT, R_WIDTH, R_HEIGHT },
{ W_WIDTH-R_WIDTH, W_HEIGHT-R_HEIGHT, R_WIDTH, R_HEIGHT },
{ W_WIDTH-R_WIDTH, 0, R_WIDTH, R_HEIGHT }
};

int main(int argc, char **argv)
{
Display *dpy;
Window w;
Pixmap pmap;
GC shape_gc;
GC win_gc;
XGCValues xgcv;
int run = 1; /* loop control variable */

/* open the display */
if(!(dpy = XOpenDisplay(getenv("DISPLAY")))) {
fprintf(stderr, "can't open display\n");
return EXIT_FAILURE;
}

/* create the window */
w = XCreateWindow(dpy, DefaultRootWindow(dpy), 0, 0, W_WIDTH,
W_HEIGHT, 0, CopyFromParent, InputOutput,
CopyFromParent, 0, NULL);

/* create a graphics context for drawing on the window */
xgcv.foreground = WhitePixel(dpy, DefaultScreen(dpy));
xgcv.line_width = 1;
xgcv.line_style = LineSolid;
win_gc = XCreateGC(dpy, w,
GCForeground | GCLineWidth | GCLineStyle, &xgcv);

/* create the pixmap that we'll use for shaping the window */
pmap = XCreatePixmap(dpy, w, W_WIDTH, W_HEIGHT, 1);

/* create a graphics context for drawing on the pixmap */
shape_gc = XCreateGC(dpy, pmap, 0, &xgcv);

/* register events: ExposureMask for re-drawing, ButtonPressMask
* to capture mouse button press events */
XSelectInput(dpy, w, ButtonPressMask | StructureNotifyMask);

XMapWindow(dpy, w);
XSync(dpy, False);

while(run) {
XEvent xe;
XNextEvent(dpy, &xe);
switch (xe.type) {
case ConfigureNotify:
printf("ConfigureNotify\n");
/* whenever we get an expose, draw the rectangles */
XSetForeground(dpy, shape_gc, 0);
XFillRectangle(dpy, pmap, shape_gc, 0, 0, W_WIDTH,
W_HEIGHT);

XSetForeground(dpy, shape_gc, 1);
XDrawRectangles(dpy, pmap, shape_gc, rectangles, 4);
XFillRectangles(dpy, pmap, shape_gc, rectangles, 4);

XSetForeground(dpy, win_gc, WhitePixel(dpy,
DefaultScreen(dpy)));
XDrawRectangles(dpy, w, win_gc, rectangles, 4);
XFillRectangles(dpy, w, win_gc, rectangles, 4);

XShapeCombineMask (dpy, w, ShapeBounding,
0, 0, pmap, ShapeSet);

XSync(dpy, False);
break;
case ButtonPress: /* quit if a button is pressed */
printf("ButtonPress\n");
run = 0;
break;
default:
printf("Caught event %i\n", xe.type);
}
}

XFreePixmap(dpy, pmap);
XDestroyWindow(dpy, w);
XCloseDisplay(dpy);

return 0;
}