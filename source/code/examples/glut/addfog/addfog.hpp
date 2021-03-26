#pragma once

void afEyeNearFar(GLfloat fnear, GLfloat ffar);
void afFogStartEnd(GLfloat start, GLfloat end);
void afFogMode(GLenum mode);
void afFogDensity(GLfloat density);
void afFogColor(GLfloat red, GLfloat green, GLfloat blue);
void afDoFinalFogPass(GLint x, GLint y, GLsizei width, GLsizei height);

