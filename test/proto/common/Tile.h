#ifndef TILE_H
#define TILE_H

#include "ITile.h"

class Tile: public ITile
{
	private:

    int _xPos;
    int _yPos;

	public:
		Tile(int xPos, int yPos);
		~Tile();
};


#endif
