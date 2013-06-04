#include "GameModelController.h"
#include "EDirection.h"

bool GameModelController::handleKeyEvent()
{

	bool result = false;
	ControllerEvent controllerEvent;
	memset(&controllerEvent, 0, sizeof(ControllerEvent));
	SDL_Event event;
	SDLMod mod;
	int counterKeydown = 0;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_KEYDOWN:
				counterKeydown++;
				controllerEvent.keyboard[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				controllerEvent.keyboard[event.key.keysym.sym] = 0;
				break;
		}
	}

	int position = m_gameModel->getPosition();
	//int fetcherDirectory = m_fetcher->GetFetcherDirectory();


	if(controllerEvent.keyboard[SDLK_a] == 1)
	{

		m_gameModel->lanceMissile();
		// lance missile
		//m_gameModel->changeDirection(LEFT);
	}

	if(controllerEvent.keyboard[SDLK_LEFT] == 1)
	{
		m_gameModel->changeDirection(LEFT);
	}

	if(controllerEvent.keyboard[SDLK_RIGHT] == 1)
	{
		m_gameModel->changeDirection(RIGHT);
	}

	if(controllerEvent.keyboard[SDLK_UP] == 1)
	{
		m_gameModel->changeDirection(UP);
	}

	if(controllerEvent.keyboard[SDLK_DOWN] == 1)
	{
		m_gameModel->changeDirection(DOWN);
	}

	if(controllerEvent.keyboard[SDLK_LSHIFT] == 1 || 
		controllerEvent.keyboard[SDLK_RSHIFT] == 1)
	{
		m_gameModel->changeVitesse(4);
	}
	else
	{
		m_gameModel->changeVitesse(1);
	}


	if(controllerEvent.keyboard[SDLK_q] == 1)
	{
		result = true;
	}
		
	if(	controllerEvent.keyboard[SDLK_LEFT] == 1 && 
		controllerEvent.keyboard[SDLK_UP] == 1)
	{
		m_gameModel->changeDirection(LEFT_UP);
	}

	if(	controllerEvent.keyboard[SDLK_RIGHT] == 1 && 
		controllerEvent.keyboard[SDLK_UP] == 1)
	{
		m_gameModel->changeDirection(RIGHT_UP);
	}

	if(	controllerEvent.keyboard[SDLK_RIGHT] == 1 && 
		controllerEvent.keyboard[SDLK_DOWN] == 1)
	{
		m_gameModel->changeDirection(DOWN_RIGHT);
	}

	if(	controllerEvent.keyboard[SDLK_LEFT] == 1 && 
		controllerEvent.keyboard[SDLK_DOWN] == 1)
	{
		m_gameModel->changeDirection(LEFT_DOWN);
	}

	if(	controllerEvent.keyboard[SDLK_LEFT] == 1 && 
		controllerEvent.keyboard[SDLK_DOWN] == 1)
	{
		m_gameModel->changeDirection(LEFT_DOWN);
	}
	
	return result;
}

GameModelController::GameModelController(IGameModel* gameModel, 
										ILoader* loader,
										SDL_Surface* a_screen,
										SDL_Surface* a_empty
										)
{
	this->m_gameModel = gameModel;
	this->m_loader = loader;
	this->m_empty = a_empty;
	this->m_surface = NULL;
	this->m_screen = a_screen;

	this->m_testMissile = 1;
}

GameModelController::~GameModelController()
{

}

int GameModelController::nextPosition()
{
	return(m_gameModel->nextPosition());
}

void GameModelController::changePosition()
{

	int position = m_gameModel->getPosition();
	DIRECTION direction = m_gameModel->getDirection();
	m_loader->changePosition(position, direction);
}


void GameModelController::chargeSurface()
{
	/* CHARGE SURFACE */
	m_surface = m_loader->getCurrentSDLSurface(m_gameModel->getPosition(), 
											 m_gameModel->getDomain());

	/* CHARGE SEULEMENT */
	//applySurfaceMissile();
	chargeSurfaceMissile();

}



void GameModelController::applySurfaces()
{

	// Appliquer surface de base
    if(m_surface != NULL)
    {
    	SDL_BlitSurface(m_surface, NULL, m_screen, NULL);
    }   
	else
	{
		printf("SURFACE NULL !!!!! %i\n", m_gameModel->getPosition());
	}


	// Appliquer missile
	//if(m_missileSurface != NULL)
	//{
  // 		SDL_BlitSurface(m_missileSurface, NULL, m_screen, NULL);
	//}
}

//void GameModelController::applySurfaceMissile()
void GameModelController::chargeSurfaceMissile()
{


	IPathMissile* missile = NULL;                 
	PathMissilePtr missilePtr; 

	for(int i = 0; i < m_gameModel->GetPathMissileList().size(); i++)
	{
		missilePtr = m_gameModel->GetPathMissileList()[0];  //
		missile = missilePtr.get();                 
	}

/***************************/

	std::string result;
	/*
	if(m_testMissile >= 120)
	{
		m_testMissile = 1;
	}
	else
	{
		m_testMissile+=6;
	}*/

	if(missile != NULL)
	{
		m_testMissile = missile->getPosition();

		std::string index;
		std::stringstream out;
		out.str("");
		out << m_testMissile;


		if(m_testMissile < 10)
		{
			index = "/000";
		}
		else if(m_testMissile < 100)
		{
			index = "/00";
		}
		else
		{
			index = "/0";
		}

		result = "images/missile2" + index 
			+ out.str() + ".png";

		m_missileSurface = IMG_Load(result.c_str());

		if(m_missileSurface != NULL)
		{

			SDL_Surface* optimizedImage = m_missileSurface;	

			Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 
				0, 0xFF, 0xFF );
			SDL_SetColorKey( optimizedImage, 
			SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
		}	
	}
}



void GameModelController::freeSurfaces()
{
	SDL_BlitSurface(m_empty, NULL, m_screen, NULL);
	if(m_surface != NULL)
	{
		SDL_FreeSurface(m_surface);
		m_surface = NULL;
	}

	/*
	if(m_missileSurface != NULL)
	{
		SDL_FreeSurface(m_missileSurface);
		m_missileSurface = NULL;
	}
	*/
}


void GameModelController::flipSurfaces()
{
	SDL_Flip(m_screen);
}




