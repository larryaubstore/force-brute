#ifndef PROJECTION_MAP
#define PROJECTION_MAP

#include <iostream>
#include <cmath>
#include <fstream>
#include <ostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cstdlib>

#include <cstdio>
#include <string.h>
#include "data.h"


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

template<typename T>
void projectverts(
	const Matrix44<T> &mat, 
	const Matrix44<T> &modelview, 
	float l, float r, float b, float t,
	int width, int height,
	const Point3<T> *verts, 
	const unsigned &nverts, 
	const char *filename)
{
	// create an image
	unsigned char *buffer = new unsigned char [width * height];
	memset((void*)buffer, 0x0, width * height);
	for (unsigned i = 0; i < nverts; ++i) {
		Point3<T> ps = verts[i] * modelview * mat;
		if (ps.x < l || ps.x > r || ps.y < b || ps.y > t) continue;
		// convert projected point coordinates to pixel coordinates
		unsigned px = std::min(unsigned((ps.x - l) / (r - l) * width), unsigned(width - 1));
		unsigned py = std::min(unsigned((1 - (ps.y - b) / (t - b)) * height), unsigned(height - 1));
		buffer[py * width + px] = 255;
	}
	// save to ppm
	std::ofstream ofs;
	ofs.open(filename);
	ofs << "P5\n" << width << " " << height << "\n255\n";
	ofs.write((char*)buffer, width * height);
	ofs.close();
	delete [] buffer;
}

struct vertex_screen_map {
  Point3<float> vertex;
  float screen_x;
  float screen_y;
  vertex_screen_map(Point3<float> vertex , float screen_x, float screen_y) : vertex(vertex), screen_x(screen_x), screen_y(screen_y)  { }
}; 

std::vector<vertex_screen_map> GetVertexScreenMap(int width, int height, float aspectRatio, float bottom, float top, const Matrix44<float> &perspProjMatrix, const Matrix44<float> &modelViewMatrix) {

  float l = -aspectRatio;
  float r = aspectRatio;
  float b = bottom;
  float t = top;

  std::map<float, std::set<float, std::greater<float> > > screenx_setScreenY_map;
  Point3<float>* vertsPtr = (Point3<float>*)verts;

  std::vector<vertex_screen_map> vertexScreenMapVector; 

	for (unsigned i = 0; i < nverts; ++i) {
		Point3<float> ps = vertsPtr[i] * modelViewMatrix * perspProjMatrix;
		if (ps.x < l || ps.x > r || ps.y < b || ps.y > t) continue;
		// convert projected point coordinates to pixel coordinates
		unsigned px = std::min(unsigned((ps.x - l) / (r - l) * width), unsigned(width - 1));
		unsigned py = std::min(unsigned((1 - (ps.y - b) / (t - b)) * height), unsigned(height - 1));
    vertexScreenMapVector.push_back(vertex_screen_map(vertsPtr[i], px, py));
    
    //setElement = screenx_setScreenY_map[px];
    //if(screenx_setScreenY_map[px] == NULL) {

    if(screenx_setScreenY_map[px].size() == 0) {
      std::set<float, std::greater<float> > setElement;
      setElement.insert(py);
      screenx_setScreenY_map.insert( std::pair<float, std::set<float, std::greater<float> > >(px, setElement) );
    }

	}
  return vertexScreenMapVector;
}


//int main(int argc, char **argv)
//{
//	int width = 960, height = 540;
//	float aspectRatio = 1;
//	float l = -aspectRatio, r = aspectRatio, b = -1, t = 1; // left, right, bottom top coordinates
//
//	Matrix44<float> perspProjMatrix;
//	Matrix44<float> modelViewMatrix;
//
//  //{{0.685880482, -0.317370087, 0.654861867, 0}, {0.727633715, 0.312468529, -0.61066556, 0}, {-0.0108167641, 0.895343125, 0.445245326, 0}, {-0.363019913, 0.922901273, -55.501564, 1}}
//  modelViewMatrix[0][0] = 0.685880482;
//  modelViewMatrix[0][1] = -0.317370087;
//  modelViewMatrix[0][2] = 0.654861867;
//  modelViewMatrix[0][3] = 0;
//
//  modelViewMatrix[1][0] = 0.727633715;
//  modelViewMatrix[1][1] = 0.312468529;
//  modelViewMatrix[1][2] = -0.61066556;
//  modelViewMatrix[1][3] = 0;
//
//  modelViewMatrix[2][0] = -0.0108167641;
//  modelViewMatrix[2][1] = 0.895343125;
//  modelViewMatrix[2][2] = 0.445245326;
//  modelViewMatrix[2][3] = 0;
//
//  modelViewMatrix[3][0] = -0.363019913;
//  modelViewMatrix[3][1] = 0.922901273;
//  modelViewMatrix[3][2] = -55.501564;
//  modelViewMatrix[3][3] = 1;
// 
//  //{{5.14315796, 0, 0, 0}, {0, 9.14339256, 0, 0}, {0, 0, -1.002002, -1}, {0, 0, -0.2002002, 0
//  perspProjMatrix[0][0] = 5.14315796;
//  perspProjMatrix[0][1] = 0;
//  perspProjMatrix[0][2] = 0;
//  perspProjMatrix[0][3] = 0;
//
//  perspProjMatrix[1][0] = 0;
//  perspProjMatrix[1][1] = 9.14339256;
//  perspProjMatrix[1][2] = 0;
//  perspProjMatrix[1][3] = 0;
//
//  perspProjMatrix[2][0] = 0;
//  perspProjMatrix[2][1] = 0;
//  perspProjMatrix[2][2] = -1.002002;
//  perspProjMatrix[2][3] = -1;
//
//  perspProjMatrix[3][0] = 0;
//  perspProjMatrix[3][1] = 0;
//  perspProjMatrix[3][2] = -0.2002002;
//  perspProjMatrix[3][3] = 0;
//
//  
//	std::cerr << perspProjMatrix << std::endl;
//	projectverts<float>(perspProjMatrix, modelViewMatrix, l, r, b, t, width, height, (Point3<float>*)verts, nverts, "./standard.ppm");
//
//	return 0;
//}

#endif

