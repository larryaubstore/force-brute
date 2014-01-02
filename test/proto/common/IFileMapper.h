#ifndef I_FILEMAPPER_H
#define I_FILEMAPPER_H


#include <string>
#include <map>

class IFileMapper
{
  public:
    virtual ~IFileMapper() {};

    virtual std::map<std::string, int> GetVertexRowMap() = 0;
    virtual std::map<std::string, int> GetVertexColMap() = 0;
    virtual void ProcessFile(std::pair<std::string, std::vector <std::string> > pair_filename_dataFile) = 0;
};

#endif


