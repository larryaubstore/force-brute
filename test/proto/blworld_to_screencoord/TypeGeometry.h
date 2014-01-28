#ifndef TYPE_GEOMETRY_H
#define TYPE_GEOMETRY_H

#ifdef BOOST_ANDROID
	#include <boost/smart_ptr/shared_ptr.hpp>
#else
	#include <boost/shared_ptr.hpp>
#endif

#include <cmath>
#include <fstream>
#include <ostream>
#include <iomanip> 

//#include <SDL/SDL.h>
//#include <vector>
template<typename T>
class Matrix44
{
public:
	Matrix44()
	{
		T *coeff = &m[0][0];
		memset(coeff, 0x0, sizeof(T) * 16);
		m[0][0] = m[1][1] = m[2][2] = m[3][3] = T(1);  
	}
	const T * operator [] (size_t i) const { return &m[i][0]; }
	T * operator [] (size_t i) { return &m[i][0]; }
	friend std::ostream & operator << (std::ostream &os, const Matrix44<T> &mat)
	{
		const T *coeff = &mat.m[0][0];
		os.precision(3);
		os << "[";
		for (size_t i = 0; i < 16; ++i) {
			os << *(coeff++) << ((i == 15) ? "" : ", ");
		}
		os << "]";
		return os;
	}

  Matrix44 Invert() {
    Matrix44<T> mInv;

    T     a00, a01, a02, a03,
          a10, a11, a12, a13,
          a20, a21, a22, a23,
          a30, a31, a32, a33,

          b00, b01, b02, b03, 
          b04, b05, b06, b07, 
          b08, b09, b10, b11,
          det;

    a00 = m[0][0];
    a01 = m[0][1];
    a02 = m[0][2];
    a03 = m[0][3];
    a10 = m[1][0];
    a11 = m[1][1];
    a12 = m[1][2];
    a13 = m[1][3];
    a20 = m[2][0];
    a21 = m[2][1];
    a22 = m[2][2];
    a23 = m[2][3];
    a30 = m[3][0];
    a31 = m[3][1];
    a32 = m[3][2];
    a33 = m[3][3];

    b00 = a00 * a11 - a01 * a10;
    b01 = a00 * a12 - a02 * a10;
    b02 = a00 * a13 - a03 * a10;
    b03 = a01 * a12 - a02 * a11;
    b04 = a01 * a13 - a03 * a11;
    b05 = a02 * a13 - a03 * a12;
    b06 = a20 * a31 - a21 * a30;
    b07 = a20 * a32 - a22 * a30;
    b08 = a20 * a33 - a23 * a30;
    b09 = a21 * a32 - a22 * a31;
    b10 = a21 * a33 - a23 * a31;
    b11 = a22 * a33 - a23 * a32;

    // Calculate the determinant
    det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;

    det = 1.0 / det;

    mInv[0][0] = (a11 * b11 - a12 * b10 + a13 * b09) * det;
    mInv[0][1] = (a02 * b10 - a01 * b11 - a03 * b09) * det;
    mInv[0][2] = (a31 * b05 - a32 * b04 + a33 * b03) * det;
    mInv[0][3] = (a22 * b04 - a21 * b05 - a23 * b03) * det;
    mInv[1][0] = (a12 * b08 - a10 * b11 - a13 * b07) * det;
    mInv[1][1] = (a00 * b11 - a02 * b08 + a03 * b07) * det;
    mInv[1][2] = (a32 * b02 - a30 * b05 - a33 * b01) * det;
    mInv[1][3] = (a20 * b05 - a22 * b02 + a23 * b01) * det;
    mInv[2][0] = (a10 * b10 - a11 * b08 + a13 * b06) * det;
    mInv[2][1] = (a01 * b08 - a00 * b10 - a03 * b06) * det;
    mInv[2][2] = (a30 * b04 - a31 * b02 + a33 * b00) * det;
    mInv[2][3] = (a21 * b02 - a20 * b04 - a23 * b00) * det;
    mInv[3][0] = (a11 * b07 - a10 * b09 - a12 * b06) * det;
    mInv[3][1] = (a00 * b09 - a01 * b07 + a02 * b06) * det;
    mInv[3][2] = (a31 * b01 - a30 * b03 - a32 * b00) * det;
    mInv[3][3] = (a20 * b03 - a21 * b01 + a22 * b00) * det;

    return mInv;
  }

	T m[4][4];
};

template<typename T>
class Point3
{
public:
	Point3() : x(T(0)), y(T(0)), z(T(0)) {}
	Point3(T xx) : x(xx), y(xx), z(xx) {}
	Point3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
	Point3 operator / (const T &f) const
	{
		T fInv = T(1) / f;
		return Point3(x * fInv, y * fInv, z * fInv);
	}
	Point3 operator + (const Point3<T> &pt) const
	{
		return Point3(x + pt.x, y + pt.y, z + pt.z);
	}
	Point3 operator * (const Matrix44<T> &mat) const
	{
		Point3<T> pt(
			  x * mat[0][0] + y * mat[1][0] + z * mat[2][0] + mat[3][0],
			  x * mat[0][1] + y * mat[1][1] + z * mat[2][1] + mat[3][1],
			  x * mat[0][2] + y * mat[1][2] + z * mat[2][2] + mat[3][2]);
		T w = x * mat[0][3] + y * mat[1][3] + z * mat[2][3] + mat[3][3];

	  return (w != 1) ? pt / w : pt;
	}
	friend std::ostream & operator << (std::ostream &os, const Point3<T> &pt)
	{
		os << 
			std::setw(10) << std::right << pt.x << " " <<
			std::setw(10) << std::right << pt.y << " " <<
			std::setw(10) << std::right << pt.z;
		return os;
	}
	T x, y, z;
};

struct vertex_screen_pair {
  Point3<float> vertex;
  float screen_x;
  float screen_y;
  vertex_screen_pair(Point3<float> vertex , float screen_x, float screen_y) : vertex(vertex), screen_x(screen_x), screen_y(screen_y)  { }
}; 


#endif
