#include <stdlib.h>
#include <stdio.h>

#include <xcb/xcb.h>

int main ()
{
    /* geometric objects */
    xcb_point_t          points[] = {
        {10, 10},
        {10, 20},
        {20, 10},
        {20, 20}};

    xcb_point_t          polyline[] = {
        {50, 10},
        { 5, 20},     /* rest of points are relative */
        {25,-20},
        {10, 10}};

    xcb_segment_t        segments[] = {
        {100, 10, 140, 30},
        {110, 25, 130, 60}};

    xcb_rectangle_t      rectangles[] = {
        { 10, 50, 40, 20},
        { 80, 50, 10, 40}};

    xcb_arc_t            arcs[] = {
        {10, 100, 60, 40, 0, 90 << 6},
        {90, 100, 55, 40, 0, 270 << 6}};


    /* Open the connection to the X server */
    xcb_connection_t *connection = xcb_connect (NULL, NULL);

    /* Get the first screen */
    xcb_screen_t *screen = xcb_setup_roots_iterator (xcb_get_setup (connection)).data;

    /* Create black (foreground) graphic context */
    xcb_drawable_t  window     = screen->root;
    xcb_gcontext_t  foreground = xcb_generate_id (connection);
    uint32_t        mask       = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
    uint32_t        values[2]  = {screen->black_pixel, 0};

    xcb_create_gc (connection, foreground, window, mask, values);


    /* Create a window */
    window = xcb_generate_id (connection);

    mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    values[0] = screen->white_pixel;
    values[1] = XCB_EVENT_MASK_EXPOSURE;

    xcb_create_window (connection,                    /* connection          */
                       XCB_COPY_FROM_PARENT,          /* depth               */
                       window,                        /* window Id           */
                       screen->root,                  /* parent window       */
                       0, 0,                          /* x, y                */
                       150, 150,                      /* width, height       */
                       10,                            /* border_width        */
                       XCB_WINDOW_CLASS_INPUT_OUTPUT, /* class               */
                       screen->root_visual,           /* visual              */
                       mask, values );                /* masks */


    /* Map the window on the screen and flush*/
    xcb_map_window (connection, window);
    xcb_flush (connection);


    /* draw primitives */
    xcb_generic_event_t *event;
    while ((event = xcb_wait_for_event (connection))) {
        switch (event->response_type & ~0x80) {
        case XCB_EXPOSE:
            /* We draw the points */
            xcb_poly_point (connection, XCB_COORD_MODE_ORIGIN, window, foreground, 4, points);

            /* We draw the polygonal line */
            xcb_poly_line (connection, XCB_COORD_MODE_PREVIOUS, window, foreground, 4, polyline);

            /* We draw the segments */
            xcb_poly_segment (connection, window, foreground, 2, segments);

            /* draw the rectangles */
            xcb_poly_rectangle (connection, window, foreground, 2, rectangles);

            /* draw the arcs */
            xcb_poly_arc (connection, window, foreground, 2, arcs);

            /* flush the request */
            xcb_flush (connection);

            break;
        default: 
            /* Unknown event type, ignore it */
            break;
        }

        free (event);
    }

    return 0;
}