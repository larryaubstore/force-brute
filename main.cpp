#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <assert.h>
#include "Timer.h"
#include <vector>
#include <string>
#include <sstream>

#include "GameModelController.h"
#include "Loader.h"
#include "IFetcher.h"
#include "Fetcher.h"

#define WIDTH 1305 
#define HEIGHT 734 

//Screen attributes
const int SCREEN_WIDTH = 1305;
const int SCREEN_HEIGHT = 734;
const int SCREEN_BPP = 32;

const int FRAME_DIMENSION = 120;


#define VIDEOWIDTH 1305 
#define VIDEOHEIGHT 734 

//The frames per second
const int FRAMES_PER_SECOND = 30;

int counter = 0;

//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *message = NULL;
SDL_Surface *screen = NULL;

static GameModelController* controller = NULL;
static SDL_mutex *mutex = NULL;
static bool quit = false;
static SDL_Thread *threadChargementImage = NULL;
static bool imageChargee = false;



SDL_Event event;

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

int main( int argc, char* args[] )
{

	// Direction, position, grid_dimension, 
	GameModel* gameModel = new GameModel(DOWN, 0, 625, 
	"images/water",
	"images/missile"
	);

	Fetcher* fetcher = new Fetcher(30, 30, 
		"nothing");


	Loader* loader = new Loader(fetcher, 7, 30);
	loader->initialize(1);


    /*
     *  Initialise libSDL
     */
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD) == -1)
    {
        printf("cannot initialize SDL\n");
        return EXIT_FAILURE;
    }

    SDL_Surface *screen, *empty, *frame_surface, *layer;


    empty = SDL_CreateRGBSurface(SDL_SWSURFACE, VIDEOWIDTH, VIDEOHEIGHT,
                                 32, 0, 0, 0, 0);

	/*
    ctx.surf = SDL_CreateRGBSurface(SDL_SWSURFACE, VIDEOWIDTH, VIDEOHEIGHT,
                                    16, 0x001f, 0x07e0, 0xf800, 0);
									*/

    mutex = SDL_CreateMutex();

    //int options = SDL_ANYFORMAT | SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN;
    int options = SDL_ANYFORMAT | SDL_HWSURFACE | SDL_DOUBLEBUF;

    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 0, options);
    if(!screen)
    {
        printf("cannot set video mode\n");
        return EXIT_FAILURE;
    }


	controller = 
		new GameModelController((IGameModel*)gameModel, (ILoader*)loader, 
								(IFetcher*)fetcher, 
								screen, 
								empty);

	// Création du thread pour charger les images
	if ( (threadChargementImage=
		SDL_CreateThread(fonctionChargementImage, NULL)) == NULL )
	{
        printf("Impossible de créer le thread --> Chargement image\n");
        return EXIT_FAILURE;
	}


    //Quit flag
    quit = false;

    //The frame rate regulator
    Timer fps;

    while( quit == false )
    {
        //Start the frame timer
        fps.start();

		quit = controller->handleKeyEvent();

		controller->changePosition();

		if(imageChargee == true)
		{
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
    return 0;
}
