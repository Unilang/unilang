#include<stdlib.h>
#include<X11/Xlib.h>
#include<X11/xpm.h>
#include <unistd.h>
#include <iostream>
#include <cassert>

int main ()
{
  Display *dpy;
  Window root;
  XWindowAttributes wa;
  GC g;
  XImage *img;


  /* open the display (connect to the X server) */
  //dpy = XOpenDisplay (getenv ("DISPLAY"));
  dpy = XOpenDisplay (NULL);
  assert(dpy);
  
  int s = DefaultScreen(dpy);


  /* get the root window */
  //root = DefaultRootWindow (dpy);
  root = RootWindow (dpy, s);


  /* get attributes of the root window */
  XGetWindowAttributes(dpy, root, &wa);


  /* create a GC for drawing in the window */
  g = XCreateGC (dpy, root, 0, NULL);


  /* set foreground color */
  XSetForeground(dpy, g, WhitePixelOfScreen(DefaultScreenOfDisplay(dpy)) );


  /* read the image */
  if (XpmReadFileToImage (dpy, "/home/thickey/Desktop/monalisa.xpm", &img, NULL, NULL)) {
      std::cout << "can't find image" << std::endl;
      exit (1);
  }


  /* draw something */
  while (1)
    {
      /* copy the image (which is ir->weight large and ir->height high,
         to a random position of the screen */
      XPutImage(dpy, root, g, img, 0, 0,
                wa.width-img->width,
                wa.height-img->height,
                img->width, img->height );


      /* once in a while, clear all */
      //if( random()%500<1 )
        //XClearWindow(dpy, root);


      /* flush changes and sleep */
      XFlush(dpy);
      //usleep (10);
    }


  XCloseDisplay (dpy);
}