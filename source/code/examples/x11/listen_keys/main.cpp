#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    Display *display;
    Window window;
    XEvent event;
    int s;
 
    /* open connection with the server */
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }
 
    s = DefaultScreen(display);
 
    /* create window */
    window = XCreateSimpleWindow(display, RootWindow(display, s), 10, 10, 200, 200, 1,
                           BlackPixel(display, s), WhitePixel(display, s));
 
    /* select kind of events we are interested in */
    XSelectInput(display, window, KeyPressMask | KeyReleaseMask );
 
    /* map (show) the window */
    XMapWindow(display, window);
    
    //auto r = RootWindow(display,s);
    //XSelectInput(display, r, KeyPressMask | KeyReleaseMask );
    //XMapWindow(display, r);
 
    /* event loop */
    while (1)
    {
        XNextEvent(display, &event);
 
        /* keyboard events */
        if (event.type == KeyPress)
        {
            printf( "KeyPress: %x\n", event.xkey.keycode );

            /* exit on ESC key press */
            if ( event.xkey.keycode == 0x09 )
                break;
        }
        else if (event.type == KeyRelease)
        {
            printf( "KeyRelease: %x\n", event.xkey.keycode );
        }
    }

    /* close connection to server */
    XCloseDisplay(display);
 
    return 0;
}