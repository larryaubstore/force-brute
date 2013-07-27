#include "Tile.h"


/**
* @brief Constructor
*/


template <typename T>
Tile<T>::Tile(int xPos, int yPos, SurfaceSharedPtr surface)
{
  this->_xPos = xPos;
  this->_yPos = yPos;
  this->_surface = surface;
}

template <typename T>
Tile<T>::~Tile()
{

}

template <typename T>
int Tile<T>::GetXPos() {
  return _xPos;
}


template <typename T>
int Tile<T>::GetYPos() {
  return _yPos;
}

template <typename T>
typename Tile<T>::SurfaceSharedPtr Tile<T>::GetSurface() {
  return _surface;
}
