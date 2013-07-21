#ifndef I_CONFIG_FILE_READER_H
#define I_CONFIG_FILE_READER_H

#include "TypeDefEngine.h"

class IConfigFileReader
{
	public:

//		virtual void changePosition(int position, DIRECTION direction) = 0;
//		virtual SDL_Surface* getCurrentSDLSurface(int a_position, 
//											      std::string a_domain) = 0; 
//		virtual SDL_Surface* loadSDLSurface(std::string fileName) = 0;

    virtual ~IConfigFileReader() {};

    virtual std::vector<TileSharedPtr> ReadFile() = 0;
};

#endif
