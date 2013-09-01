/*
  showimage:  A test application for the SDL image loading library.
  Copyright (C) 1997-2013 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <vector>
#include "Timer.h"
#include <boost/assign/list_of.hpp>

#include "SDL.h"
#include "SDL_image.h"

#define WIDTH 960 
#define HEIGHT 540 


int currentFrame = 0;
int currentFrame240 = 0;
int currentFrame480 = 0;
int currentFrame960 = 0;
const int FRAMES_PER_SECOND = 30;
int xConst = 163;
int yConst = 72;
int permanentShiftX = 0;
int permanentShiftY = 0;
int scalefactor = 0;

struct Position {
  int x;
  int y;
  std::string id;
  std::vector<int> frames;
  Position(int x, int y, std::string id) : x(x), y(y), id(id)  { }
  Position(int x, int y, std::string id, std::vector<int> frames) : x(x), y(y), id(id), frames(frames) { }
};

std::map <std::string, SDL_Texture*> surfMap;
std::vector <std::string> notLoadedSurfVector;
SDL_Renderer *renderer;
std::vector<Position> positionVector;


/* Draw a Gimpish background pattern to show transparency in the image */
static void draw_background(SDL_Renderer *renderer, int w, int h)
{
    SDL_Color col[2] = {
        { 0x66, 0x66, 0x66, 0xff },
        { 0x99, 0x99, 0x99, 0xff },
    };
    int i, x, y;
    SDL_Rect rect;

    rect.w = 8;
    rect.h = 8;
    for (y = 0; y < h; y += rect.h) {
        for (x = 0; x < w; x += rect.w) {
            /* use an 8x8 checkerboard pattern */
            i = (((x ^ y) >> 3) & 1);
            SDL_SetRenderDrawColor(renderer, col[i].r, col[i].g, col[i].b, col[i].a);

            rect.x = x;
            rect.y = y;
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

SDL_Texture* loadSDLSurface(std::string fileName) {

  printf("-- %s\n", fileName.data()); 
  SDL_Texture* texture = IMG_LoadTexture(renderer, fileName.data());
  return(texture);
}

void chargeSurface() {
  for (std::vector<Position>::iterator it = positionVector.begin() ; it != positionVector.end(); ++it) {
    surfMap[(*it).id] = loadSDLSurface((*it).id + ".png");
    if (!surfMap[(*it).id]) { 
      fprintf(stderr, "Couldn't load %s\n", SDL_GetError());
    }  
  }
  notLoadedSurfVector.clear();
}

void initSurfaces() {
  //positionVector.push_back(Position(0, 0, "bateau/0001" ));
  //

  positionVector.push_back(Position(0, 0, "bateau/0001", boost::assign::list_of(44)(45)(46)(47) ));
  positionVector.push_back(Position(0, 0, "bateau/0002", boost::assign::list_of(42)(43)(48)(49) ));
  positionVector.push_back(Position(0, 0, "bateau/0003", boost::assign::list_of(40)(41)(50)(51) ));
  positionVector.push_back(Position(0, 0, "bateau/0004", boost::assign::list_of(38)(39)(52)(53) ));
  positionVector.push_back(Position(0, 0, "bateau/0005", boost::assign::list_of(36)(37)(54)(55) ));
  positionVector.push_back(Position(0, 0, "bateau/0006", boost::assign::list_of(34)(35)(56)(57) ));
  positionVector.push_back(Position(0, 0, "bateau/0007", boost::assign::list_of(32)(33)(58)(59) ));
  positionVector.push_back(Position(0, 0, "bateau/0008", boost::assign::list_of(0)(1)(30)(31) ));
  positionVector.push_back(Position(0, 0, "bateau/0009", boost::assign::list_of(2)(3)(28)(29) ));
  positionVector.push_back(Position(0, 0, "bateau/0010", boost::assign::list_of(4)(5)(26)(27) ));
  positionVector.push_back(Position(0, 0, "bateau/0011", boost::assign::list_of(6)(7)(24)(25) ));
  positionVector.push_back(Position(0, 0, "bateau/0012", boost::assign::list_of(8)(9)(22)(23) ));
  positionVector.push_back(Position(0, 0, "bateau/0013", boost::assign::list_of(10)(11)(20)(21) ));
  positionVector.push_back(Position(0, 0, "bateau/0014", boost::assign::list_of(12)(13)(18)(19) ));
  positionVector.push_back(Position(0, 0, "bateau/0015", boost::assign::list_of(14)(15)(16)(17) ));
  positionVector.push_back(Position(0, 0, "bateau/picking_a"));
  positionVector.push_back(Position(0, 0, "bateau/petitpoteau"));
  positionVector.push_back(Position(0, 0, "bateau/nuage/nuage"));

//  notLoadedSurfVector.push_back("bateau/0001");
//  notLoadedSurfVector.push_back("bateau/picking_a");
//  notLoadedSurfVector.push_back("bateau/petitpoteau");
//  notLoadedSurfVector.push_back("bateau/nuage/nuage");
}

int main(int argc, char *argv[])
{
  SDL_Window *window;
  SDL_Texture *texture;
  Uint32 flags;
  int i, w, h, done;
  SDL_Event event;
  const char *saveFile = NULL;

  initSurfaces();

  flags = SDL_WINDOW_HIDDEN;
  for ( i=1; argv[i]; ++i ) {
      if ( strcmp(argv[i], "-fullscreen") == 0 ) {
          SDL_ShowCursor(0);
          flags |= SDL_WINDOW_FULLSCREEN;
      }
  }

  if (SDL_CreateWindowAndRenderer(0, 0, flags, &window, &renderer) < 0) {
      fprintf(stderr, "SDL_CreateWindowAndRenderer() failed: %s\n", SDL_GetError());
      return(2);
  }

  chargeSurface();

  /* Show the window */
  SDL_SetWindowTitle(window, argv[i]);
  SDL_SetWindowSize(window, WIDTH, HEIGHT);
  SDL_ShowWindow(window);

  Timer fps;
  done = 0;
  while ( ! done ) {
      fps.start();
      while ( SDL_PollEvent(&event) ) {
          switch (event.type) {
              case SDL_KEYUP:
                  switch (event.key.keysym.sym) {
                      case SDLK_LEFT:
                          if ( i > 1 ) {
                              i -= 2;
                              done = 1;
                          }
                          break;
                      case SDLK_RIGHT:
                          if ( argv[i+1] ) {
                              done = 1;
                          }
                          break;
                      case SDLK_ESCAPE:
                      case SDLK_q:
                          argv[i+1] = NULL;
                      /* Drop through to done */
                      case SDLK_SPACE:
                      case SDLK_TAB:
                      done = 1;
                      break;
                      default:
                      break;
                  }
                  break;
              case SDL_MOUSEBUTTONDOWN:
                  done = 1;
                  break;
              case SDL_QUIT:
                  argv[i+1] = NULL;
                  done = 1;
                  break;
              default:
                  break;
          }
      }

      /* Draw a background pattern in case the image has transparency */
      //draw_background(renderer, w, h);

      SDL_Rect SrcR;
      SDL_Rect DestR;
      int formatX = 0;
      int formatY = 0;
      double scalecon = scalefactor  / 500.0f;

      for ( std::vector<Position>::iterator it = positionVector.begin(); 
        it != positionVector.end(); 
        ++it) {
        std::string idValue = (*it).id;

        if(idValue == "bateau/petitpoteau") {
          //formatX = - (xPosClicked - 33);
          //formatY = - (yPosClicked - 50);
        } else if(idValue == "bateau/nuage/nuage") {
          formatX = - (  (currentFrame960 * WIDTH / 600) - (493 + 180) );
          formatY = - ((yConst * (*it).y) + permanentShiftY) * scalecon;
        } else {
          formatX = - ((xConst * (*it).x) + permanentShiftX) * scalecon;
          formatY = - ((yConst * (*it).y) + permanentShiftY) * scalecon;
        }



        if((*it).frames.size() > 0) {
          if(std::find((*it).frames.begin(), (*it).frames.end(), currentFrame) != (*it).frames.end()) {
            SDL_QueryTexture(surfMap[idValue], NULL, NULL, &w, &h);
            SrcR.x = 0;
            SrcR.y = 0;
            SrcR.w = w;
            SrcR.h = h;

            DestR.x = formatX;
            DestR.y = formatY;
            DestR.w = w;
            DestR.h = h;
            SDL_RenderCopy(renderer, surfMap[idValue] , &SrcR, &DestR);
          }
        } else {
          SDL_QueryTexture(surfMap[idValue], NULL, NULL, &w, &h);
          SrcR.x = 0;
          SrcR.y = 0;
          SrcR.w = w;
          SrcR.h = h;

          DestR.x = formatX;
          DestR.y = formatY;
          DestR.w = w;
          DestR.h = h;
          SDL_RenderCopy(renderer, surfMap[idValue], &SrcR, &DestR);
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


      SDL_RenderPresent(renderer);
      currentFrame = (currentFrame + 1) % 60;
      currentFrame240 = (currentFrame240 + 1) % 240;
      currentFrame480 = (currentFrame480 + 1) % 480;
      currentFrame960 = (currentFrame960 + 1) % 960;
      if(  fps.get_ticks() < (1000 / FRAMES_PER_SECOND)  ) {
        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
      }
    }

    for ( std::vector<Position>::iterator it = positionVector.begin(); 
          it != positionVector.end(); 
          ++it) {
      std::string idValue = (*it).id;
      SDL_DestroyTexture(surfMap[idValue]);
    }

    SDL_Quit();
    return(0);
}
