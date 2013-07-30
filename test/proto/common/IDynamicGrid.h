#ifndef I_DYNAMIC_GRID_H
#define I_DYNAMIC_GRID_H

#include <vector>

#include "TypeDefEngine.h"
#include "ITile.h"

class IDynamicGrid
{
  public:
    virtual std::vector<TileSharedPtr> GetTileConverted() = 0;

    virtual void Zoom(double factor) = 0;

    virtual ~IDynamicGrid() {};
};

#endif
