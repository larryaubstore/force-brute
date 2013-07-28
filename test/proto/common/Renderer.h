#ifndef RENDERER_H
#define RENDERER_H

#include "IRenderer.h"
#include "TypeDefEngine.h"

template <typename T>
class Renderer: public IRenderer<T>
{
	private:

//    int _xPos;
//    int _yPos;
//    SurfaceSharedPtr _surface;

	public:
		Renderer();
		~Renderer();

    virtual void BlitSurface();
    virtual void ZoomSurface();
    virtual void LoadSurface();
    virtual void FreeSurface();
    virtual void FlipSurface();

    virtual std::vector<T> GetLoadedSurfaces(); 
};


#include "Renderer.tpp"

#endif
