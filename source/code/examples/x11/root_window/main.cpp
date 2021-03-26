#include <assert.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <cairo.h>
#include <cairo-xlib.h>

int width, height;

void draw(cairo_t *cr) {
    int quarter_w = width / 4;
    int quarter_h = height / 4;
    cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);
    cairo_rectangle(cr, quarter_w, quarter_h, quarter_w * 2, quarter_h * 2);
    cairo_fill(cr);
}

int main() {
    Display *d = XOpenDisplay(NULL);
    assert(d);

    int s = DefaultScreen(d);
    Window w = RootWindow(d, s);
    //Window w = (Window) 0x1e0000a;
    width = DisplayWidth(d, s);
    height = DisplayHeight(d, s);

    cairo_surface_t *surf = cairo_xlib_surface_create(d, w,
                                  DefaultVisual(d, s),
                                  width, height);
    cairo_t *cr = cairo_create(surf);

    XSelectInput(d, w, ExposureMask);

    draw(cr);

    XEvent ev;
    while (1) {
    XNextEvent(d, &ev);
        printf("Event!\n");
        if (ev.type == Expose) {
            draw(cr);
        }
    }

    cairo_destroy(cr);
    cairo_surface_destroy(surf);
    XCloseDisplay(d);
    return 0;
}