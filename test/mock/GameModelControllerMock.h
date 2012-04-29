#ifndef GAME_MODEL_CONTROLLER_MOCK_H
#define GAME_MODEL_CONTROLLER_MOCK_H

#include <mockpp/mockpp.h> 
#include <mockpp/MockObject.h>
#include <mockpp/ExpectationList.h>
#include <mockpp/ReturnObjectList.h>
#include <mockpp/ExpectationCounter.h>


#include <mockpp/constraint/ConstraintList.h>


#include <IGameModelController.h>

#include <exception>
#include <iostream>

//#include "mock/GameModelControllerMock.h"

USING_NAMESPACE_MOCKPP

                                                                                        
class GameModelControllerMock : public IGameModelController
                	, public MOCKPP_NS::MockObject
{

	public:
		GameModelControllerMock() : 
			MOCKPP_NS::MockObject(MOCKPP_PCHAR("GameModelControllerMock"), 0),
			handleKeyEvent_name(MOCKPP_PCHAR("GameModelController/handleKeyEvent_name"), this)
		{



		}

		virtual bool handleKeyEvent()
		{
			return false;
		}

		virtual int nextPosition()
		{


		}

		virtual void lanceMissile()
		{

		}

		virtual void chargeSurface()
		{

		}

		virtual void chargeSurfaceMissile()
		{

		}

		virtual void applySurfaces()
		{

		}

		virtual void freeSurfaces()
		{

		}

		virtual void flipSurfaces()
		{

		}

	MOCKPP_NS::ExpectationList<int>  handleKeyEvent_name;
};

#endif                 
