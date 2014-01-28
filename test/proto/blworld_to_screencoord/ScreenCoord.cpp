#include "ScreenCoord.h"


ScreenCoord::ScreenCoord() {


}

ScreenCoord::~ScreenCoord() {


}



vertex_screen_pair ScreenCoord::ProcessOneCoord(Point3<float> vertex) {

  float l = -_aspectRatio;
  float r = _aspectRatio;
  float b = _bottom;
  float t = _top;

  Point3<float> ps = vertex * _modelViewMatrix * _perspProjMatrix;

  unsigned px = std::min(unsigned((ps.x - l) / (r - l) * _width), unsigned(_width - 1));
  unsigned py = std::min(unsigned((1 - (ps.y - b) / (t - b)) * _height), unsigned(_height - 1));


  vertex_screen_pair result = vertex_screen_pair(vertex, px, py);
  return result;
}
