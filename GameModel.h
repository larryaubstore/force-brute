#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "EDirection.h"
#include "IGameModel.h"
#include "IRuleFetcher.h"

#include "PathMissile.h"

#include "TypeDefEngine.h"


/**
* @brief This class holds all information about the game.
*/
class GameModel : public IGameModel
{

	private:


		IRuleFetcher* m_ruleFetcher;

		/**
		* @brief This is the member for the current direction.
		*/
		DIRECTION m_direction;

		/**
		* @brief This is the member for the current position;
		*/
		int m_position;

		int m_grid_dimension;

		int m_vitesse;

		std::string m_domain;

		std::string m_missileDomain;

		std::vector<PathMissilePtr> m_pathMissileList;

		void updateMissilePosition();

		void nextMissilePosition(PathMissilePtr a_missilePtr);
		


	public:

		/**
		* @brief  Constructor
		*
		* @param m_direction Initial direction.
		* @param m_position Initial position.
		* @param m_grid_dimension Grid dimension
		* @param m_missileDomain Missile Domain
		*/
		GameModel(DIRECTION a_direction, 
				  int a_position, 
				  int a_grid_dimension,
				  std::string a_domain, 
				  std::string a_missileDomain);

		/**
		* @brief This method returns the next position index.
		*
		* @return Next position index
		*/
		int nextPosition();

		void changeDirection(DIRECTION direction);
		void changePosition(int position);
		void changeVitesse(int vitesse);

		DIRECTION getDirection();
		int getPosition();
		std::string getDomain();
		std::string getMissileDomain();

		void lanceMissile();

		std::vector <PathMissilePtr > GetPathMissileList();

};

#endif
