#include "DynamicGrid.h"


/**
* @brief Constructor
*/
DynamicGrid::DynamicGrid(int tileWidth, 
                         int tileHeight, 
                         int shiftX, 
                         int shiftY,
                         std::vector<TileSharedPtr> tileList)
{
  this->_tileWidth = tileWidth;
  this->_tileHeight = tileHeight;
  this->_shiftX = shiftX;
  this->_shiftY = shiftY;
  this->_tileList = tileList;
}

DynamicGrid::~DynamicGrid()
{

}


