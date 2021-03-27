#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include <cmath>

template <class T, int N>
class Vector {
	public:
		static Vector<T,N> zero();
		
		Vector();
		Vector(const T data[]);
		Vector(const Vector<T,N>& v);
		Vector& operator = (const Vector<T,N>& v);
	
		T* data();
		
		T& operator() (int i);
		T operator() (int i) const;
		
		//operators
		Vector<T,N> operator - ();
		Vector<T,N> operator + (const Vector<T,N>& v);
		Vector<T,N> operator - (const Vector<T,N>& v);
		
		Vector<T,N>& operator += (const Vector<T,N>& v);
		Vector<T,N>& operator -= (const Vector<T,N>& v);
		
		Vector<T,N> operator * (const T& c);
		Vector<T,N> operator / (const T& c);
		
		Vector<T,N>& operator *= (const T& c);
		Vector<T,N>& operator /= (const T& c);
		
		//inner product
		T operator* (const Vector<T,N>& v);
		
		//distance & length
		T norm();
		T distance(const Vector<T,N>& v);
		
		Vector<T,N> normalize();
		
	private:
		float data_[N];
};

template <class T, int N>
Vector<T,N> Vector<T,N>::zero() {
	Vector<T,N> ret;
	
	for (int i = 0; i < N; i++)
		ret(i) = (T)0;
		
	return ret;
} 

template <class T, int N>
Vector<T,N>::Vector() {
} 

template <class T, int N>
Vector<T,N>::Vector(const T* data) {
	for (int i = 0; i < N; i++)
		data_[i] = data[i];
}

template <class T, int N>
Vector<T,N>::Vector(const Vector<T,N>& v) {
	*this = v;
}

template <class T, int N>
Vector<T,N>& Vector<T,N>::operator = (const Vector<T,N>& v) {
	for (int i = 0; i < N; i++)
		data_[i] = v.data_[i];

	return *this;
}

template <class T, int N>
T* Vector<T,N>::data() {
	return data_;
}

template <class T, int N>
T& Vector<T,N>::operator () (int i) {
	return data_[i];
}

template <class T, int N>
T Vector<T,N>::operator () (int i) const {
	return data_[i];
}

template <class T, int N>
Vector<T,N> Vector<T,N>::operator - () {
	Vector<T,N> ret;
	
	for (int i = 0; i < N; i++)
		ret.data_[i] = -data_[i];
	
	return ret;
}

template <class T, int N>
Vector<T,N> Vector<T,N>::operator + (const Vector& v) {
	Vector<T,N> ret;
	
	for (int i = 0; i < N; i++)
		ret.data_[i] = data_[i] + v.data_[i];
	
	return ret;
}

template <class T, int N>
Vector<T,N> Vector<T,N>::operator - (const Vector& v) {
	Vector<T,N> ret;
	
	for (int i = 0; i < N; i++)
		ret.data_[i] = data_[i] - v.data_[i];
	
	return ret;
}

template <class T, int N>
Vector<T,N>& Vector<T,N>::operator += (const Vector<T,N>& v) {
	for (int i = 0; i < N; i++)
		data_[i] += v.data_[i];
	
	return *this;
}

template <class T, int N>
Vector<T,N>& Vector<T,N>::operator -= (const Vector<T,N>& v) {
	for (int i = 0; i < N; i++)
		data_[i] -= v.data_[i];
	
	return *this;
}

template <class T, int N>
Vector<T,N> Vector<T,N>::operator * (const T& c) {
	Vector<T,N> ret;
	
	for (int i = 0; i < N; i++)
		ret.data_[i] = data_[i] * c;
	
	return ret;
}

template <class T, int N>
Vector<T,N> Vector<T,N>::operator / (const T& c) {
	Vector<T,N> ret;
	
	for (int i = 0; i < N; i++)
		ret.data_[i] = data_[i] / c;
	
	return ret;
}

template <class T, int N>
Vector<T,N>& Vector<T,N>::operator *= (const T& c) {
	for (int i = 0; i < N; i++)
		data_[i] *= c;
	
	return *this;
}

template <class T, int N>
Vector<T,N>& Vector<T,N>::operator /= (const T& c) {
	for (int i = 0; i < N; i++)
		data_[i] /= c;
	
	return *this;
}

template <class T, int N>
T Vector<T,N>::operator* (const Vector<T,N>& v) {
	T sum = 0;
	
	for (int i = 0; i < N; i++)
		sum += data_[i] * v.data_[i];
		
	return sum;
}

template <class T, int N>
T Vector<T,N>::norm() {
	return std::sqrt(*this * *this);
}

template <class T, int N>
T Vector<T,N>::distance(const Vector<T,N>& v) {
	return (*this - v).norm();
}

template <class T, int N>
Vector<T,N> Vector<T,N>::normalize() {
	return *this / this->norm();
}

template <class T>
Vector<T,3> crossProduct(const Vector<T,3>& v1, const Vector<T,3>& v2) {
	T c0 = v1(1) * v2(2) - v1(2) * v2(1);
	T c1 = v1(2) * v2(0) - v1(0) * v2(2);
	T c2 = v1(0) * v2(1) - v1(1) * v2(0);
	
	T data[] = {c0, c1, c2};
	return Vector<T,3>(data);
}

typedef Vector<float,2> Vector2f;
typedef Vector<double,2> Vector2d;

typedef Vector<float,3> Vector3f;
typedef Vector<double,3> Vector3d;

typedef Vector<float,4> Vector4f;
typedef Vector<double,4> Vector4d;

typedef Vector2f Point2f;
typedef Vector2d Point2d;

typedef Vector3f Point3f;
typedef Vector3d Point3d;

typedef Vector4f Point4f;
typedef Vector4d Point4d;

#endif
