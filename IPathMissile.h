#ifndef I_PATH_MISSILE_H
#define I_PATH_MISSILE_H

#include "EDirection.h"
#include <string>

class IPathMissile
{
	public:


		
		virtual DIRECTION getDirection() = 0;
		virtual void setDirection(DIRECTION a_direction) = 0;

		virtual int getStartPosition() = 0;
		virtual void setStartPosition(int a_position) = 0;

		virtual int getPosition() = 0;
		virtual void setPosition(int a_position) = 0;

		virtual int getEndPosition() = 0;
		virtual void setEndPosition(int a_position) = 0;


		virtual ~IPathMissile() {};

};


#endif
