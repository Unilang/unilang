#include<stdlib.h>
#include <cstdlib>
#include<stdio.h>
#include<X11/Xlib.h>
#include <unistd.h>

#include "vroot.h"


//Running this by itself you won't see anything.
//You need to run it under xscreensaver to see it draw to the window.
int main ()
{
  Display *dpy;
  Window root;
  GC g;


  /* open the display (connect to the X server) */
  dpy = XOpenDisplay (getenv ("DISPLAY"));


  /* get the root window */
  root = DefaultRootWindow (dpy);


  /* create a GC for drawing in the window */
  g = XCreateGC (dpy, root, 0, NULL);


  /* set foreground color */
  XSetForeground(dpy, g, WhitePixelOfScreen(DefaultScreenOfDisplay(dpy)) );


  /* draw something */
  while (1)
    {
      /* draw a square */
      XFillRectangle (dpy, root, g, random()%500, random()%500, 50, 40);


      /* once in a while, clear all */
      if( random()%500<1 )
        XClearWindow(dpy, root);


      /* flush changes and sleep */
      XFlush(dpy);
      usleep (10);
    }


  XCloseDisplay (dpy);
}