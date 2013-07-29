#ifndef TYPE_DEF_ENGINE_H
#define TYPE_DEF_ENGINE_H

#ifdef BOOST_ANDROID
	#include <boost/smart_ptr/shared_ptr.hpp>
#else
	#include <boost/shared_ptr.hpp>
#endif

class ITile;
class IDynamicGrid;

typedef boost::shared_ptr<ITile> TileSharedPtr;

template <typename T>
struct SurfaceSharedPtr {
  typedef boost::shared_ptr<T> type;
};

typedef boost::shared_ptr<IDynamicGrid> DynamicGridSharedPtr;
#endif
