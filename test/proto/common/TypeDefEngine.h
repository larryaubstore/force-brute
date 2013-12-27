#ifndef TYPE_DEF_ENGINE_H
#define TYPE_DEF_ENGINE_H

#ifdef BOOST_ANDROID
	#include <boost/smart_ptr/shared_ptr.hpp>
#else
	#include <boost/shared_ptr.hpp>
#endif

#include <SDL/SDL.h>

#include <vector>

class ITile;
class IDynamicGrid;
class IConfigFileReader;

template <typename T>
class IRenderer;

typedef boost::shared_ptr<ITile> TileSharedPtr;

template <typename T>
struct SurfaceSharedPtr {
  typedef boost::shared_ptr<T> type;
};

typedef boost::shared_ptr<IDynamicGrid> DynamicGridSharedPtr;
typedef boost::shared_ptr<ITile> TileSharedPtr;
typedef boost::shared_ptr<IConfigFileReader> ConfigFileReaderSharedPtr;
typedef boost::shared_ptr<IRenderer<SDL_Surface> > RendererSharedPtr;
typedef std::pair<std::string, std::vector <std::string> > Filename_DataPair;


class {
public:
    template<typename T>
    operator boost::shared_ptr<T>() { return boost::shared_ptr<T>(); }
} NULL_PTR;

#endif
