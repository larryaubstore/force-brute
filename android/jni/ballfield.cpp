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

#define fprintf(X, ...) __android_log_print(ANDROID_LOG_INFO, "Ballfield", __VA_ARGS__)
#define printf(...) __android_log_print(ANDROID_LOG_INFO, "Ballfield", __VA_ARGS__)

/*----------------------------------------------------------
	Definitions...
----------------------------------------------------------*/

#define	SCREEN_W	640
#define	SCREEN_H	480


/*----------------------------------------------------------
	main()
----------------------------------------------------------*/
static bool imageChargee = false;
static SDL_mutex *mutex = NULL;
static GameModelController* controller = NULL;

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
	// Direction, position, grid_dimension, 
	GameModel* gameModel = new GameModel(IDLE, 1, 625, 
	"images/water",
	"images/missile"
	);

	Fetcher* fetcher = new Fetcher(30, 30, 
		"nothing");


	Loader* loader = new Loader(fetcher, 7, 30);
	loader->initialize(1);


	SDL_Surface* screen;
	int bpp = 16;
	int flags = SDL_HWSURFACE;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK);
	SDL_EnableUNICODE(1);

	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, bpp, flags);
	if(!screen)
	{
		fprintf(stderr, "Failed to open screen!\n");
		exit(-1);
	}

	SDL_WM_SetCaption("Ballfield", "Ballfield");
	if(flags & SDL_FULLSCREEN)
		SDL_ShowCursor(0);

	return 0;
}
