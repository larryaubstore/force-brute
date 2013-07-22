#ifndef TILE_H
#define TILE_H

#include "TypeDefEngine.h"
#include "ITile.h"


class Tile: public ITile
{
	private:

    int _xPos;
    int _yPos;
    SurfaceSharedPtr _surface;

	public:
		Tile(int xPos, int yPos, SurfaceSharedPtr surface);
		~Tile();
};


#endif
