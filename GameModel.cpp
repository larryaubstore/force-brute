
#include "GameModel.h"
#include <stdio.h>
#include "PathMissile.h"
#include "TypeDefEngine.h"



GameModel::GameModel(DIRECTION a_direction, 
					 int a_position, 
					 int a_grid_dimension, 
					 std::string a_domain, 
					 std::string a_missileDomain)
{
	this->m_direction = a_direction;
	this->m_position = a_position;
	this->m_grid_dimension = a_grid_dimension;
	this->m_vitesse = 1;
	this->m_domain = a_domain;
	this->m_missileDomain = a_missileDomain;

}

void GameModel::changeDirection(DIRECTION direction)
{
	this->m_direction = direction;
}

void GameModel::changePosition(int position)
{
	this->m_position = position;
}

void GameModel::changeVitesse(int vitesse)
{
	this->m_vitesse = vitesse;
}


int GameModel::nextPosition()
{

	/* m_grid_dimension = 3 */
	/*
		| 01 | 04 | 07 |
		| 02 | 05 | 08 |
		| 03 | 06 | 09 |
	*/

	switch(this->m_direction)
	{
		case DOWN:

			// Patch to solve the event queue problem.
			// The event queue is not empty at the beginning even if no keys
			// are pressed. 
			if(m_position > (1 * m_vitesse) ) {
				m_position = m_position - (1 * m_vitesse );
			}
			break;
		case DOWN_RIGHT:
			m_position = m_position + ((m_grid_dimension - 1) * m_vitesse );
			break;
		case RIGHT:
			m_position = m_position + (m_grid_dimension * m_vitesse );
			break;
		case RIGHT_UP:
			m_position = m_position + ((m_grid_dimension + 1) * m_vitesse);
			//printf("POSITION ---> %i\n", m_position);
			break;
		case UP:
			m_position = m_position + (1 * m_vitesse );
			break;
		case LEFT_UP:
			m_position = m_position - ((m_grid_dimension - 1) * m_vitesse  );
			//printf("POSITION ---> %i\n", m_position);
			break;
		case LEFT:
			m_position = m_position - ( m_grid_dimension * m_vitesse );
			break;
		case LEFT_DOWN:
			m_position = m_position - ((m_grid_dimension + 1) * m_vitesse );
			break;
		default:
			break;
	}
	this->m_direction = IDLE;

	// Mettre à jour les missiles
	updateMissilePosition();

	return m_position;
}

void GameModel::updateMissilePosition()
{
	PathMissilePtr pathMissileElement;

	IPathMissile* missile = NULL;

	// Parcourir la liste de tous les missiles
	for(int i = 0; i < m_pathMissileList.size(); i++)
	{
		pathMissileElement = m_pathMissileList[i];

		// Mettre à jour les coordonnées du missile
		nextMissilePosition(pathMissileElement);

		missile = pathMissileElement.get();
		// Vérifier si le missile est à la fin de sa trajectoire
		if(missile->getPosition() >= missile->getEndPosition())
		{
			// Détruire le missile
			m_pathMissileList.erase( m_pathMissileList.begin() + i );
		}
	}
}


void GameModel::nextMissilePosition(PathMissilePtr a_missilePtr)
{

	IPathMissile* missile = a_missilePtr.get();
	int pos = missile->getPosition();

	switch(missile->getDirection())
	{
		case DOWN:
		
			missile->setPosition(pos - 1);
			//m_position = m_position - (1 * m_vitesse );
			break;
		case DOWN_RIGHT:
			//m_position = m_position + ((m_grid_dimension - 1) * m_vitesse );
			break;
		case RIGHT:
			missile->setPosition(pos + m_grid_dimension);
			//m_position = m_position + (m_grid_dimension * m_vitesse );
			break;
		case RIGHT_UP:
			//m_position = m_position + ((m_grid_dimension + 1) * m_vitesse);
			break;
		case UP:
			missile->setPosition(pos + 4);
			//m_position = m_position + (1 * m_vitesse );
			break;
		case LEFT_UP:
			//m_position = m_position - ((m_grid_dimension - 1) * m_vitesse  );
			break;
		case LEFT:
			missile->setPosition(pos - m_grid_dimension);
			//m_position = m_position - ( m_grid_dimension * m_vitesse );
			break;
		case LEFT_DOWN:
			//m_position = m_position - ((m_grid_dimension + 1) * m_vitesse );
			break;
		default:
			break;
	}
}


void GameModel::lanceMissile()
{
	PathMissile* pathMissile; 
	if(m_pathMissileList.size() == 0)
	{

		printf("lance missile %i\n", m_position);
		/*
		PathMissilePtr ptr(new PathMissile(m_position, 
										   m_position, 
										   m_position + 120, UP));
										   */
		PathMissilePtr ptr(new PathMissile(1, 
										   1, 
										   120, UP));
		m_pathMissileList.push_back(ptr);
	}
}


DIRECTION GameModel::getDirection()
{
	return this->m_direction;
}

int GameModel::getPosition()
{
	return this->m_position;
}

std::string GameModel::getDomain()
{
	return this->m_domain;
}

std::string GameModel::getMissileDomain()
{
	return this->m_missileDomain;
}

std::vector<PathMissilePtr> GameModel::GetPathMissileList()
{
	return this->m_pathMissileList;
}


