#ifndef TILE_H
#define TILE_H

#include "TypeDefEngine.h"
#include "ITile.h"



template <typename T>
class Tile: public ITile
{
  private:

    int _xPos;
    int _yPos;
    typename SurfaceSharedPtr<T>::type _surface;

  public:
    Tile(int xPos, int yPos, typename SurfaceSharedPtr<T>::type surface);
    ~Tile();

    virtual int GetXPos();
    virtual int GetYPos();
    virtual typename SurfaceSharedPtr<T>::type GetSurface();
};


#include "Tile.tpp"

#endif
