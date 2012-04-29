#include "Loader.h"


/**
* @brief Constructor
*/
Loader::Loader(IFetcher* fetcher, int buffer_dimension, int grid_dimension)
{
	this->m_fetcher = fetcher;
	this->m_buffer_dimension = buffer_dimension;
	this->m_grid_dimension = grid_dimension;
}

Loader::~Loader()
{

}

void Loader::initialize(int initialPosition)
{
	this->m_position = initialPosition;
}

void Loader::changePosition(int position, DIRECTION direction)
{

	this->m_oldPosition = m_position;
	this->m_direction = direction;	
	this->m_position = position;
}

SDL_Surface* Loader::loadSDLSurface(std::string fileName)
{
	SDL_Surface* surface;
	FILE *fp = fopen(fileName.data(), "rb");
	if( fp == NULL ) {
		SDL_SetError("Couldn't open %s", fp);
	}
	else
	{
		temp_rwop = SDL_RWFromFP(fp, 0);
		surface = IMG_LoadJPG_RW(temp_rwop);

		SDL_FreeRW(temp_rwop);
		temp_rwop = NULL;
		fclose(fp);
		return surface;
	}
	return NULL;
}

SDL_Surface* Loader::getCurrentSDLSurface(int a_position, std::string a_domain)
{
	m_fetcher->SetPrefix(a_domain);
	// Get file name
	std::string fileNameLinkedToPosition = 
		m_fetcher->GetFileNameLinkedToPosition(a_position);
	// Get surface
	return(this->loadSDLSurface(fileNameLinkedToPosition));
}

