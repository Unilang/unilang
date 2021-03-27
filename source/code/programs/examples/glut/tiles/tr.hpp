
/* tr.h */

/*
 * Tiled Rendering library
 *
 * This library allows one to render arbitrarily large images with OpenGL.
 * The basic idea is to break the image into tiles which are rendered one
 * at a time.  The tiles are assembled together to form the final, large
 * image.  Tiles can be of any size.
 *
 * Basic usage:
 *
 * 1. Allocate a tile rendering context:
 *       TRcontext t = trNew();
 *
 * 2. Specify the final image buffer and tile size:
 *       GLubyte image[W][H][4]
 *       trSetup(t, W, H, (GLubyte *) image, tileWidth, tileHeight);
 *
 * 3. Setup your projection:
 *       trFrustum(t, left, right, bottom top, nnear, ffar);
 *    or
 *       trOrtho(t, left, right, bottom top, nnear, ffar);
 *    or
 *       trPerspective(t, fovy, aspect, nnear, ffar);
 *
 * 4. Render the tiles:
 *       do {
 *           trBeginTile(t);
 *           DrawMyScene();
 *       } while (trEndTile(t));
 *
 *    You provide the DrawMyScene() function which calls glClear() and
 *    draws all your stuff.
 *
 * 5. The image array is now complete.  Display it, write it to a file, etc.
 *
 * 6. Delete the tile rendering context when finished:
 *       trDelete(t);
 *
 *
 * Brian Paul
 * April 1997
 */


#ifndef TR_H
#define TR_H


#ifdef WIN32
#include <windows.h>
#endif
#include <GL/gl.h>


typedef struct _TRctx TRcontext;


TRcontext *trNew(void);


void trDelete(TRcontext *tr);


void trSetup(TRcontext *tr,
		    GLint imageWidth, GLint imageHeight, GLubyte *image,
		    GLint tileWidth, GLint tileHeight);


void trOrtho(TRcontext *tr,
		    GLdouble left, GLdouble right,
		    GLdouble bottom, GLdouble top,
		    GLdouble nnear, GLdouble ffar);


void trFrustum(TRcontext *tr,
		      GLdouble left, GLdouble right,
		      GLdouble bottom, GLdouble top,
		      GLdouble nnear, GLdouble ffar);


void trPerspective(TRcontext *tr,
			  GLdouble fovy, GLdouble aspect,
			  GLdouble zNear, GLdouble zFar );


void trBeginTile(TRcontext *tr);


int trEndTile(TRcontext *tr);


#endif
