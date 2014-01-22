#ifndef I_BL_WORLD_MAPPER_H
#define I_BL_WORLD_MAPPER_H

#include <string>
#include <map>

class IBLWorldMapper
{
  public:
    virtual ~IBLWorldMapper() {};


    // X, Y, Z => PX, PY
    virtual std::map<std::string, std::pair<int, int> > GetVertexPair_Map() = 0;

    // FILENAME, VECTOR<STRING> (X, Y, Z)
    virtual void ProcessFile(std::pair<std::string, std::vector <std::string> > pair_filename_dataFile) = 0;
};


#endif
