#ifndef I_FILEREADER_H
#define I_FILEREADER_H


#include <string>

class IFileReader
{
  public:
    virtual ~IFileReader() {};
    virtual void OpenFile(std::string filename) = 0;
    virtual bool HasNext() = 0;
    virtual std::string ReadLine() = 0;
    virtual void CloseFile() = 0;
};

#endif


