#ifndef LOADER_MOCK_H
#define LOADER_MOCK_H

#include <mockpp/mockpp.h> 
#include <mockpp/MockObject.h>
#include <mockpp/ExpectationList.h>
#include <mockpp/ReturnObjectList.h>
#include <mockpp/ExpectationCounter.h>


#include <mockpp/constraint/ConstraintList.h>

#include "SDL/SDL.h"

#include <ILoader.h>
#include <EDirection.h>

#include <exception>
#include <iostream>


USING_NAMESPACE_MOCKPP

                                                                                        
class LoaderMock : public ILoader
                	, public MOCKPP_NS::MockObject
{

	public:
		LoaderMock() : 
			MOCKPP_NS::MockObject(MOCKPP_PCHAR("LoaderMock"), 0)
		{



		}

		virtual void changePosition(int position, DIRECTION direction)
		{

		}

		virtual std::map<int, SDL_Surface*> *  getMapSurfaceGrid()
		{
			return 0;
		}

		SDL_Surface* getCurrentSDLSurface(int a_position, std::string a_domain)
		{
			return NULL;
		}


		virtual SDL_Surface* loadSDLSurface(std::string fileName)
		{

		}


};

#endif                 
