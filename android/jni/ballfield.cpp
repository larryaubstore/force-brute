/*
 * "Ballfield"
 *
 *   (C) David Olofson <david@olofson.net>, 2002, 2003
 *
 * This software is released under the terms of the GPL.
 *
 * Contact author for permission if you want to use this
 * software, or work derived from it, under other terms.
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <android/log.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_screenkeyboard.h>

#include <GameModelController.h>
#include <Loader.h>
#include <IFetcher.h>
#include <Fetcher.h>
#include <Timer.h>

#define fprintf(X, ...) __android_log_print(ANDROID_LOG_INFO, "Ballfield", __VA_ARGS__)
#define printf(...) __android_log_print(ANDROID_LOG_INFO, "Ballfield", __VA_ARGS__)

/*----------------------------------------------------------
	Definitions...
----------------------------------------------------------*/

#define	SCREEN_W	640
#define	SCREEN_H	480

//The frames per second
const int FRAMES_PER_SECOND = 30;

/*----------------------------------------------------------
	main()
----------------------------------------------------------*/
static bool imageChargee = false;
static SDL_mutex *mutex = NULL;
static GameModelController* controller = NULL;
static SDL_Thread *threadChargementImage = NULL;
static bool quit = false;

int SDLCALL fonctionChargementImage(void *data)
{

	while(1)
	{
		if(imageChargee == false)
		{
			// LOCK
			if ( SDL_mutexP(mutex) < 0 ) {
				fprintf(stderr, "Couldn't lock mutex: %s", SDL_GetError());
				exit(1);
	    	}

			controller->chargeSurface();
			imageChargee = true;

			// UNLOCK
			if ( SDL_mutexV(mutex) < 0 ) {
				fprintf(stderr, "Couldn't unlock mutex: %s", SDL_GetError());
				exit(1);
			}
		}
		SDL_Delay(10);
	}
}

int main(int argc, char* argv[])
{
#include <android/log.h>

	__android_log_write(ANDROID_LOG_INFO, "LARRY", "Message LARRY");
	// Direction, position, grid_dimension, 
	GameModel* gameModel = new GameModel(IDLE, 1, 625, 
	"images/water",
	"images/missile"
	);

	Fetcher* fetcher = new Fetcher(30, 30, 
		"nothing");


	Loader* loader = new Loader(fetcher, 7, 30);
	loader->initialize(1);


	SDL_Surface* screen, *empty, *frame_surface, *layer;

	empty = SDL_CreateRGBSurface(SDL_SWSURFACE, SCREEN_W, SCREEN_H,
															 32, 0, 0, 0, 0);

	mutex = SDL_CreateMutex();

	int bpp = 16;
	int flags = SDL_HWSURFACE;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK);
	SDL_EnableUNICODE(1);

	atexit(SDL_Quit);

	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, bpp, flags);
	if(!screen)
	{
		fprintf(stderr, "Failed to open screen!\n");
		exit(-1);
	}

	controller = new GameModelController((IGameModel*)gameModel, (ILoader*)loader, screen, empty);

	// Création du thread pour charger les images
	if ( (threadChargementImage = SDL_CreateThread(fonctionChargementImage, NULL)) == NULL ) {
 		printf("Impossible de créer le thread --> Chargement image\n");
  	return EXIT_FAILURE;
	}

	//Quit flag
	quit = false;

	//The frame rate regulator
	Timer fps;
	while( quit == false ) {
		//Start the frame timer
		fps.start();

		quit = controller->handleKeyEvent();

		if(quit == true) {
			printf("FIN ...\n");
		}

		if(imageChargee == true && quit == false) {
			controller->applySurfaces();

			controller->flipSurfaces();

			controller->nextPosition();

			controller->freeSurfaces();

			if ( SDL_mutexP(mutex) < 0 ) {
				fprintf(stderr, "Couldn't lock mutex: %s", SDL_GetError());
				exit(1);
			}

			imageChargee = false;

			if ( SDL_mutexV(mutex) < 0 ) {
				fprintf(stderr, "Couldn't lock mutex: %s", SDL_GetError());
				exit(1);
			}

			if(  fps.get_ticks() < (1000 / FRAMES_PER_SECOND)  )
			{
				//Sleep the remaining frame time
				SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
			}
		}
	}

	SDL_WM_SetCaption("Ballfield", "Ballfield");
	if(flags & SDL_FULLSCREEN)
		SDL_ShowCursor(0);

	return 0;
}
