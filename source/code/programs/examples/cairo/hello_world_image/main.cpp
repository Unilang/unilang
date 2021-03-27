#include <cairo-svg.h>
#include <stdio.h>

int main(int argc, char **argv) {
    cairo_surface_t *surface = cairo_svg_surface_create("/home/laptop/Desktop/Cairo_example.svg", 100.0, 100.0);
    cairo_t *cr = cairo_create(surface);

    /* Draw the squares in the background */
    for (int x=0; x<10; x++)
       for (int y=0; y<10; y++)
           cairo_rectangle(cr, x*10.0, y*10.0, 5, 5);

    cairo_pattern_t *pattern = cairo_pattern_create_radial(50, 50, 5, 50, 50, 50);
    cairo_pattern_add_color_stop_rgb(pattern, 0, 0.75, 0.15, 0.99);
    cairo_pattern_add_color_stop_rgb(pattern, 0.9, 1, 1, 1);

    cairo_set_source(cr, pattern);
    cairo_fill(cr);

    /* Writing in the foreground */
    cairo_set_font_size (cr, 15);
    cairo_select_font_face (cr, "Georgia", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_source_rgb (cr, 0, 0, 0);

    cairo_move_to(cr, 10, 25);
    cairo_show_text(cr, "Hello");

    cairo_move_to(cr, 10, 75);
    cairo_show_text(cr, "Wikipedia!");

    cairo_destroy(cr), cr = NULL;
    cairo_surface_destroy(surface), surface = NULL;
}