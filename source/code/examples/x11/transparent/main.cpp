/*
      ____      _____
    /\__  \   /\  ___\
    \/__/\ \  \ \ \__/_
        \ \ \  \ \____ \
        _\_\ \  \/__/_\ \
      /\ _____\  /\ _____\
      \/______/  \/______/
   Copyright (C) 2011 Joerg Seebohn
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program demonstrates how an X11 window with OpenGL support
   can be drawn transparent.
   The title bar and window border drawn by the window manager are
   drawn opaque.
   Only the background of the window which is drawn with OpenGL
         glClearColor( 0.7, 0.7, 0.7, 0.7) ;
         glClear(GL_COLOR_BUFFER_BIT) ;
   is 30% transparent.
   Compile it with: 
     gcc -std=gnu99 -o test testprogram.c -lX11 -lGL
*/
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>

#include <GL/gl.h>
#include <GL/glx.h>

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[])
{
   Display    * display = XOpenDisplay( 0 ) ;
   const char * xserver = getenv( "DISPLAY" ) ;

   if (display == 0)
   {
      printf("Could not establish a connection to X-server '%s'\n", xserver ) ;
      exit(1) ;
   }

   // query Visual for "TrueColor" and 32 bits depth (RGBA)
   XVisualInfo visualinfo ;
   XMatchVisualInfo(display, DefaultScreen(display), 32, TrueColor, &visualinfo);
   
   // create window
   Window   win ;
   GC       gc ;
   XSetWindowAttributes attr ;
   attr.colormap   = XCreateColormap( display, DefaultRootWindow(display), visualinfo.visual, AllocNone) ;
   attr.event_mask = ExposureMask | KeyPressMask ;
   attr.background_pixmap = None ;
   attr.border_pixel      = 0 ;
   win = XCreateWindow(    display, DefaultRootWindow(display),
                           50, 300, 400, 100, // x,y,width,height : are possibly opverwriteen by window manager
                           0,
                           visualinfo.depth,
                           InputOutput,
                           visualinfo.visual,
                           CWColormap|CWEventMask|CWBackPixmap|CWBorderPixel,
                           &attr
                           ) ;
   gc = XCreateGC( display, win, 0, 0) ;

   // set title bar name of window
   XStoreName( display, win, "Transparent Window with OpenGL Support" ) ;

   // say window manager which position we would prefer
   XSizeHints sizehints ;
   sizehints.flags = PPosition | PSize ;
   sizehints.x     = 50 ;  sizehints.y = 300 ;
   sizehints.width = 400 ; sizehints.height = 100 ;
   XSetWMNormalHints( display, win, &sizehints ) ;
   // Switch On >> If user pressed close key let window manager only send notification >>
   Atom wm_delete_window = XInternAtom( display, "WM_DELETE_WINDOW", 0) ;
   XSetWMProtocols( display, win, &wm_delete_window, 1) ;

   { 
      // change foreground color to brown
      XColor    xcol ;
      xcol.red   = 153 * 256 ;   // X11 uses 16 bit colors !
      xcol.green = 116 * 256 ;
      xcol.blue  = 65  * 256 ;
      XAllocColor( display, attr.colormap, &xcol) ;
      XGCValues gcvalues ;
      gcvalues.foreground = xcol.pixel ;
      XChangeGC( display, gc, GCForeground, &gcvalues) ;
   }

   // create OpenGL context
   GLXContext glcontext = glXCreateContext( display, &visualinfo, 0, True ) ;
   if (!glcontext)
   {
      printf("X11 server '%s' does not support OpenGL\n", xserver ) ;
      exit(1) ;
   }
   glXMakeCurrent( display, win, glcontext ) ;

   // now let the window appear to the user
   XMapWindow( display, win) ;

   int isUserWantsWindowToClose = 0 ;

   while( !isUserWantsWindowToClose )
   {
      int  isRedraw = 0 ;

      /* XPending returns number of already queued events.
       * If no events are queued XPending sends all queued requests to the X-server
       * and tries to read new incoming events. */

      while( XPending(display) > 0 )
      {
         // process event
         XEvent   event ;
         XNextEvent( display, &event) ;

         switch(event.type)
         {  // see 'man XAnyEvent' for a list of available events
         case ClientMessage:
                  // check if the client message was send by window manager to indicate user wants to close the window
                  if (  event.xclient.message_type  == XInternAtom( display, "WM_PROTOCOLS", 1)
                        && event.xclient.data.l[0]  == XInternAtom( display, "WM_DELETE_WINDOW", 1)
                        )
                  {
                     isUserWantsWindowToClose = 1 ;
                  }
         case KeyPress:
                  if (XLookupKeysym(&event.xkey, 0) == XK_Escape)
                  {
                     isUserWantsWindowToClose = 1 ;
                  }
                  break ;
         case Expose:
                  isRedraw = 1 ;
                  break ;
         default:
               // do no thing
               break ;
         }

      }

      // ... all events processed, now do other stuff ...

      if (isRedraw)
      {  // needs redraw
         // use opengl to clear background in (transparent) light grey
         glClearColor( 0.7, 0.7, 0.7, 0.7) ;
         glClear(GL_COLOR_BUFFER_BIT) ;
         glXSwapBuffers( display, win) ;
         glXWaitGL() ;
         // draw string with X11
         XDrawString( display, win, gc, 10, 20, "Hello ! ", 7) ;
      }

      // ... do something else ...

   }

   XDestroyWindow( display, win ) ; 
   win = 0 ;
   XCloseDisplay( display ) ; 
   display = 0 ;

   return 0 ;
}