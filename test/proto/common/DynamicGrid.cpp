

/**
* @brief Constructor
*/
template <typename T> 
DynamicGrid<T>::DynamicGrid(int tileWidth, 
                         int tileHeight, 
                         int shiftX, 
                         int shiftY,
                         double zoomFactor,
                         std::vector<T> tileList)
{
  this->_tileWidth = tileWidth;
  this->_tileHeight = tileHeight;
  this->_shiftX = shiftX;
  this->_shiftY = shiftY;
  this->_tileList = tileList;
  this->_zoomFactor = zoomFactor;
}

template <typename T> 
DynamicGrid<T>::~DynamicGrid()
{

}

//r.x = - ((xConst *  i) - (225 / 2 ) + permanentShiftX) * scalecon;
//r.y = - ((yConst * j) - (101 / 2 ) + permanentShiftY) * scalecon;

template <typename T> 
std::vector<T> DynamicGrid<T>::GetTileConverted() {

  std::vector<T> tile_vector;
  T tile_ptr;
  int x = 0;
  int y = 0;
  for (typename std::vector<T>::iterator it = _tileList.begin() ; it != _tileList.end(); ++it) {

    x = - ((_tileWidth *  (*it)->GetXPos()) - (_tileWidth / 2 ) + _shiftX) * _zoomFactor;
    y = - ((_tileHeight * (*it)->GetYPos()) - (_tileHeight / 2 ) + _shiftY) * _zoomFactor;
    tile_ptr.reset(new Tile(x, y, (*it)->GetSurface()));
    tile_vector.push_back(tile_ptr);
  }
  return tile_vector;
}
