#pragma once

/* Copyright (c) Mark J. Kilgard, 1997. */

/* This program is freely distributable without licensing fees and is
   provided without guarantee or warrantee expressed or implied.  This
   program is -not- in the public domain. */

/* Real-time Shadowing library, Version 0.8 */

#ifdef WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>


struct ShadowVolumeState {
  int lightSernum;
  int objectSernum;
#ifdef MP
  int generationDone;
#endif

  int silhouetteSize;
  GLfloat *silhouette;

  GLfloat angle;
  GLfloat axis[3];

  GLfloat topScale;
};

enum {
  RTS_ERROR_OUT_OF_MEMORY,
  RTS_WARNING_EYE_IN_SHADOW,
  RTS_WARNING_LIGHT_TOO_CLOSE
};

typedef enum {
  RTS_OFF,
  RTS_SHINING,
  RTS_SHINING_AND_CASTING
} RTSlightState;

typedef enum {
  RTS_NOT_SHADOWING,
  RTS_SHADOWING
} RTSobjectState;

typedef enum {
  RTS_NO_SHADOWS,
  RTS_USE_SHADOWS,
  RTS_USE_SHADOWS_NO_OVERLAP
} RTSmode;

typedef struct RTSscene RTSscene;
typedef struct RTSlight RTSlight;
typedef struct RTSobject RTSobject;

typedef void (*RTSerrorHandler) (int error, char *message);

RTSscene *rtsCreateScene(
  GLfloat eyePos[3],
  GLbitfield usableStencilBits,
  void (*renderSceneFunc) (GLenum castingLight, void *sceneData, RTSscene * scene),
  void *sceneData);
RTSlight *rtsCreateLight(
  GLenum glLight,
  GLfloat lightPos[3],
  GLfloat radius);
RTSobject *rtsCreateObject(
  GLfloat objectPos[3],
  GLfloat maxRadius,
  void (*renderObject) (void *objectData),
  void *objectData,
  int feedbackBufferSizeGuess);

void rtsAddLightToScene(
  RTSscene * scene,
  RTSlight * light);
void rtsAddObjectToLight(
  RTSlight * light,
  RTSobject * object);

void rtsRemoveLightFromScene(
  RTSscene * scene,
  RTSlight * light);
void rtsRemoveObjectFromLight(
  RTSlight * light,
  RTSobject * object);

void rtsSetLightState(
  RTSlight * light,
  RTSlightState state);
void rtsSetObjectState(
  RTSobject * object,
  RTSobjectState state);

void rtsUpdateEyePos(
  RTSscene * scene,
  GLfloat eyePos[3]);
void rtsUpdateUsableStencilBits(
  RTSscene * scene,
  GLbitfield usableStencilBits);

void rtsUpdateLightPos(
  RTSlight * light,
  GLfloat lightPos[3]);
void rtsUpdateLightRadius(
  RTSlight * light,
  GLfloat lightRadius);

void rtsUpdateObjectPos(
  RTSobject * object,
  GLfloat objectPos[3]);
void rtsUpdateObjectShape(
  RTSobject * object);
void rtsUpdateObjectMaxRadius(
  RTSobject * object,
  GLfloat maxRadius);

void rtsFreeScene(
  RTSscene * scene);
void rtsFreeLight(
  RTSlight * light);
void rtsFreeObject(
  RTSobject * object);

int rtsTriviallyOutsideShadowVolume(
  RTSscene * scene,
  GLfloat objectPos[3],
  GLfloat maxRadius);

void rtsRenderScene(
  RTSscene * scene,
  RTSmode mode);

void rtsRenderSilhouette(
  RTSscene * scene,
  RTSlight * light,
  RTSobject * object);

RTSerrorHandler rtsSetErrorHandler(
  RTSerrorHandler handler);
