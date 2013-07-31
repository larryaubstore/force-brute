#ifndef I_TILE_H
#define I_TILE_H

#ifdef BOOST_ANDROID
	#include <boost/smart_ptr/shared_ptr.hpp>
#else
	#include <boost/shared_ptr.hpp>
#endif

class ITile
{
  public:

    virtual ~ITile() {};

    virtual int GetXPos() = 0;
    virtual int GetYPos() = 0;
    virtual double GetZoomFactor() = 0;
};

#endif
