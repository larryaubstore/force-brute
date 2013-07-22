#include "Tile.h"


/**
* @brief Constructor
*/
Tile::Tile(int xPos, int yPos, SurfaceSharedPtr surface)
{
  this->_xPos = xPos;
  this->_yPos = yPos;
  this->_surface = surface;
}

Tile::~Tile()
{

}


