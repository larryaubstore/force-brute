#ifndef PATHMISSILE_H
#define PATHMISSILE_H

#include "EDirection.h"
#include "IPathMissile.h"

class PathMissile : public IPathMissile
{

	private:

		int m_startPosition;

		int m_position;

		int m_endPosition;

		DIRECTION m_direction;

	public:

		PathMissile()
		{

		}

		PathMissile(int a_startPosition, 
					int a_position, 
					int a_endPosition,
					DIRECTION a_direction);



		int getStartPosition();
		void setStartPosition(int a_startPosition);

		int getPosition();
		void setPosition(int a_position);

		int getEndPosition();
		void setEndPosition(int a_endPosition);

		void setDirection(DIRECTION a_direction);
		DIRECTION getDirection();

		//PathMissile (const PathMissile& path);

		~PathMissile()
		{

		}
};

#endif
