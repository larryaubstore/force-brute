#ifndef RENDERER_H
#define RENDERER_H

#include "IRenderer.h"
#include "TypeDefEngine.h"

class Renderer: public IRenderer<SDL_Surface>
{
  private:
    DynamicGridSharedPtr _dynamicGridSharedPtr;
  public:
    Renderer(DynamicGridSharedPtr dynamicGridSharedPtr);
    ~Renderer();

    virtual void BlitSurface();
    virtual void ZoomSurface();
    virtual void LoadSurface();
    virtual void FreeSurface();
    virtual void FlipSurface();

    virtual std::vector<SurfaceSharedPtr<SDL_Surface>::type> GetLoadedSurfaces(); 
    virtual DynamicGridSharedPtr GetDynamicGrid();
};



#endif
