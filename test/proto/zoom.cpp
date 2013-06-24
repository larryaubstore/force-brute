#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <assert.h>
#include "Timer.h"
#include <vector>
#include <string>
#include <sstream>


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
SDL_Surface *empty = NULL;
SDL_Surface *surface = NULL;
SDL_Surface *layer = NULL;
SDL_RWops* temp_rwop;

static SDL_mutex *mutex = NULL;
static bool quit = false;
static SDL_Thread *threadChargementImage = NULL;
static bool imageChargee = false;

SDL_Event event;

SDL_Surface* loadSDLSurface(std::string fileName)
{
	SDL_Surface* surface;
	FILE *fp = fopen(fileName.data(), "rb");
	if( fp == NULL ) {
		SDL_SetError("Couldn't open %s", fp);
	}
	else
	{
		temp_rwop = SDL_RWFromFP(fp, 0);
		surface = IMG_LoadJPG_RW(temp_rwop);

		SDL_FreeRW(temp_rwop);
		temp_rwop = NULL;
		fclose(fp);
		return surface;
	}
	return NULL;
}

void chargeSurface()
{
	surface = loadSDLSurface("monkey0001.jpg"); 
	//chargeSurfaceMissile();
}

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

			chargeSurface();
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

bool handleKeyEvent() {
	return false;
}

void applySurfaces()
{

	// Appliquer surface de base
	if(surface != NULL)
	{
		SDL_BlitSurface(surface, NULL, screen, NULL);
	} else {
		printf("SURFACE NULL !!!!! \n");
	}
}

void flipSurfaces()
{
	SDL_Flip(screen);
}



void freeSurfaces()
{
	SDL_BlitSurface(empty, NULL, screen, NULL);
	if(surface != NULL)
	{
		SDL_FreeSurface(surface);
		surface = NULL;
	}
}


int main( int argc, char* args[] )
{
	/*
	 *  Initialise libSDL
	 */
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD) == -1)
	{
			printf("cannot initialize SDL\n");
			return EXIT_FAILURE;
	}



	empty = SDL_CreateRGBSurface(SDL_SWSURFACE, VIDEOWIDTH, VIDEOHEIGHT,
															 32, 0, 0, 0, 0);

	mutex = SDL_CreateMutex();

	//int options = SDL_ANYFORMAT | SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN;
	int options = SDL_ANYFORMAT | SDL_HWSURFACE | SDL_DOUBLEBUF;

	screen = SDL_SetVideoMode(WIDTH, HEIGHT, 0, options);
	if(!screen)
	{
		printf("cannot set video mode\n");
		return EXIT_FAILURE;
	}

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

		quit = handleKeyEvent();

		if(quit == true) {
			printf("FIN ...\n");
		}

		if(imageChargee == true && quit == false) {

			applySurfaces();

			flipSurfaces();

			freeSurfaces();

//			controller->applySurfaces();
//
//			controller->flipSurfaces();
//
//			controller->nextPosition();
//
//			controller->freeSurfaces();

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
