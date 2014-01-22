#ifndef BL_WORLD_MAPPER_H
#define BL_WORLD_MAPPER_H

#include <string>
#include <map>
#include "TypeDefEngine.h"
#include "IBLWorldMapper.h"

#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <sstream>

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

class BLWorldMapper : public IBLWorldMapper 
{
  public:

    BLWorldMapper();
    ~BLWorldMapper();


    std::map<std::string, std::pair<int, int> > GetVertexPair_Map();

    void ProcessFile(std::pair<std::string, std::vector <std::string> > pair_filename_dataFile);
};

#endif
