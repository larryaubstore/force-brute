#ifndef I_DYNAMIC_GRID_H
#define I_DYNAMIC_GRID_H

#include <vector>
#include "ITile.h"

class IDynamicGrid
{
  public:
    typedef boost::shared_ptr<ITile> TileSharedPtr;
    virtual std::vector<TileSharedPtr> GetTileConverted() = 0;
    virtual ~IDynamicGrid() {};
};

#endif
