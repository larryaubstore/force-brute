#ifndef TILE_H
#define TILE_H

#include "TypeDefEngine.h"
#include "ITile.h"



template <typename T>
class Tile: public ITile
{
  typedef boost::shared_ptr<T> SurfaceSharedPtr;
	private:

    int _xPos;
    int _yPos;
    SurfaceSharedPtr _surface;

	public:
		Tile(int xPos, int yPos, SurfaceSharedPtr surface);
		~Tile();

    virtual int GetXPos();
    virtual int GetYPos();
    virtual SurfaceSharedPtr GetSurface();
};


#include "Tile.cpp"

#endif
