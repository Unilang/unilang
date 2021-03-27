#include "Arcball.hpp"

#include <GL/gl.h>
#include <GL/glu.h>

#include <cmath>

#include <stdio.h>

Arcball::Arcball() {
}

void Arcball::setCenter(const Vector3f& center) {
	center_ = center;
}

Vector3f Arcball::center() {
	return center_;
}

void Arcball::setRadius(const float& radius) {
	radius_ = radius;
}

float Arcball::radius() {
	return radius_;
}


Matrix3f Arcball::rotation(const Vector2f& start, const Vector2f& end) {
	 //for simplicity we assume the eye is at the origin since that's all we need for this application
	GLdouble x1, y1, z1, x2, y2, z2;
	GLdouble modelView[16] = {1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0};
	
	GLdouble projection[16];
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	
	//find the rays from the start/end vectors (in screen coordinates) to the corresponding points on the sphere
	gluUnProject(start(0), start(1), 0.0f, modelView, projection, viewport, &x1, &y1, &z1);
	gluUnProject(start(0), start(1), 1.0f, modelView, projection, viewport, &x2, &y2, &z2);
	
	Vector3f v1;
	v1(0) = (float)(x2 - x1);
	v1(1) = (float)(y2 - y1);
	v1(2) = (float)(z2 - z1);
	
	gluUnProject(end(0), end(1), 0.0f, modelView, projection, viewport, &x1, &y1, &z1);
	gluUnProject(end(0), end(1), 1.0f, modelView, projection, viewport, &x2, &y2, &z2);
	
	Vector3f v2;
	v2(0) = (float)(x2 - x1);
	v2(1) = (float)(y2 - y1);
	v2(2) = (float)(z2 - z1);
	
	//find intersection with sphere
	float c = (center_ * center_) - (radius_ * radius_);
	
	float a1 = v1 * v1;
	float b1 = -2.0 * (v1 * center_);
	
	float a2 = v2 * v2;
	float b2 = -2.0 * (v2 * center_);
	
	float d1 = b1 * b1 - 4.0 * a1 * c;
	float d2 = b2 * b2 - 4.0 * a2 * c;
	
	//if either one of the rays does not intersect the sphere, then do nothing
	if (d1 < 0.0 || d2 < 0.0)
		return Matrix3f::identity();
	
	float r11 = (-b1 - std::sqrt(d1)) / (2.0 * a1);
	float r12 = (-b1 + std::sqrt(d1)) / (2.0 * a1);
	
	float r21 = (-b2 - std::sqrt(d2)) / (2.0 * a2);
	float r22 = (-b2 + std::sqrt(d2)) / (2.0 * a2);
	
	float t1 = (r11 < r12) ? r11 : r12;
	float t2 = (r21 < r22) ? r21 : r22;
	
	//find points on sphere and make them relative to the center
	v1 *= t1;
	v2 *= t2;
	
	v1 -= center_;
	v2 -= center_;
	
	v1 = v1.normalize();
	v2 = v2.normalize();
	
	//find matrix corresponding to a rotating v1 to v2
	return rotationMatrix(crossProduct(v1, v2).normalize(), std::acos(v1 * v2));
}
