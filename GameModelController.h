#ifndef GAME_MODEL_CONTROLLER_H
#define GAME_MODEL_CONTROLLER_H

#include "SDL/SDL.h"
#include "GameModel.h"
#include "IGameModelController.h"
#include "IGameModel.h"
#include "ILoader.h"
#include "IFetcher.h"

#include "EDirection.h"
#include "SEvent.h"

#include "SDL/SDL.h"

#include <sstream>




class GameModelController : public IGameModelController
{

	private:
		IGameModel* m_gameModel;
		ILoader* m_loader;
		SDL_Surface* m_surface;
		SDL_Surface* m_screen;
		SDL_Surface* m_empty;
		SDL_Surface* m_missileSurface;

		int m_testMissile; 

		//void applySurfaceMissile();

	public:

		int nextPosition();
		//void handleKeyEvent(int keyCode);
		//void handleKeyEvent(SDL_KeyboardEvent *key);
		bool handleKeyEvent();


		SDL_Surface* getCurrentSurface();
		void changePosition();

		void freeSurfaces();
		void applySurfaces();
		void chargeSurface();
		void chargeSurfaceMissile();

		void flipSurfaces();

		GameModelController(IGameModel* gameModel, 
							ILoader* loader, 
							SDL_Surface* a_screen, 
							SDL_Surface* a_empty);
		~GameModelController();	

};



#endif
