#ifndef SCREEN_COORD_H
#define SCREEN_COORD_H

#include "TypeGeometry.h"
#include "IScreenCoord.h"

class ScreenCoord : public IScreenCoord
{
  public:
    ScreenCoord();
    ~ScreenCoord();
    vertex_screen_pair ProcessOneCoord(Point3<float> vertex);
  private:

    int _width;
    int _height;
    float _aspectRatio;
    float _bottom;
    float _top;
    const Matrix44<float> _perspProjMatrix;
    const Matrix44<float> _modelViewMatrix;

};

#endif
