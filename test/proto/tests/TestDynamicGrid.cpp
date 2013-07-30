#include "TestDynamicGrid.h"

void TestDynamicGrid::testTileRendering() {

    std::vector<TileSharedPtr> tile_vector;

    SurfaceSharedPtr<SDL_Surface>::type surface_ptr;
    TileSharedPtr tile_ptr(new Tile<SDL_Surface>(0, 0, surface_ptr));
    tile_vector.push_back(tile_ptr);

    tile_ptr.reset(new Tile<SDL_Surface>(1, 0, surface_ptr));
    tile_vector.push_back(tile_ptr);

    tile_ptr.reset(new Tile<SDL_Surface>(2, 0, surface_ptr));
    tile_vector.push_back(tile_ptr);

    boost::shared_ptr<DynamicGrid> dynamicGrid_ptr(new DynamicGrid(50, 50, 100, 100, 1.0d, tile_vector));


    std::vector<TileSharedPtr> tileConverted_vector = dynamicGrid_ptr->GetTileConverted();

    TEST_ASSERT(tileConverted_vector.size() == 3);

    printf("Tile (0, 0) XPos => %i\n", tileConverted_vector[0]->GetXPos());
    printf("Tile (0, 0) YPos => %i\n", tileConverted_vector[0]->GetYPos());
    TEST_ASSERT(tileConverted_vector[0]->GetXPos() == -75);
    TEST_ASSERT(tileConverted_vector[0]->GetYPos() == -75);


    printf("Tile (1, 0) XPos => %i\n", tileConverted_vector[1]->GetXPos());
    printf("Tile (1, 0) YPos => %i\n", tileConverted_vector[1]->GetYPos());
    TEST_ASSERT(tileConverted_vector[1]->GetXPos() == -125);
    TEST_ASSERT(tileConverted_vector[1]->GetYPos() == -75);
}


void TestDynamicGrid::testZoom() {
    std::vector<TileSharedPtr> tile_vector;

    SurfaceSharedPtr<SDL_Surface>::type surface_ptr;
    TileSharedPtr tile_ptr(new Tile<SDL_Surface>(0, 0, surface_ptr));
    tile_vector.push_back(tile_ptr);

    tile_ptr.reset(new Tile<SDL_Surface>(1, 0, surface_ptr));
    tile_vector.push_back(tile_ptr);

    tile_ptr.reset(new Tile<SDL_Surface>(2, 0, surface_ptr));
    tile_vector.push_back(tile_ptr);

    boost::shared_ptr<DynamicGrid> dynamicGrid_ptr(new DynamicGrid(50, 50, 100, 100, 1.0d, tile_vector));

  
    printf("Zoom factor 0.5 \n");
    dynamicGrid_ptr->Zoom(0.5d); 
    std::vector<TileSharedPtr> tileConverted_vector = dynamicGrid_ptr->GetTileConverted();
    printf("Tile (0, 0) XPos => %i\n", tileConverted_vector[0]->GetXPos());
    TEST_ASSERT(tileConverted_vector[0]->GetXPos() == -37);
}

