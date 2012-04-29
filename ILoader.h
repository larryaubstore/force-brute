#ifndef I_LOADER_H
#define I_LOADER_H

#include "EDirection.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <map>


class ILoader
{
	public:
		//virtual int GetRelativePositionInTheMap(int position) = 0;

		virtual void changePosition(int position, DIRECTION direction) = 0;

		virtual SDL_Surface* getCurrentSDLSurface(int a_position, 
											      std::string a_domain) = 0; 
		virtual ~ILoader() {};


		virtual SDL_Surface* loadSDLSurface(std::string fileName) = 0;

};

#endif
