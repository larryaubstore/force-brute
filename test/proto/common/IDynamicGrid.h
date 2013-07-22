#ifndef I_DYNAMIC_GRID_H
#define I_DYNAMIC_GRID_H

#include <vector>

class IDynamicGrid
{
	public:

//		virtual void changePosition(int position, DIRECTION direction) = 0;
//		virtual SDL_Surface* getCurrentSDLSurface(int a_position, 
//											      std::string a_domain) = 0; 
//		virtual SDL_Surface* loadSDLSurface(std::string fileName) = 0;

    virtual std::vector<TileSharedPtr> GetTileConverted() = 0;
    
    virtual ~IDynamicGrid() {};
};

#endif
