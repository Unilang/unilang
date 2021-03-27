#include <cairo-svg.h>
#include <stdio.h>

int main(int argc, char **argv) {
    //cairo_surface_t *surface = cairo_svg_surface_create("/home/laptop/Desktop/cairo_pixel_example.svg", 100.0, 100.0);
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_RGB24,100,100);
    cairo_t *cr = cairo_create(surface);
    
    //draw background
    cairo_save(cr);
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);
    cairo_restore(cr);

    cairo_rectangle (cr, 50, 50, 1, 1);
    cairo_set_source_rgb (cr, 0, 0, 0);
    cairo_fill (cr);
    
    cairo_rectangle (cr, 52, 50, 1, 1);
    cairo_set_source_rgb (cr, 0, 0, 0);
    cairo_fill (cr);
    
    cairo_set_source_rgb (cr, 0, 0, 0);
    cairo_fill(cr);
    
    cairo_surface_write_to_png(surface, "/home/laptop/Desktop/cairo_pixel_example.png");


    cairo_destroy(cr), cr = NULL;
    cairo_surface_destroy(surface), surface = NULL;
    
}