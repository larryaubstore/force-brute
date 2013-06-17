#ifndef LOADER_H
#define LOADER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <map>

//#include <memory> // for share_ptr

#include "IFetcher.h"

#ifdef BOOST_ANDROID
	#include <boost/smart_ptr/shared_ptr.hpp>
#else
	#include <boost/shared_ptr.hpp>
#endif

#include <vector>
#include "EDirection.h"
#include "ILoader.h"


//# using namespace std;

		struct ltint
		{
			bool operator()(int firstElement, int secondElement) const
		    {
		    	return firstElement == secondElement;
			}		
	  	};


class Loader : public ILoader
{


	private:


		SDL_RWops* temp_rwop;
		int m_position;
		int m_oldPosition;
		int m_buffer_dimension;
		int m_grid_dimension;
		DIRECTION m_direction;
		IFetcher* m_fetcher;


	public:
		Loader(IFetcher* fetcher, int buffer_dimension, int grid_dimension);
		~Loader();

		void changePosition(int position, DIRECTION direction);

		SDL_Surface* loadSDLSurface(std::string fileName);
		void initialize(int initialPosition);

		SDL_Surface* getCurrentSDLSurface(int a_position, std::string a_domain);




};


#endif
