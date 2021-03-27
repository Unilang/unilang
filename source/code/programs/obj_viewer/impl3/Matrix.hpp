#ifndef _MATRIX_HPP
#define _MATRIX_HPP

#include "Vector.hpp"

#include <cmath>

template <class T, int M, int N>
class Matrix {
	public:
		static Matrix<T,M,N> zero();
		static Matrix<T,M,N> identity();
		
		Matrix();
		Matrix(const T* data);
		Matrix(const Matrix<T,M,N>& m);
		Matrix& operator = (const Matrix<T,M,N>& m);
		
		T* data();
		
		T& operator () (int i, int j);
		T operator () (int i, int j) const;
		
		Vector<T,N> operator * (const Vector<T,N>& v);
		Matrix<T,M,N> operator * (const Matrix<T,N,M>& m);
		
	private:
		T data_[M * N];
};

template <class T, int M, int N>
Matrix<T,M,N> Matrix<T,M,N>::zero() {
	Matrix<T,M,N> ret;
	
	for (int i = 0; i < M * N; i++)
		ret.data_[i] = (T)0;
		
	return ret;
}

template <class T, int M, int N>
Matrix<T,M,N> Matrix<T,M,N>::identity() {
	Matrix<T,M,N> ret = zero();
	
	for (int i = 0; i < M; i++)
		ret(i, i) = (T)1;
	
	return ret;
}

template <class T, int M, int N>
Matrix<T,M,N>::Matrix() {
}

template <class T, int M, int N>
Matrix<T,M,N>::Matrix(const Matrix& m) {
	*this = m;
}

template <class T, int M, int N>
Matrix<T,M,N>& Matrix<T,M,N>::operator = (const Matrix<T,M,N>& m) {
	for (int i = 0; i < M * N; i++)
		data_[i] = m.data_[i];
		
	return *this;
}

template <class T, int M, int N>
T* Matrix<T,M,N>::data() {
	return data_;
}

template <class T, int M, int N>
T& Matrix<T,M,N>::operator () (int i, int j) {
	return data_[N * i + j];
}

template <class T, int M, int N>
T Matrix<T,M,N>::operator () (int i, int j) const {
	return data_[N * i + j];
}

template <class T, int M, int N>
Vector<T,N> Matrix<T,M,N>::operator * (const Vector<T,N>& v) {
	Vector<T,M> ret = Vector<T,M>::zero();
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			ret(i) += (*this)(i, j) * v(j);
		}
	}
	
	return ret;
}

template <class T, int M, int N>
Matrix<T,M,N> Matrix<T,M,N>::operator * (const Matrix<T,N,M>& m) {
	Matrix<T,M,N> ret;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			T sum = 0;
			
			for (int k = 0; k < N; k++) {
				sum += (*this)(i, k) * m(k, j);
			}
			
			ret(i, j) = sum;
		}
	}
	
	return ret;
}

template <class T>
Matrix<T,4,4> isometryMatrix(const Matrix<T,3,3>& rot, const Vector<T,3>& trans) {
	Matrix<T,4,4> ret = Matrix<T,4,4>::zero();
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ret(i, j) = rot(i, j);
		}
	}
	
	for (int i = 0; i < 3; i++)
		ret(i, 3) = trans(i);
	
	ret(3, 3) = 1.0;
	
	return ret;
}

template <class T>
Matrix<T,3,3> rotationMatrix(const Vector<T,3>& axis, const T& angle) {
	T c = std::cos(angle);
	T s = std::sin(angle);
	
	Matrix<T,3,3> ret;
	
	ret(0, 0) = c + (1.0f - c) * axis(0) * axis(0);
	ret(0, 1) = (1.0f - c) * axis(0) * axis(1) - s * axis(2);
	ret(0, 2) = (1.0f - c) * axis(0) * axis(2) + s * axis(1);
	
	ret(1, 0) = (1.0f - c) * axis(0) * axis(1) + s * axis(2); 
	ret(1, 1) = c + (1.0f - c) * axis(1) * axis(1);
	ret(1, 2) = (1.0f - c) * axis(1) * axis(2) - s * axis(0);
	
	ret(2, 0) = (1.0f - c) * axis(0) * axis(2) - s * axis(1);
	ret(2, 1) = (1.0f - c) * axis(1) * axis(2) + s * axis(0);
	ret(2, 2) = c + (1.0f - c) * axis(2) * axis(2);
	
	return ret;
}

template <class T, int N, int M, int P>
Matrix<T,M,P> matrixMult(const Matrix<T,M,N>& m1, const Matrix<T,N,P>& m2) {
	Matrix<T,M,P> ret;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < P; j++) {
			T sum = (T)0;
			
			for (int k = 0; k < N; k++) {
				sum += m1(i, k) * m2(k, j);
			}
			
			ret(i, j) = sum;
		}
	}
	
	return ret;
}

typedef Matrix<float,3,3> Matrix3f;
typedef Matrix<double,3,3> Matrix3d;

typedef Matrix<float,4,4> Matrix4f;
typedef Matrix<double,4,4> Matrix4d;

#endif
