#ifndef FILEMAPPER_H
#define FILEMAPPER_H


#include <string>
#include <map>
#include "TypeDefEngine.h"
#include "IFileMapper.h"

#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <sstream>

class FileMapper: public IFileMapper
{
  private:
    std::map<std::string, int> _vertexRowMap;
    std::map<std::string, int> _vertexColMap;
  public:
    FileMapper();
    ~FileMapper();

    std::map<std::string, int> GetVertexRowMap();
    std::map<std::string, int> GetVertexColMap();
    void ProcessFile(std::pair<std::string, std::vector <std::string> > pair_filename_dataFile);
};

#endif


