#ifndef I_SCREEN_COORD_H
#define I_SCREEN_COORD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <vector>
#include "boost/filesystem.hpp" 
#include "TypeDefEngine.h"
#include "TypeGeometry.h"

using namespace boost::filesystem;

class IScreenCoord
{
	public:

    virtual ~IScreenCoord() {};


    virtual vertex_screen_pair ProcessOneCoord(Point3<float> vertex) = 0;
//    virtual void Initialize() = 0;
//    virtual void Reset() = 0;
//    virtual bool HasNext() = 0;
//    virtual Filename_DataPair Next() = 0;

};

#endif
