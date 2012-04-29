#ifndef GAME_MODEL_CONTROLLER_TEST_H
#define GAME_MODEL_CONTROLLER_TEST_H

#include <mockpp/mockpp.h> 

#include <mockpp/MockObject.h>
#include <mockpp/ExpectationList.h>
#include <mockpp/ReturnObjectList.h>
#include <mockpp/ExpectationCounter.h>


#include "mock/GameModelControllerMock.h"
#include "mock/GameModelMock.h"
#include "mock/LoaderMock.h"
#include "mock/FetcherMock.h"

#include <IGameModelController.h>
#include <GameModelController.h>
#include <EDirection.h>

#include <cpptest.h>

#include <exception>
#include <iostream>

#include <GameModel.h>

#include <EDirection.h>


                                                                                        
class GameModelControllerTest : public Test::Suite
{

	public:
		GameModelControllerTest() 
		{
			//TEST_ADD(GameModelControllerTest::testHandleKeyEvent);
			//TEST_ADD(GameModelControllerTest::testCommunicationWithGameModel);

			TEST_ADD(GameModelControllerTest::testPathMissile);
			TEST_ADD(GameModelControllerTest::testMissileAutoDestruction);

		}

	private:
		
		void testHandleKeyEvent();
		void testCommunicationWithGameModel();

		void testPathMissile();
		void testMissileAutoDestruction();
};


#endif                 
