#ifndef I_GAME_MODEL_H
#define I_GAME_MODEL_H

#include <string>
#include <vector>

#include "EDirection.h"

#ifdef BOOST_ANDROID
	#include <boost/smart_ptr/shared_ptr.hpp>
#else
	#include <boost/shared_ptr.hpp>
#endif

#include "TypeDefEngine.h"


class IGameModel
{
	public:

		virtual int nextPosition() = 0;
		virtual void changeDirection(DIRECTION direction) = 0;

		virtual DIRECTION getDirection() = 0;
		virtual int getPosition() = 0; 
		virtual std::string getDomain() = 0; 
		virtual void changePosition(int position) = 0;
		virtual void changeVitesse(int vitesse) = 0;


		virtual std::string getMissileDomain() = 0;

		virtual void lanceMissile() = 0;

		virtual std::vector<PathMissilePtr> GetPathMissileList() = 0;

		virtual ~IGameModel() {};

};


#endif
