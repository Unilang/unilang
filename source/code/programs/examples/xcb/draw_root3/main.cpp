//http://stackoverflow.com/questions/5134297/xlib-how-does-this-removing-window-decoration-work
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <inttypes.h>
#include <xcb/xcb.h>
#include <xcb/xproto.h>

//xcb_event.h
#define XCB_EVENT_RESPONSE_TYPE_MASK (0x7f)
#define XCB_EVENT_RESPONSE_TYPE(e) (e->response_type & XCB_EVENT_RESPONSE_TYPE_MASK)
#define XCB_EVENT_SENT(e) (e->response_type & ~XCB_EVENT_RESPONSE_TYPE_MASK)

#define WIDTH 300
#define HEIGHT 100

using namespace std;

xcb_connection_t* connection;
xcb_screen_t* screen;
xcb_window_t window;

typedef struct MotifHints
{
    uint32_t   flags;
    uint32_t   functions;
    uint32_t   decorations;
    int32_t    input_mode;
    uint32_t   status;
} Hints;

static xcb_gcontext_t getFontGC(xcb_connection_t* c,
    xcb_screen_t* screen,
    xcb_window_t window,
    const char* font_name);

static void testCookie(xcb_void_cookie_t cookie,
    xcb_connection_t* connection,
    char* errMessage)
{
    xcb_generic_error_t* error = xcb_request_check(connection, cookie);
    if (error) {
        fprintf(stderr, "ERROR: %s : %" PRIu8 "\n", errMessage, error->error_code);
        xcb_disconnect(connection);
        exit(-1);
    }
}

static void drawText(xcb_connection_t* connection,
    xcb_screen_t* screen,
    xcb_window_t window,
    int16_t x1,
    int16_t y1,
    const char* label)
{

    /* get graphics context */
    xcb_gcontext_t gc = getFontGC(connection, screen, window, "fixed");

    /* draw the text */
    xcb_void_cookie_t textCookie = xcb_image_text_8_checked(connection,
        strlen(label),
        window,
        gc,
        x1, y1,
        label);

    testCookie(textCookie, connection, "can't paste text");

    /* free the gc */
    xcb_void_cookie_t gcCookie = xcb_free_gc(connection, gc);

    testCookie(gcCookie, connection, "can't free gc");
}

static xcb_gcontext_t getFontGC(xcb_connection_t* connection,
    xcb_screen_t* screen,
    xcb_window_t window,
    const char* font_name)
{
    /* get font */
    xcb_font_t font = xcb_generate_id(connection);
    xcb_void_cookie_t fontCookie = xcb_open_font_checked(connection,
        font,
        strlen(font_name),
        font_name);

    testCookie(fontCookie, connection, "can't open font");

    /* create graphics context */
    xcb_gcontext_t gc = xcb_generate_id(connection);
    uint32_t mask = XCB_GC_FOREGROUND | XCB_GC_BACKGROUND | XCB_GC_FONT;
    uint32_t value_list[3] = { screen->black_pixel,
        screen->white_pixel,
        font };

    xcb_void_cookie_t gcCookie = xcb_create_gc_checked(connection,
        gc,
        window,
        mask,
        value_list);

    testCookie(gcCookie, connection, "can't create gc");

    /* close font */
    fontCookie = xcb_close_font_checked(connection, font);

    testCookie(fontCookie, connection, "can't close font");

    return gc;
}

void invalidate()
{
    xcb_expose_event_t invalidate_event;
    invalidate_event.window = window;
    invalidate_event.response_type = XCB_EXPOSE;
    invalidate_event.x = 0;
    invalidate_event.y = 0;
    invalidate_event.width = WIDTH;
    invalidate_event.height = HEIGHT;
    xcb_send_event(connection, false, window, XCB_EVENT_MASK_EXPOSURE, (char*)&invalidate_event);
    xcb_flush(connection);
}

void event_loop()
{
    xcb_generic_event_t* event;
    int done = 0;
    while (!done && (event = xcb_wait_for_event(connection))) {
        switch (event->response_type & XCB_EVENT_RESPONSE_TYPE_MASK) {
        case XCB_EXPOSE: /* draw or redraw the window */
            {
            drawText(connection,
                screen,
                window,
                10, HEIGHT / 2 + 5,
                "To close windows - press and release any key");

            xcb_gcontext_t  foreground = xcb_generate_id (connection);
            uint32_t mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
            uint32_t values[2];
            values[0] = screen->black_pixel;
            values[1] = 0;
            xcb_create_gc (connection, foreground, window, mask, values);

            xcb_rectangle_t rectangle;
            rectangle.x = 0;
            rectangle.y = 0;
            rectangle.width = WIDTH-1;
            rectangle.height = HEIGHT-1;
            xcb_poly_rectangle (connection,
                        window,
                        foreground,
                        1,
                        &rectangle);
            xcb_free_gc(connection, foreground);
            xcb_flush(connection);
            }
            break;
        case XCB_KEY_RELEASE: /* exit on key release */
            done = 1;
            break;
        }
        free(event);
    }
}

int main()
{
    int screenNum;
    connection = xcb_connect(NULL, &screenNum);
    if (!connection) {
        fprintf(stderr, "ERROR: can't connect to an X server\n");
        return -1;
    }
    /* get the current screen */
    xcb_screen_iterator_t iter = xcb_setup_roots_iterator(xcb_get_setup(connection));

    // we want the screen at index screenNum of the iterator
    for (int i = 0; i < screenNum; ++i) {
        xcb_screen_next(&iter);
    }

    screen = iter.data;

    if (!screen) {
        fprintf(stderr, "ERROR: can't get the current screen\n");
        xcb_disconnect(connection);
        return -1;
    }

    /* create the window */
    window = xcb_generate_id(connection);

    uint32_t mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    uint32_t values[2];
    values[0] = screen->white_pixel;
    values[1] = XCB_EVENT_MASK_KEY_RELEASE | XCB_EVENT_MASK_BUTTON_PRESS | XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_POINTER_MOTION;

    xcb_void_cookie_t windowCookie = xcb_create_window_checked(connection,
        screen->root_depth,
        window, screen->root,
        20, 200,
        WIDTH, HEIGHT,
        0, XCB_WINDOW_CLASS_INPUT_OUTPUT,
        screen->root_visual,
        mask, values);

    testCookie(windowCookie, connection, "can't create window");

    xcb_intern_atom_cookie_t cookie = xcb_intern_atom ( connection, 0, strlen ( "_MOTIF_WM_HINTS" ), "_MOTIF_WM_HINTS" );
    xcb_intern_atom_reply_t *reply = xcb_intern_atom_reply ( connection, cookie, NULL );

    MotifHints hints;
    hints.flags = 2;
    hints.functions = 0;
    hints.decorations = 0;
    hints.input_mode = 0;
    hints.status = 0;

    xcb_change_property_checked ( connection,
                     XCB_PROP_MODE_REPLACE,
                     window,
                     reply->atom,
                     XCB_ATOM_INTEGER,
                     32,
                     5,
                     &hints );

    xcb_void_cookie_t mapCookie = xcb_map_window_checked(connection, window);
    testCookie(mapCookie, connection, "can't map window");
    xcb_flush(connection); // make sure window is drawn

    event_loop();
    xcb_disconnect(connection);
    exit(EXIT_SUCCESS);
    return 0;
}