#include "TestDynamicGrid.h"

void TestDynamicGrid::testTileRendering()
{

    std::vector<TileSharedPtr> tile_vector;

    SurfaceSharedPtr surface_ptr;
    TileSharedPtr tile_ptr(new Tile(0, 0, surface_ptr));
    tile_vector.push_back(tile_ptr);

    tile_ptr.reset(new Tile(1, 0, surface_ptr));
    tile_vector.push_back(tile_ptr);

    tile_ptr.reset(new Tile(1, 0, surface_ptr));
    tile_vector.push_back(tile_ptr);

    boost::shared_ptr<DynamicGrid> dynamicGrid_ptr(new DynamicGrid(50, 50, 100, 100, 1.0d, tile_vector));


    std::vector<TileSharedPtr> tileConverted_vector = dynamicGrid_ptr->GetTileConverted();

    TEST_ASSERT(tileConverted_vector.size() == 3);
}
