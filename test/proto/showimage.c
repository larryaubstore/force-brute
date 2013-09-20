#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <vector>
#include "Timer.h"
#include <boost/assign/list_of.hpp>
#include <math.h> 

#include "SDL.h"
#include "SDL_image.h"
#include "points.h"

#define WIDTH 960 
#define HEIGHT 540 


int currentFrame = 0;
int currentFrame120 = 0;
int currentFrame240 = 0;
int currentFrame480 = 0;
int currentFrame960 = 0;
const int FRAMES_PER_SECOND = 30;
int xConst = 163;
int yConst = 72;
int permanentShiftX = 0;
int permanentShiftY = 0;
int scalefactor = 0;
int xPos = 0;
int yPos = 0;
int xPosClicked = 0;
int yPosClicked = 0;

struct Position {
  int x;
  int y;
  std::string id;
  std::vector<int> frames;
  std::string speed;
  Position(int x, int y, std::string id) : x(x), y(y), id(id)  { }
  Position(int x, int y, std::string id, std::vector<int> frames) : x(x), y(y), id(id), frames(frames) { }
  Position(int x, int y, std::string id, std::vector<int> frames, std::string speed) : x(x), y(y), id(id), frames(frames), speed(speed) { }
};

std::map <std::string, SDL_Texture*> surfMap;
std::vector <std::string> notLoadedSurfVector;
SDL_Renderer *renderer;
std::vector<Position> positionVector;


///* Draw a Gimpish background pattern to show transparency in the image */
//static void draw_background(SDL_Renderer *renderer, int w, int h)
//{
//    SDL_Color col[2] = {
//        { 0x66, 0x66, 0x66, 0xff },
//        { 0x99, 0x99, 0x99, 0xff },
//    };
//    int i, x, y;
//    SDL_Rect rect;
//
//    rect.w = 8;
//    rect.h = 8;
//    for (y = 0; y < h; y += rect.h) {
//        for (x = 0; x < w; x += rect.w) {
//            /* use an 8x8 checkerboard pattern */
//            i = (((x ^ y) >> 3) & 1);
//            SDL_SetRenderDrawColor(renderer, col[i].r, col[i].g, col[i].b, col[i].a);
//
//            rect.x = x;
//            rect.y = y;
//            SDL_RenderFillRect(renderer, &rect);
//        }
//    }
//}

/* Draw a Gimpish background pattern to show transparency in the image */
static void draw_rectangle(SDL_Renderer *renderer, int w, int h, int x, int y)
{
    SDL_Color col[3] = {
        { 0x66, 0x66, 0x66, 0xff },
        { 0x99, 0x99, 0x99, 0xff },
        { 0xff, 0x00, 0x00, 0xff },
    };
    //int i, x, y;
    SDL_Rect rect;

    rect.w = 4;
    rect.h = 4;
    SDL_SetRenderDrawColor(renderer, col[2].r, col[2].g, col[2].b, col[2].a);

    rect.x = x; 
    rect.y = y;
    SDL_RenderFillRect(renderer, &rect);
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

  positionVector.push_back(Position(0, 0, "bateau/picking/0001", boost::assign::list_of(44)(45)(46)(47) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0002", boost::assign::list_of(42)(43)(48)(49) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0003", boost::assign::list_of(40)(41)(50)(51) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0004", boost::assign::list_of(38)(39)(52)(53) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0005", boost::assign::list_of(36)(37)(54)(55) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0006", boost::assign::list_of(34)(35)(56)(57) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0007", boost::assign::list_of(32)(33)(58)(59) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0008", boost::assign::list_of(0)(1)(30)(31) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0009", boost::assign::list_of(2)(3)(28)(29) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0010", boost::assign::list_of(4)(5)(26)(27) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0011", boost::assign::list_of(6)(7)(24)(25) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0012", boost::assign::list_of(8)(9)(22)(23) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0013", boost::assign::list_of(10)(11)(20)(21) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0014", boost::assign::list_of(12)(13)(18)(19) ));
  positionVector.push_back(Position(0, 0, "bateau/picking/0015", boost::assign::list_of(14)(15)(16)(17) ));

  positionVector.push_back(Position(0, 0, "bateau/bateau/bateau"));
  //positionVector.push_back(Position(0, 0, "bateau/nuage/nuage"));
  
  positionVector.push_back(Position(0, 0, "bateau/nuage/0001", boost::assign::list_of(1)(120), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0002", boost::assign::list_of(2)(119), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0003", boost::assign::list_of(3)(118), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0004", boost::assign::list_of(4)(117), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0005", boost::assign::list_of(5)(116), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0006", boost::assign::list_of(6)(115), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0007", boost::assign::list_of(7)(114), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0008", boost::assign::list_of(8)(113), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0009", boost::assign::list_of(9)(112), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0010", boost::assign::list_of(10)(111), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0011", boost::assign::list_of(11)(110), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0012", boost::assign::list_of(12)(109), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0013", boost::assign::list_of(13)(108), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0014", boost::assign::list_of(14)(107), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0015", boost::assign::list_of(15)(106), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0016", boost::assign::list_of(16)(105), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0017", boost::assign::list_of(17)(104), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0018", boost::assign::list_of(18)(103), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0019", boost::assign::list_of(19)(102), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0020", boost::assign::list_of(20)(101), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0021", boost::assign::list_of(21)(100), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0022", boost::assign::list_of(22)(99), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0023", boost::assign::list_of(23)(98), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0024", boost::assign::list_of(24)(97), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0025", boost::assign::list_of(25)(96), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0026", boost::assign::list_of(26)(95), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0027", boost::assign::list_of(27)(94), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0028", boost::assign::list_of(28)(93), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0029", boost::assign::list_of(29)(92), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0030", boost::assign::list_of(30)(91), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0031", boost::assign::list_of(31)(90), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0032", boost::assign::list_of(32)(89), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0033", boost::assign::list_of(33)(88), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0034", boost::assign::list_of(34)(87), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0035", boost::assign::list_of(35)(86), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0036", boost::assign::list_of(36)(85), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0037", boost::assign::list_of(37)(84), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0038", boost::assign::list_of(38)(83), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0039", boost::assign::list_of(39)(82), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0040", boost::assign::list_of(40)(81), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0041", boost::assign::list_of(41)(80), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0042", boost::assign::list_of(42)(79), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0043", boost::assign::list_of(43)(78), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0044", boost::assign::list_of(44)(77), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0045", boost::assign::list_of(45)(76), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0046", boost::assign::list_of(46)(75), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0047", boost::assign::list_of(47)(74), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0048", boost::assign::list_of(48)(73), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0049", boost::assign::list_of(49)(72), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0050", boost::assign::list_of(50)(71), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0051", boost::assign::list_of(51)(70), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0052", boost::assign::list_of(52)(69), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0053", boost::assign::list_of(53)(68), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0054", boost::assign::list_of(54)(67), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0055", boost::assign::list_of(55)(66), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0056", boost::assign::list_of(56)(65), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0057", boost::assign::list_of(57)(64), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0058", boost::assign::list_of(58)(63), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0059", boost::assign::list_of(59)(62), "240" ));
  positionVector.push_back(Position(0, 0, "bateau/nuage/0060", boost::assign::list_of(60)(61), "240" ));

//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0001", boost::assign::list_of(44)(45)(46)(47), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0002", boost::assign::list_of(42)(43)(48)(49), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0003", boost::assign::list_of(40)(41)(50)(51), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0004", boost::assign::list_of(38)(39)(52)(53), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0005", boost::assign::list_of(36)(37)(54)(55), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0006", boost::assign::list_of(34)(35)(56)(57), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0007", boost::assign::list_of(32)(33)(58)(59), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0008", boost::assign::list_of(0)(1)(30)(31), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0009", boost::assign::list_of(2)(3)(28)(29), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0010", boost::assign::list_of(4)(5)(26)(27), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0011", boost::assign::list_of(6)(7)(24)(25), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0012", boost::assign::list_of(8)(9)(22)(23), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0013", boost::assign::list_of(10)(11)(20)(21), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0014", boost::assign::list_of(12)(13)(18)(19), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0015", boost::assign::list_of(14)(15)(16)(17), "240" ));

//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0001", boost::assign::list_of(1), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0002", boost::assign::list_of(2), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0003", boost::assign::list_of(3), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0004", boost::assign::list_of(4), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0005", boost::assign::list_of(5), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0006", boost::assign::list_of(6), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0007", boost::assign::list_of(7), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0008", boost::assign::list_of(8), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0009", boost::assign::list_of(9), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0010", boost::assign::list_of(10), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0011", boost::assign::list_of(11), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0012", boost::assign::list_of(12), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0013", boost::assign::list_of(13), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0014", boost::assign::list_of(14), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0015", boost::assign::list_of(15), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0016", boost::assign::list_of(16), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0017", boost::assign::list_of(17), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0018", boost::assign::list_of(18), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0019", boost::assign::list_of(19), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0020", boost::assign::list_of(20), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0021", boost::assign::list_of(21), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0022", boost::assign::list_of(22), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0023", boost::assign::list_of(23), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0024", boost::assign::list_of(24), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0025", boost::assign::list_of(25), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0026", boost::assign::list_of(26), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0027", boost::assign::list_of(27), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0028", boost::assign::list_of(28), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0029", boost::assign::list_of(29), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0030", boost::assign::list_of(30), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0031", boost::assign::list_of(31), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0032", boost::assign::list_of(32), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0033", boost::assign::list_of(33), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0034", boost::assign::list_of(34), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0035", boost::assign::list_of(35), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0036", boost::assign::list_of(36), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0037", boost::assign::list_of(37), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0038", boost::assign::list_of(38), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0039", boost::assign::list_of(39), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0040", boost::assign::list_of(40), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0041", boost::assign::list_of(41), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0042", boost::assign::list_of(42), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0043", boost::assign::list_of(43), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0044", boost::assign::list_of(44), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0045", boost::assign::list_of(45), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0046", boost::assign::list_of(46), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0047", boost::assign::list_of(47), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0048", boost::assign::list_of(48), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0049", boost::assign::list_of(49), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0050", boost::assign::list_of(50), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0051", boost::assign::list_of(51), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0052", boost::assign::list_of(52), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0053", boost::assign::list_of(53), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0054", boost::assign::list_of(54), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0055", boost::assign::list_of(55), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0056", boost::assign::list_of(56), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0057", boost::assign::list_of(57), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0058", boost::assign::list_of(58), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0059", boost::assign::list_of(59), "240" ));
//  positionVector.push_back(Position(0, 0, "bateau/nuagecontinu/0060", boost::assign::list_of(60), "240" ));

}

int main(int argc, char *argv[])
{
  SDL_Window *window;
  SDL_Texture *texture;
  Uint32 flags;
  int i, w, h, done;
  SDL_Event event;
  const char *saveFile = NULL;
  bool mouseClicked = false;

  std::map<int, int> map_index_hypothenuse;

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

    Uint8 mouseState = SDL_GetMouseState(&xPos, &yPos);

    mouseClicked = false;
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
                //done = 1;
                mouseClicked = true;
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
        //formatX = - (  (currentFrame960 * WIDTH / 600) - (493 + 180) );
        //formatY = - ((yConst * (*it).y) + permanentShiftY) * scalecon;
      } else if(idValue == "bateau/picking_a") {

      } else {
        formatX = - ((xConst * (*it).x) + permanentShiftX) * scalecon;
        formatY = - ((yConst * (*it).y) + permanentShiftY) * scalecon;
      }



      if((*it).frames.size() > 0) {

        std::string speed = (*it).speed;

        if(speed != "240") {
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
        } else if(speed == "240") {

          int currentFrameCorrected = ceil(currentFrame240 / 2) + 1;
          //int currentFrameCorrected = ceil(currentFrame120 / 2) + 1;
          
          if(std::find((*it).frames.begin(), (*it).frames.end(), currentFrameCorrected) != (*it).frames.end()) {
          //if(std::find((*it).frames.begin(), (*it).frames.end(), currentFrame120 + 1) != (*it).frames.end()) {
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


    int px;
    int py;

    int hypothenuse;
    int dx;
    int dy;

    if(mouseClicked == true) {
      map_index_hypothenuse.clear();
      for(int counter = 0; counter < npoints-1; counter+=2) {
        px = points[counter];
        py = points[counter+1];


        dx = px - xPos;
        dy = py - yPos;

        //hypothenuse = sqrt(px*px + py*py);
        hypothenuse = sqrt(dx*dx + dy*dy);

        if( map_index_hypothenuse.size() < 4 ) {
           map_index_hypothenuse.insert( std::pair<int, int>(hypothenuse, counter));
        } else {
          for(std::map<int, int>::reverse_iterator rit = map_index_hypothenuse.rbegin(); rit != map_index_hypothenuse.rend(); ++rit) {
            if( hypothenuse < rit->first) {
              map_index_hypothenuse.erase(--rit.base());
              map_index_hypothenuse.insert( std::pair<int, int>(hypothenuse, counter));
            }
          }
        }
      }

      printf("XPOS => %i\n", xPos);
      printf("YPOS => %i\n", yPos);
      printf("SIZE => %i\n", map_index_hypothenuse.size());
      for(std::map<int, int>::iterator iterator = map_index_hypothenuse.begin(); iterator != map_index_hypothenuse.end(); iterator++) {

        printf("\nPOINTS X => %i\n", points[iterator->second] );
        printf("POINTS Y => %i\n", points[iterator->second+1] );
      }
    } else {
      for(std::map<int, int>::iterator iterator = map_index_hypothenuse.begin(); iterator != map_index_hypothenuse.end(); iterator++) {
        draw_rectangle(renderer, 8, 8, points[iterator->second], points[iterator->second+1]);
      }
    }
    //draw_rectangle(renderer, 8, 8, 500, 500);

    SDL_RenderPresent(renderer);
    currentFrame = (currentFrame + 1) % 60;
    currentFrame120 = (currentFrame120 + 1) % 120;
    currentFrame240 = (currentFrame240 + 1) % 240;
    currentFrame480 = (currentFrame480 + 1) % 480;
    currentFrame960 = (currentFrame960 + 1) % 960;
    if(  fps.get_ticks() < (1000 / FRAMES_PER_SECOND)  ) {
      SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
    }
  }

  for ( std::vector<Position>::iterator it = positionVector.begin(); it != positionVector.end(); 
        ++it) {
    std::string idValue = (*it).id;
    SDL_DestroyTexture(surfMap[idValue]);
  }

  SDL_Quit();
  return(0);
}
