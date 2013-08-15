#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL_rotozoom.h>

#include <string>
#include <assert.h>
#include "Timer.h"
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "SEvent.h"

#include "common/DynamicGrid.h"
#include "common/Tile.h"

#include <boost/assign/list_of.hpp>


#define WIDTH 960 
#define HEIGHT 540 

const int SCREEN_BPP = 32;
const int FRAME_DIMENSION = 120;
const int FRAMES_PER_SECOND = 30;

int counter = 0;
int currentFrame = 0;
int currentFrameCloud = 0;
int xPos = 0;
int yPos = 0;
int xPosClicked = 0;
int yPosClicked = 0;

//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *message = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *empty = NULL;
SDL_Surface *surface = NULL;
SDL_Surface *surfacePlat = NULL;
SDL_Surface *surfacePlatNonCarre = NULL;

SDL_Surface *layer = NULL;
SDL_Surface *zoomsurface = NULL;
SDL_Surface *cloudsurface = NULL;
SDL_Surface *zoommontagne = NULL;
SDL_Surface *zoomplatnoncarre = NULL;

//std::vector<SDL_Surface*> surfVector;
//
std::map <std::string, SDL_Surface*> surfMap;
std::vector <std::string> notLoadedSurfVector;

struct Position {
  int x;
  int y;
  std::string id;
  std::vector<int> frames;
  Position(int x, int y, std::string id) : x(x), y(y), id(id)  { }
  Position(int x, int y, std::string id, std::vector<int> frames) : x(x), y(y), id(id), frames(frames) { }
};

std::vector<Position> positionVector;


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
int shiftConstX = 0;
int shiftConstY = 0;
int permanentShiftX = 0;
int permanentShiftY = 0;

int xConst = 163;
int yConst = 72;
bool mouseClicked = false;

SDL_Surface* loadSDLSurface(std::string fileName) {
  SDL_Surface* surface;
  FILE *fp = fopen(fileName.data(), "rb");
  if( fp == NULL ) {
    SDL_SetError("Couldn't open %s", fp);
  } else {
    temp_rwop = SDL_RWFromFP(fp, 0);
    surface = IMG_Load_RW(temp_rwop, 0);

    SDL_FreeRW(temp_rwop);
    temp_rwop = NULL;
    fclose(fp);
    return surface;
  }
  return NULL;
}

void chargeSurface() {
  for (std::vector<std::string>::iterator it = notLoadedSurfVector.begin() ; it != notLoadedSurfVector.end(); ++it) {
    surfMap[(*it)] = loadSDLSurface((*it) + ".png");
  }
  notLoadedSurfVector.clear();
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
  bool result = false;
  ControllerEvent controllerEvent;
  memset(&controllerEvent, 0, sizeof(ControllerEvent));
  SDL_Event event;
  SDLMod mod;

  Uint8 mouseState = SDL_GetMouseState(&xPos, &yPos);

  int counterKeydown = 0;
  delta = 0;
  shiftX = 0;
  shiftY = 0;
  shiftConstY = 0;
  shiftConstX = 0;
  //mouseClicked = false;

  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN:
        counterKeydown++;
        controllerEvent.keyboard[event.key.keysym.sym] = 1;
        break;
      case SDL_KEYUP:
        controllerEvent.keyboard[event.key.keysym.sym] = 0;
        break;
      case SDL_MOUSEBUTTONDOWN:
        mouseClicked = true;
//        printf("X => %i\n", xPos);
//        printf("Y => %i\n", yPos);
//        printf("\n");
        break;
    }
  }

  if(controllerEvent.keyboard[SDLK_c] == 1 || xPos > (WIDTH - 100)) {
    //shiftX += 5;
  }

  if(controllerEvent.keyboard[SDLK_d] == 1 || xPos < (0 + 100)) {
    //shiftX -= 5;
  }

  if(yPos < 100) {
    //shiftY -= 5;
  }

  if(yPos > (HEIGHT - 100) ) {
    //shiftY += 5;
  }

  if(controllerEvent.keyboard[SDLK_a] == 1) {
    delta = -1;
  }

  if(controllerEvent.keyboard[SDLK_b] == 1) {
    delta = +1;
  }

  if(controllerEvent.keyboard[SDLK_c] == 1) {
    shiftConstY = -1;
  }

  if(controllerEvent.keyboard[SDLK_d] == 1) {
    shiftConstY = +1;
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

  int formatX = 0;
  int formatY = 0;


  for (std::vector<Position>::iterator it = positionVector.begin() ; it != positionVector.end(); ++it) {

    std::string idValue = (*it).id;

    if(idValue == "bateau/petitpoteau") {
      formatX = - (xPosClicked - 33);
      formatY = - (yPosClicked - 50);
    } else {
      formatX = - ((xConst * (*it).x) + permanentShiftX) * scalecon;
      formatY = - ((yConst * (*it).y) + permanentShiftY) * scalecon;
    }

    r.x = formatX;
    r.y = formatY;

    if(surfMap[idValue] == NULL) {
      notLoadedSurfVector.push_back(idValue);
    } else {
      if((*it).frames.size() > 0) {
        if(std::find((*it).frames.begin(), (*it).frames.end(), currentFrame) != (*it).frames.end()) {
          SDL_BlitSurface(surfMap[idValue] , &r, screen, NULL);
        }
      } else {
        SDL_BlitSurface(surfMap[idValue] , &r, screen, NULL);
      }
    }
  }
}

void flipSurfaces() {
  SDL_Flip(screen);
}



void freeSurfaces() {
  SDL_BlitSurface(empty, NULL, screen, NULL);
  if(surface != NULL) {
//    SDL_FreeSurface(zoomsurface);
//    SDL_FreeSurface(zoommontagne);
//    SDL_FreeSurface(zoomplatnoncarre);
    zoomsurface = NULL;
    zoommontagne = NULL;
    zoomplatnoncarre = NULL;
  }
}


int main( int argc, char* args[] ) {
 
  //positionVector.push_back(Position(0, 0, "bateau/grillefinal", [1, 2, 3]));

//  positionVector.push_back(Position(0, 0, "bateau/plan1f", boost::assign::list_of(1)(2)));
//  positionVector.push_back(Position(0, 0, "bateau/plan2f", boost::assign::list_of(3)(4)));
//  positionVector.push_back(Position(0, 0, "bateau/plan3f", boost::assign::list_of(5)(6)));
//  positionVector.push_back(Position(0, 0, "bateau/plan4f", boost::assign::list_of(7)(8)));
//  positionVector.push_back(Position(0, 0, "bateau/plan5f", boost::assign::list_of(9)(10)));
//  positionVector.push_back(Position(0, 0, "bateau/plan6f", boost::assign::list_of(11)(12)));
//  positionVector.push_back(Position(0, 0, "bateau/plan7f", boost::assign::list_of(13)(14)));
//  positionVector.push_back(Position(0, 0, "bateau/plan8f", boost::assign::list_of(15)(16)));
//  positionVector.push_back(Position(0, 0, "bateau/plan9f", boost::assign::list_of(17)(18)));
//  positionVector.push_back(Position(0, 0, "bateau/plan10f", boost::assign::list_of(19)(20)));
//  positionVector.push_back(Position(0, 0, "bateau/plan11f", boost::assign::list_of(21)(22)));
//  positionVector.push_back(Position(0, 0, "bateau/plan12f", boost::assign::list_of(23)(24)));
//  positionVector.push_back(Position(0, 0, "bateau/plan13f", boost::assign::list_of(25)(26)));
//  positionVector.push_back(Position(0, 0, "bateau/plan14f", boost::assign::list_of(27)(28)));
//  positionVector.push_back(Position(0, 0, "bateau/plan15f", boost::assign::list_of(29)(0)));

  positionVector.push_back(Position(0, 0, "bateau/plan1f", boost::assign::list_of(23)(22)));
  positionVector.push_back(Position(0, 0, "bateau/plan2f", boost::assign::list_of(24)(21)));
  positionVector.push_back(Position(0, 0, "bateau/plan3f", boost::assign::list_of(25)(20)));
  positionVector.push_back(Position(0, 0, "bateau/plan4f", boost::assign::list_of(26)(19)));
  positionVector.push_back(Position(0, 0, "bateau/plan5f", boost::assign::list_of(27)(18)));
  positionVector.push_back(Position(0, 0, "bateau/plan6f", boost::assign::list_of(28)(17)));
  positionVector.push_back(Position(0, 0, "bateau/plan7f", boost::assign::list_of(29)(16)));
  positionVector.push_back(Position(0, 0, "bateau/plan8f", boost::assign::list_of(0)(15)));
  positionVector.push_back(Position(0, 0, "bateau/plan9f", boost::assign::list_of(1)(14)));
  positionVector.push_back(Position(0, 0, "bateau/plan10f", boost::assign::list_of(2)(13)));
  positionVector.push_back(Position(0, 0, "bateau/plan11f", boost::assign::list_of(3)(12)));
  positionVector.push_back(Position(0, 0, "bateau/plan12f", boost::assign::list_of(4)(11)));
  positionVector.push_back(Position(0, 0, "bateau/plan13f", boost::assign::list_of(5)(10)));
  positionVector.push_back(Position(0, 0, "bateau/plan14f", boost::assign::list_of(6)(9)));
  positionVector.push_back(Position(0, 0, "bateau/plan15f", boost::assign::list_of(7)(8)));


  //positionVector.push_back(Position(0, 0, "bateau/justeplan_montagne"));
  //positionVector.push_back(Position(0, 0, "bateau/justegrille"));
  positionVector.push_back(Position(0, 0, "bateau/petitpoteau"));
  //positionVector.push_back(Position(0, 0, "bateau/petitpoteau"));
//  positionVector.push_back(Position(0, 0, "relief"));
//  positionVector.push_back(Position(1, 0, "relief"));
//  positionVector.push_back(Position(0, 1, "relief"));
//  positionVector.push_back(Position(1, 1, "relief"));
//
//  int tileOffset = 1;
//  positionVector.push_back(Position(0 + tileOffset, 0, "plat"));
//  positionVector.push_back(Position(1 + tileOffset, 0, "plat"));
//  positionVector.push_back(Position(0 + tileOffset, 1, "plat"));
//  positionVector.push_back(Position(1 + tileOffset, 1, "plat"));

  scalefactor = 325;

  /*
   *  Initialise libSDL
   */
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD) == -1) {
    printf("cannot initialize SDL\n");
    return EXIT_FAILURE;
  }

  empty = SDL_CreateRGBSurface(SDL_SWSURFACE, WIDTH, HEIGHT,
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

  SurfaceSharedPtr<SDL_Surface>::type surface_ptr;
  std::vector<TileSharedPtr> tile_vector;

  TileSharedPtr tile_ptr(new Tile(0, 0, 1.0d));
  tile_vector.push_back(tile_ptr);

  tile_ptr.reset(new Tile(1, 0, 1.0d));
  tile_vector.push_back(tile_ptr);

  tile_ptr.reset(new Tile(2, 0, 1.0d));
  tile_vector.push_back(tile_ptr);


  boost::shared_ptr< DynamicGrid  > dynamicGrid_ptr(new DynamicGrid(225, 
                                                                 101, 
                                                                 permanentShiftX, 
                                                                 permanentShiftY, 
                                                                 1.0d, 
                                                                 tile_vector));



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
      yConst += shiftConstY; 

      if(mouseClicked == true) {
        xPosClicked = xPos;
        yPosClicked = yPos;
        mouseClicked = false;
      }
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
