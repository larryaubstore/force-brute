#include "PathMissile.h"


int PathMissile::getStartPosition()
{
	return m_startPosition;
}

void PathMissile::setStartPosition(int a_startPosition)
{
	m_startPosition = a_startPosition;
}


int PathMissile::getPosition()
{
	return m_position;
}

void PathMissile::setPosition(int a_position)
{
	m_position = a_position;
}


int PathMissile::getEndPosition()
{
	return m_endPosition;
}

void PathMissile::setEndPosition(int a_endPosition)
{
	m_endPosition = a_endPosition;
}

PathMissile::PathMissile(int a_startPosition, 
						 int a_position, 
						 int a_endPosition,
						 DIRECTION a_direction)
{

	this->m_startPosition = a_startPosition;
	this->m_position = a_position;
	this->m_endPosition = a_endPosition;
	this->m_direction = a_direction;
}

void PathMissile::setDirection(DIRECTION a_direction)
{
	this->m_direction = a_direction;
}

DIRECTION PathMissile::getDirection()
{
	return m_direction;
}

