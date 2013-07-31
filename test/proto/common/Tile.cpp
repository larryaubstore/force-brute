#include "Tile.h"


/**
* @brief Constructor
*/


Tile::Tile(int xPos, int yPos, double zoomFactor) {
  this->_xPos = xPos;
  this->_yPos = yPos;
  this->_zoomFactor = zoomFactor;
}

Tile::~Tile() {

}

int Tile::GetXPos() {
  return _xPos;
}


int Tile::GetYPos() {
  return _yPos;
}

double Tile::GetZoomFactor() {

  return _zoomFactor;
}
