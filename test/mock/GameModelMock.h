#ifndef GAME_MODEL_MOCK_H
#define GAME_MODEL_MOCK_H

#include <mockpp/mockpp.h> 
#include <mockpp/MockObject.h>
#include <mockpp/ExpectationList.h>
#include <mockpp/ReturnObjectList.h>
#include <mockpp/ExpectationCounter.h>


#include <mockpp/constraint/ConstraintList.h>

#include "SDL/SDL.h"

#include <IGameModel.h>
#include <EDirection.h>

#include <exception>
#include <iostream>

#include "TypeDefEngine.h"

USING_NAMESPACE_MOCKPP

                                                                                        
class GameModelMock : public IGameModel
                	, public MOCKPP_NS::MockObject
{

	public:
		GameModelMock() : 
			MOCKPP_NS::MockObject(MOCKPP_PCHAR("GameModelMock"), 0),
			changeDirection_name(MOCKPP_PCHAR("GameModel/changeDirection_name"), this)
		{



		}

		virtual void changeDirection(DIRECTION direction)
		{
			changeDirection_name.addActual(direction);
		}

		virtual int nextPosition()
		{


		}

		virtual DIRECTION getDirection()
		{
			return LEFT;
		}

		virtual int getPosition()
		{
			return 0;
		}

		virtual void changePosition(int position)
		{

		}

		virtual void changeVitesse(int vitesse)
		{

		}

		virtual std::string getDomain()
		{

		}

		virtual std::string getMissileDomain()
		{

		}

		virtual void lanceMissile()
		{

		}

		virtual std::vector<PathMissilePtr> GetPathMissileList()
		{

		}



	MOCKPP_NS::ExpectationList<int>  changeDirection_name;
};

#endif                 
