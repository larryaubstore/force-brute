#ifndef TYPE_DEF_ENGINE_H
#define TYPE_DEF_ENGINE_H

#include "ITile.h"

#ifdef BOOST_ANDROID
	#include <boost/smart_ptr/shared_ptr.hpp>
#else
	#include <boost/shared_ptr.hpp>
#endif

typedef boost::shared_ptr<ITile> TileSharedPtr;

#endif
