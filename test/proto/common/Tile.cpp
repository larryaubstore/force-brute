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

int Tile::GetXPos() {
  return _xPos;
}


int Tile::GetYPos() {
  return _yPos;
}

SurfaceSharedPtr Tile::GetSurface() {
  return _surface;
}
