#ifndef TILE_H
#define TILE_H

#include "TypeDefEngine.h"
#include "ITile.h"



class Tile: public ITile
{
  private:
    int _xPos;
    int _yPos;
    double _zoomFactor;

  public:

    Tile(int xPos, int yPos, double zoomFactor);
    ~Tile();

    virtual int GetXPos();
    virtual int GetYPos();
    virtual double GetZoomFactor();
};

#endif
