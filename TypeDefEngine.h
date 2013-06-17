#ifndef TYPE_DEF_ENGINE_H
#define TYPE_DEF_ENGINE_H

#ifdef BOOST_ANDROID
	#include <boost/smart_ptr/shared_ptr.hpp>
#else
	#include <boost/shared_ptr.hpp>
#endif

#include "IPathMissile.h"
#include "scene/IAnimation.h"

typedef boost::shared_ptr<IPathMissile> PathMissilePtr;
typedef boost::shared_ptr<IAnimation> AnimationPtr;

//#include "PathMissile.h"
//class EngineType
//{
//	public:
		//typedef boost::shared_ptr<PathMissile> PathMissilePtr;

//};
#endif
