#ifndef FONT_H
#define FONT_H

#include "SDL_ttf.h"
#include <sstream>

typedef struct {
    SDL_Texture *caption;
    SDL_Rect captionRect;
    SDL_Texture *message;
    SDL_Rect messageRect;
} Scene;

static void draw_scene(SDL_Renderer *renderer, Scene *scene)
{
    /* Clear the background to background color */
    //SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    //SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, scene->message, NULL, &scene->messageRect);
    //SDL_RenderPresent(renderer);
}

static std::string convertInt(int number)
{
   std::ostringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

//SDL_Surface *text;
//text = TTF_RenderText_Solid(font, string, *forecol);
//scene.messageRect.x = (WIDTH - text->w)/2;
//scene.messageRect.y = (HEIGHT - text->h)/2;
//scene.messageRect.w = text->w;
//scene.messageRect.h = text->h;
//scene.message = SDL_CreateTextureFromSurface(renderer, text);
//if ( text != NULL ) {
//    scene.captionRect.x = 4;
//    scene.captionRect.y = 4;
//    scene.captionRect.w = text->w;
//    scene.captionRect.h = text->h;
//    scene.caption = SDL_CreateTextureFromSurface(renderer, text);
//    SDL_FreeSurface(text);
//}

#endif
