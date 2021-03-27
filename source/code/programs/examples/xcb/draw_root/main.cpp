#include <stdlib.h>
#include <stdio.h>
#include <xcb/xcb.h>

int
main ()
{
  xcb_connection_t    *c;
  xcb_screen_t        *screen;
  uint32_t             mask = 0;
  xcb_gcontext_t    gc = { 0 };    /* the returned default graphic context */
  xcb_drawable_t draw;

  xcb_rectangle_t rectangles[] = {
    { 200, 200, 400, 400 },
  };

  c = xcb_connect (NULL, NULL);

  /* get the first screen */
  screen = xcb_setup_roots_iterator ( xcb_get_setup ( c ) ).data;

  gc = xcb_generate_id ( c );

  /* root window */
  draw = screen->root;

  mask = XCB_GC_FUNCTION | XCB_GC_FOREGROUND | XCB_GC_BACKGROUND |  XCB_GC_LINE_WIDTH| XCB_GC_LINE_STYLE | XCB_GC_GRAPHICS_EXPOSURES;
  uint32_t values[] = {
      XCB_GX_XOR,
      screen->white_pixel,
      screen->black_pixel,
      1,
      XCB_LINE_STYLE_ON_OFF_DASH,
      0
  };

  xcb_create_gc ( c, gc, draw, mask, values );
  xcb_poly_rectangle (c, draw, gc, 3, rectangles);
  xcb_map_window (c, draw);
  xcb_flush(c);
  while(true){
  }
  return 0;
}