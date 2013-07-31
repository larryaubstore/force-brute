#ifndef RENDERER_H
#define RENDERER_H

#include "IRenderer.h"
#include "TypeDefEngine.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL_rotozoom.h>


class Renderer: public IRenderer<SDL_Surface>
{
  private:
    DynamicGridSharedPtr _dynamicGridSharedPtr;
    SDL_Surface* _screen; 
  public:
    //Renderer(DynamicGridSharedPtr dynamicGridSharedPtr);
    //Renderer(std::string filename);
    
    Renderer(ConfigFileReaderSharedPtr configFileReaderSharedPtr); 
    ~Renderer();

    virtual void BlitSurface();
    virtual void ZoomSurface();
    virtual SDL_Surface* LoadSurface(std::string fileName);
    virtual void FreeSurface();
    virtual void FlipSurface();

    virtual std::vector<SurfaceSharedPtr<SDL_Surface>::type> GetLoadedSurfaces(); 
    virtual DynamicGridSharedPtr GetDynamicGrid();
};



#endif
