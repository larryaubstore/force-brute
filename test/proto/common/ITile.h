#ifndef I_TILE_H
#define I_TILE_H

#ifdef BOOST_ANDROID
	#include <boost/smart_ptr/shared_ptr.hpp>
#else
	#include <boost/shared_ptr.hpp>
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class ITile
{
	public:

//		virtual void changePosition(int position, DIRECTION direction) = 0;
//		virtual SDL_Surface* getCurrentSDLSurface(int a_position, 
//											      std::string a_domain) = 0; 
//		virtual SDL_Surface* loadSDLSurface(std::string fileName) = 0;

    virtual ~ITile() {};

    virtual int GetXPos() = 0;
    virtual int GetYPos() = 0;
    virtual boost::shared_ptr<SDL_Surface> GetSurface() = 0;
};

#endif
