#ifndef DYNAMIC_GRID_H
#define DYNAMIC_GRID_H


#include "TypeDefEngine.h"
#include "IDynamicGrid.h"
#include "Tile.h"

//#include "SDL/SDL.h"
//#include "SDL/SDL_image.h"
//#include <map>
//
//#include "IFetcher.h"
//
//#ifdef BOOST_ANDROID
//	#include <boost/smart_ptr/shared_ptr.hpp>
//#else
//	#include <boost/shared_ptr.hpp>
//#endif
//
#include <vector>

// Taille du pavé, largeur + hauteur
// Déplacement vertical et horizontal 
// Facteur de zoom
// Position x et y

template <typename T>
class DynamicGrid: public IDynamicGrid
{
	private:

    int _tileWidth;
    int _tileHeight;
    int _shiftX;
    int _shiftY;
    
    std::vector<T> _tileList;
    double _zoomFactor;


	public:
		DynamicGrid(int tileWidth, 
                int tileHeight, 
                int shiftX, 
                int shiftY,
                double zoomFactor,
                std::vector<T> tileList);
		~DynamicGrid();

    std::vector<T> GetTileConverted();
};

#include "DynamicGrid.cpp"

#endif
