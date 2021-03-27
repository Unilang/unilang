#ifndef _ARCBALL_HPP
#define _ARCBALL_HPP

#include "Matrix.hpp"
#include "Vector.hpp"

class Arcball {
	public:
		Arcball();
		
		void setCenter(const Vector3f& center);
		Vector3f center();
		
		void setRadius(const float& radius);
		float radius();
		
		Matrix3f rotation(const Vector2f& start, const Vector2f& end);
		
	private:
		Vector3f center_;
		float radius_;
};

#endif
