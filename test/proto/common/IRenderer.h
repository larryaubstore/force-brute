#ifndef I_RENDERER_H
#define I_RENDERER_H

#ifdef BOOST_ANDROID
	#include <boost/smart_ptr/shared_ptr.hpp>
#else
	#include <boost/shared_ptr.hpp>
#endif

#include <vector>

#include "IDynamicGrid.h"

#include "TypeDefEngine.h"

template <typename T>
class IRenderer
{

	public:

    virtual ~IRenderer() {};

    virtual void BlitSurface() = 0;
    virtual void ZoomSurface() = 0;
    virtual T* LoadSurface(std::string fileName) = 0;
    virtual void FreeSurface() = 0;
    virtual void FlipSurface() = 0;
    virtual void Run() = 0;

    virtual DynamicGridSharedPtr GetDynamicGrid() = 0;
    virtual std::vector<boost::shared_ptr<T> > GetLoadedSurfaces() = 0; 
};

#endif
