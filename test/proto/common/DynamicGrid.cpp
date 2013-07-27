#include "DynamicGrid.h"

/**
* @brief Constructor
*/
DynamicGrid::DynamicGrid(int tileWidth, 
                         int tileHeight, 
                         int shiftX, 
                         int shiftY,
                         double zoomFactor,
                         std::vector<TileSharedPtr> tileList)
{
  this->_tileWidth = tileWidth;
  this->_tileHeight = tileHeight;
  this->_shiftX = shiftX;
  this->_shiftY = shiftY;
  this->_tileList = tileList;
  this->_zoomFactor = zoomFactor;
}

DynamicGrid::~DynamicGrid()
{

}

std::vector<TileSharedPtr> DynamicGrid::GetTileConverted() {

  std::vector<TileSharedPtr> tile_vector;
  TileSharedPtr tile_ptr;
  int x = 0;
  int y = 0;
  for (std::vector<TileSharedPtr>::iterator it = _tileList.begin() ; it != _tileList.end(); ++it) {

    x = - ((_tileWidth *  (*it)->GetXPos()) - (_tileWidth / 2 ) + _shiftX) * _zoomFactor;
    y = - ((_tileHeight * (*it)->GetYPos()) - (_tileHeight / 2 ) + _shiftY) * _zoomFactor;
    tile_ptr.reset(new Tile<SDL_Surface>(x, y, (*it)->GetSurface()));
    tile_vector.push_back(tile_ptr);
  }
  return tile_vector;
}
