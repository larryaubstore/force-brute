#include <SDL.h>

#include <SDL_image.h>

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
int currentFrame240 = 0;
int currentFrame480 = 0;
int currentFrame960 = 0;
int currentFrameCloud = 0;

int xPos = 0;
int yPos = 0;
int xPosClicked = 0;
int yPosClicked = 0;

//The surfaces
SDL_Window * screen = NULL;
SDL_Renderer *sdlRenderer;

std::map <std::string, SDL_Texture*> surfMap;
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


SDL_Texture* loadSDLSurface(std::string fileName) {

  printf("-- %s\n", fileName.data()); 
  SDL_Texture* texture = IMG_LoadTexture(sdlRenderer, fileName.data());
  return(texture);
}

void chargeSurface() {
  for (std::vector<std::string>::iterator it = notLoadedSurfVector.begin() ; it != notLoadedSurfVector.end(); ++it) {
    surfMap[(*it)] = loadSDLSurface((*it) + ".png");
    if (!surfMap[(*it)]) { 
      fprintf(stderr, "Couldn't load %s\n", SDL_GetError());
    }  
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
    } else if(idValue == "bateau/nuage/nuage") {
      //formatX = - (  (currentFrame480 * WIDTH / 480) - (263 + 60) );

      formatX = - (  (currentFrame960 * WIDTH / 600) - (493 + 180) );
      formatY = - ((yConst * (*it).y) + permanentShiftY) * scalecon;
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
          SDL_QueryTexture(surfMap[idValue], NULL, NULL, NULL, NULL);
          SDL_RenderCopy(sdlRenderer, surfMap[idValue] , NULL, NULL);
        }
      } else {
        SDL_QueryTexture(surfMap[idValue], NULL, NULL, NULL, NULL);
        SDL_RenderCopy(sdlRenderer, surfMap[idValue] , NULL , NULL);
      }
    }
  }

  const int numPoints = 4;
  SDL_Point points[numPoints];

  points[0].x = 134;
  points[0].y = 89;
  points[1].x = 129;
  points[1].y = 103;
  points[2].x = 171;
  points[2].y = 89;
  points[3].x = 167;
  points[3].y = 103;


  //-11.2217;-0.868118;0.379809;134;89;
  //-10.5483;-1.5029;0.379608;129;103;
  //-10.5735;-0.207413;0.379809;171;89;
  //-9.90005;-0.842192;0.379608;167;103; 

}

void flipSurfaces() {
  //SDL_Flip(screen);
  SDL_RenderPresent(sdlRenderer);
}



void freeSurfaces() {
  //SDL_BlitSurface(empty, NULL, screen, NULL);
  //if(surface != NULL) {
//    SDL_FreeSurface(zoomsurface);
//    SDL_FreeSurface(zoommontagne);
//    SDL_FreeSurface(zoomplatnoncarre);
  //}
}


int main( int argc, char* args[] ) {



                                                                      
  positionVector.push_back(Position(0, 0, "bateau/0001" ));
  positionVector.push_back(Position(0, 0, "bateau/picking_a"));

//  positionVector.push_back(Position(0, 0, "bateau/0001", boost::assign::list_of(44)(45)(46)(47) ));
//  positionVector.push_back(Position(0, 0, "bateau/0002", boost::assign::list_of(42)(43)(48)(49) ));
//  positionVector.push_back(Position(0, 0, "bateau/0003", boost::assign::list_of(40)(41)(50)(51) ));
//  positionVector.push_back(Position(0, 0, "bateau/0004", boost::assign::list_of(38)(39)(52)(53) ));
//  positionVector.push_back(Position(0, 0, "bateau/0005", boost::assign::list_of(36)(37)(54)(55) ));
//  positionVector.push_back(Position(0, 0, "bateau/0006", boost::assign::list_of(34)(35)(56)(57) ));
//  positionVector.push_back(Position(0, 0, "bateau/0007", boost::assign::list_of(32)(33)(58)(59) ));
//  positionVector.push_back(Position(0, 0, "bateau/0008", boost::assign::list_of(0)(1)(30)(31) ));
//  positionVector.push_back(Position(0, 0, "bateau/0009", boost::assign::list_of(2)(3)(28)(29) ));
//  positionVector.push_back(Position(0, 0, "bateau/0010", boost::assign::list_of(4)(5)(26)(27) ));
//  positionVector.push_back(Position(0, 0, "bateau/0011", boost::assign::list_of(6)(7)(24)(25) ));
//  positionVector.push_back(Position(0, 0, "bateau/0012", boost::assign::list_of(8)(9)(22)(23) ));
//  positionVector.push_back(Position(0, 0, "bateau/0013", boost::assign::list_of(10)(11)(20)(21) ));
//  positionVector.push_back(Position(0, 0, "bateau/0014", boost::assign::list_of(12)(13)(18)(19) ));
//  positionVector.push_back(Position(0, 0, "bateau/0015", boost::assign::list_of(14)(15)(16)(17) ));


  positionVector.push_back(Position(0, 0, "bateau/petitpoteau"));
  positionVector.push_back(Position(0, 0, "bateau/nuage/nuage"));
  scalefactor = 325;

//  /*
//   *  Initialise libSDL
//   */
//  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == -1) {
//    printf("cannot initialize SDL\n");
//    return EXIT_FAILURE;
//  }

//  empty = SDL_CreateRGBSurface(SDL_SWSURFACE, WIDTH, HEIGHT,
//     32, 0, 0, 0, 0);

  mutex = SDL_CreateMutex();

  Uint32 flags = SDL_WINDOW_HIDDEN;


  if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, flags, &screen, &sdlRenderer)) {
    printf("cannot set video mode\n");
    return EXIT_FAILURE;
  }

  SDL_SetWindowTitle(screen, "Titre fenêtre");
  SDL_SetWindowSize(screen, WIDTH, HEIGHT);
  SDL_ShowWindow(screen);

  // Création du thread pour charger les images
  if ( (threadChargementImage = SDL_CreateThread(fonctionChargementImage, NULL, NULL)) == NULL ) {
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
      yConst += shiftConstY; 

      if(mouseClicked == true) {
        xPosClicked = xPos;
        yPosClicked = yPos;
        mouseClicked = false;
      }
      
      applySurfaces();
      flipSurfaces();

      freeSurfaces();
      SDL_Delay(100);

      if ( SDL_mutexP(mutex) < 0 ) {
        fprintf(stderr, "Couldn't lock mutex: %s", SDL_GetError());
        exit(1);
      }

      imageChargee = false;

      if ( SDL_mutexV(mutex) < 0 ) {
        fprintf(stderr, "Couldn't lock mutex: %s", SDL_GetError());
        exit(1);
      }

      //currentFrame = (currentFrame + 1) % 30;
      currentFrame = (currentFrame + 1) % 60;
      currentFrame240 = (currentFrame240 + 1) % 240;
      currentFrame480 = (currentFrame480 + 1) % 480;
      currentFrame960 = (currentFrame960 + 1) % 960;
      if(  fps.get_ticks() < (1000 / FRAMES_PER_SECOND)  ) {
        //Sleep the remaining frame time
        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
      }
    }
  }
  return 0;
}
