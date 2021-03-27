/* ---------------------------------------------------------------- *\

  file    : cliblend.c
  author  : m. gumz <akira at fluxbox dot org>
  copyr   : copyright (c) 2005 by m. gumz

  license : MIT
  
  start   : Do 19 Mai 2005 14:06:32 CEST

\* ---------------------------------------------------------------- */
/* ---------------------------------------------------------------- *\

  about :
  
    $> gcc -o cliblend cliblend.c -lX11 -lXrender -lXpm

\* ---------------------------------------------------------------- */

/* ---------------------------------------------------------------- *\
  includes
\* ---------------------------------------------------------------- */
#include <X11/Xlib.h>
#include <X11/extensions/Xrender.h>
#include <X11/xpm.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* ---------------------------------------------------------------- *\
\* ---------------------------------------------------------------- */

int main(int argc, char* argv[]) {

    Display* dpy = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(dpy);
    int scrnr = DefaultScreen(dpy);
    int depth = DefaultDepth(dpy, scrnr);
    Visual* vis = DefaultVisual(dpy, scrnr);
    GC gc = DefaultGC(dpy, scrnr);

    char* in_filename;
    char* out_filename;
    int alpha;

    int width = 0;
    int height = 0;
    
    Pixmap src_pm = None;
    Pixmap dst_pm = None;

    if (argc < 4) {
        printf("cliblend in.xpm out.xpm alpha\n");
        return 1;
    }

    {
        int major_opcode, first_event, first_error;
        if (XQueryExtension(dpy, RENDER_NAME,
                            &major_opcode,
                            &first_event, &first_error) == False) {
            printf("error, no xrender-support found\n");
            return 0;
        }
    }
    
    in_filename = argv[1];
    out_filename = argv[2];
    alpha = atoi(argv[3]);
    
    {
        XImage* image;
        XpmReadFileToImage(dpy, in_filename, &image, None, 0);
        //image = XGetImage(dpy, root, 0, 0, 200, 200, AllPlanes, ZPixmap);
        width = image->width;
        height = image->height;
        depth = image->depth;
        dst_pm = XCreatePixmap(dpy, root, width, height, depth);
        XPutImage(dpy, dst_pm, gc, image, 0, 0, 0, 0, width, height);
        XDestroyImage(image);
    }
        
    src_pm = XCreatePixmap(dpy, root, width, height, depth);
    {
        GC fillgc;
        XGCValues fillval;

        fillval.foreground = BlackPixel(dpy, scrnr);
        fillgc = XCreateGC(dpy, src_pm, GCForeground, &fillval);
        XFillRectangle(dpy, src_pm, fillgc, 0, 0, width, height);
        XFreeGC(dpy, fillgc);
    }

    {
        Picture alpha_pic = None;
        XRenderPictFormat* format = None;
        XRenderPictFormat alpha_format;

        alpha_format.type = PictTypeDirect;
        alpha_format.depth = 8;
        alpha_format.direct.alpha = 0;
        alpha_format.direct.alphaMask = 0xff;

        //format = XRenderFindFormat(dpy, PictFormatType| PictFormatDepth|
        //    PictFormatAlpha| PictFormatAlphaMask, &alpha_format, 0);

        format = XRenderFindStandardFormat(dpy, PictStandardA8);

        if (!format) {
            printf("error, couldnt find valid format for alpha.\n");
            XFreePixmap(dpy, dst_pm);
            XFreePixmap(dpy, src_pm);
            XCloseDisplay(dpy);
            return 0;
        }

        { /* fill the alpha-picture */ 
            Pixmap alpha_pm = None;
            XRenderColor alpha_color;
            XRenderPictureAttributes alpha_attr;

            alpha_color.red = 0;
            alpha_color.green = 0;
            alpha_color.blue = 0;
            alpha_color.alpha = 0xffff * (alpha)/100;

            alpha_attr.repeat = True;
            alpha_attr.component_alpha = True;

            alpha_pm = XCreatePixmap(dpy, src_pm, 1, 1, 8);
            alpha_pic = XRenderCreatePicture(dpy, alpha_pm, format, CPRepeat|CPComponentAlpha, &alpha_attr);
            XRenderFillRectangle(dpy, PictOpSrc, alpha_pic, &alpha_color, 0, 0, 1, 1);
            XFreePixmap(dpy, alpha_pm);
        }
        
        {
            Picture src_pic;
            Picture dst_pic;
            
            format = XRenderFindVisualFormat(dpy, vis);

            src_pic = XRenderCreatePicture(dpy, src_pm, format, 0, 0);
            dst_pic = XRenderCreatePicture(dpy, dst_pm, format, 0, 0);

            XRenderComposite(dpy, PictOpOver, src_pic, alpha_pic, dst_pic, 0, 0, 0, 0, 0, 0, width, height);
            XRenderFreePicture(dpy, src_pic);
            XRenderFreePicture(dpy, dst_pic);
        }
    }

    XpmWriteFileFromPixmap(dpy, out_filename, dst_pm, 0, 0);
    XFreePixmap(dpy, src_pm);
    XFreePixmap(dpy, dst_pm);
    XCloseDisplay(dpy);
    
    return 0;
}

/* ---------------------------------------------------------------- *\
\* ---------------------------------------------------------------- */
