#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL_rotozoom.h>

#include <string>
#include <assert.h>
#include "Timer.h"
#include <vector>
#include <string>
#include <sstream>
#include "SEvent.h"


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
int currentFrame = 0;
int currentFrameCloud = 0;

//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *message = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *empty = NULL;
SDL_Surface *surface = NULL;
SDL_Surface *surfacePlat = NULL;
SDL_Surface *layer = NULL;
SDL_Surface *zoomsurface = NULL;
SDL_Surface *cloudsurface = NULL;
SDL_Surface *zoommontagne = NULL;


std::vector<SDL_Surface*> surfVector;

SDL_RWops* temp_rwop;


static SDL_mutex *mutex = NULL;
static bool quit = false;
static SDL_Thread *threadChargementImage = NULL;
static bool imageChargee = false;

SDL_Event event;
int scalefactor = 0;
int delta = 0;
int shiftX = 0;
int shiftY = 0;
int permanentShiftX = 0;
int permanentShiftY = 0;

SDL_Surface* loadSDLSurface(std::string fileName) {
  SDL_Surface* surface;
  FILE *fp = fopen(fileName.data(), "rb");
  if( fp == NULL ) {
    SDL_SetError("Couldn't open %s", fp);
  } else {
    temp_rwop = SDL_RWFromFP(fp, 0);
    //surface = IMG_LoadJPG_RW(temp_rwop);
    surface = IMG_Load_RW(temp_rwop, 0);

    SDL_FreeRW(temp_rwop);
    temp_rwop = NULL;
    fclose(fp);
    return surface;
  }
  return NULL;
}

void chargeSurface() {
  if(surface == NULL) {
    printf("LOAD\n");
    surface = loadSDLSurface("0001.png"); 
  }

  if(surfacePlat == NULL) {
    printf("LOAD\n");
    surfacePlat = loadSDLSurface("0002.png"); 
  }
  

  if(cloudsurface == NULL) {
    printf("CLOUD\n");
    cloudsurface = loadSDLSurface("cloudguru2.png");
  }

  if(surfVector.size() < 10) {
    surfVector.push_back(loadSDLSurface("guru/0001.png"));
    surfVector.push_back(loadSDLSurface("guru/0002.png"));
    surfVector.push_back(loadSDLSurface("guru/0003.png"));
    surfVector.push_back(loadSDLSurface("guru/0004.png"));
    surfVector.push_back(loadSDLSurface("guru/0005.png"));
    surfVector.push_back(loadSDLSurface("guru/0006.png"));
    surfVector.push_back(loadSDLSurface("guru/0007.png"));
    surfVector.push_back(loadSDLSurface("guru/0008.png"));
    surfVector.push_back(loadSDLSurface("guru/0009.png"));
    surfVector.push_back(loadSDLSurface("guru/0010.png"));
  }
}

int SDLCALL fonctionChargementImage(void *data) {

  while(1) {
    if(imageChargee == false) {
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
  //return false;
  //
  bool result = false;
  ControllerEvent controllerEvent;
  memset(&controllerEvent, 0, sizeof(ControllerEvent));
  SDL_Event event;
  SDLMod mod;

  int xPos = 0;
  int yPos = 0;
  Uint8 mouseState = SDL_GetMouseState(&xPos, &yPos);

  int counterKeydown = 0;
  delta = 0;
  shiftX = 0;
  shiftY = 0;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN:
        counterKeydown++;
        controllerEvent.keyboard[event.key.keysym.sym] = 1;
        break;
      case SDL_KEYUP:
        controllerEvent.keyboard[event.key.keysym.sym] = 0;
        break;
    }
  }

  //printf("X => %i Y => %i\n", xPos, yPos);
  //scalefactor = 0;
  if(controllerEvent.keyboard[SDLK_UP] == 1) {

    //scalefactor = 1;
    //m_gameModel->changeDirection(UP);
  }

  if(controllerEvent.keyboard[SDLK_DOWN] == 1) {
    //scalefactor = -1;
    //m_gameModel->changeDirection(DOWN);
  }

  if(controllerEvent.keyboard[SDLK_c] == 1 || xPos > (VIDEOWIDTH - 100)) {
    shiftX += 5;
    //scalefactor = -1;
    //m_gameModel->changeDirection(DOWN);
  }

  if(controllerEvent.keyboard[SDLK_d] == 1 || xPos < (0 + 100)) {
    shiftX -= 5;
    //scalefactor = -1;
    //m_gameModel->changeDirection(DOWN);
  }

  if(yPos < 100) {
    shiftY -= 5;
  }

  if(yPos > (VIDEOHEIGHT - 100) ) {
    shiftY += 5;
  }


  if(controllerEvent.keyboard[SDLK_a] == 1) {
    delta = -1;
    //scalefactor -= 1;
    //SDL_Delay(1);
  }

  if(controllerEvent.keyboard[SDLK_b] == 1) {
    delta = +1;
    //scalefactor += 1;
    //SDL_Delay(1);
  }


  if(controllerEvent.keyboard[SDLK_q] == 1) {
    result = true;
  }
  return result;
}

void applySurfaces() {
  SDL_Rect r;
  r.x = 0;
  r.y = 0;
  r.w = 1920;
  r.h = 1080;

  SDL_Rect rzoom;
  rzoom.x = 0;
  rzoom.y = 0;
  rzoom.w = 1920 / 4;
  rzoom.h = 1080 / 4;

  double scalecon = scalefactor  / 500.0f;

// Appliquer surface de base
  if(surface != NULL) {
//cloudsurface =  surfVector[currentFrameCloud];
//if( (currentFrame  % 3) == 0) {
//currentFrameCloud = (currentFrameCloud + 1) % 10;
//}
//zoomcloud = rotozoomSurface(cloudsurface, 0, scalecon, 1);

    zoomsurface = rotozoomSurface(surface, 0, scalecon, 1);
    zoommontagne = rotozoomSurface(surfacePlat, 0, scalecon, 1);

    int xConst = 225;
    int yConst = 101;

    for(int i = -1; i < 6; i++) {
      for(int j = -1; j < 7; j++) {
        r.x = - ((xConst *  i) + permanentShiftX) * scalecon;
        r.y = - ((yConst * j) + permanentShiftY) * scalecon;
        SDL_BlitSurface(zoommontagne, &r, screen, NULL);
      }
    }

    for(int i = -1; i < 6; i++) {
      for(int j = -1; j < 7; j++) {
        r.x = - ((xConst *  i) - (225 / 2 ) + permanentShiftX) * scalecon;
        r.y = - ((yConst * j) - (101 / 2 ) + permanentShiftY) * scalecon;
        SDL_BlitSurface(zoomsurface, &r, screen, NULL);
      }
    }
  } else {
    printf("SURFACE NULL !!!!! \n");
  }
}

void flipSurfaces() {
  SDL_Flip(screen);
}



void freeSurfaces() {
  SDL_BlitSurface(empty, NULL, screen, NULL);
  if(surface != NULL) {
    //SDL_FreeSurface(surface);
    SDL_FreeSurface(zoomsurface);
    SDL_FreeSurface(zoommontagne);
    //surface = NULL;
    zoomsurface = NULL;
    zoommontagne = NULL;
  }
}


int main( int argc, char* args[] ) {

  scalefactor = 500 /*64*/;
  /*
   *  Initialise libSDL
   */
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD) == -1) {
    printf("cannot initialize SDL\n");
    return EXIT_FAILURE;
  }



  empty = SDL_CreateRGBSurface(SDL_SWSURFACE, VIDEOWIDTH, VIDEOHEIGHT,
     32, 0, 0, 0, 0);

  mutex = SDL_CreateMutex();

  int options = SDL_ANYFORMAT | SDL_HWSURFACE | SDL_DOUBLEBUF /*| SDL_FULLSCREEN*/;

  screen = SDL_SetVideoMode(WIDTH, HEIGHT, 0, options);
  if(!screen) {
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

      scalefactor += delta;
      permanentShiftX += shiftX;
      permanentShiftY += shiftY;
      applySurfaces();

      flipSurfaces();

      freeSurfaces();

      if ( SDL_mutexP(mutex) < 0 ) {
        fprintf(stderr, "Couldn't lock mutex: %s", SDL_GetError());
        exit(1);
      }

      imageChargee = false;

      if ( SDL_mutexV(mutex) < 0 ) {
        fprintf(stderr, "Couldn't lock mutex: %s", SDL_GetError());
        exit(1);
      }

      currentFrame = (currentFrame + 1) % 30;

      if(  fps.get_ticks() < (1000 / FRAMES_PER_SECOND)  ) {
        //Sleep the remaining frame time
        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
      }
    }
  }
  return 0;
}
