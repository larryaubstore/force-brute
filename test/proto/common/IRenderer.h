#ifndef I_RENDERER_H
#define I_RENDERER_H

#ifdef BOOST_ANDROID
	#include <boost/smart_ptr/shared_ptr.hpp>
#else
	#include <boost/shared_ptr.hpp>
#endif

#include <vector>

template <typename T>
class IRenderer
{
  typedef boost::shared_ptr<T> SurfaceSharedPtr;

	public:

    virtual ~IRenderer() {};

    virtual void BlitSurface() = 0;
    virtual void ZoomSurface() = 0;
    virtual void LoadSurface() = 0;
    virtual void FreeSurface() = 0;
    virtual void FlipSurface() = 0;

    virtual std::vector<SurfaceSharedPtr> GetLoadedSurfaces() = 0; 
    //virtual boost::shared_ptr<SDL_Surface> GetSurface() = 0;
};

#endif
