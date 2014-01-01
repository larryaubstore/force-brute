#ifndef FILEREADER_H
#define FILEREADER_H

#include <boost/filesystem.hpp> 

#include <string>
#include "TypeDefEngine.h"
#include "IFileReader.h"

#include <iostream>
#include <fstream>
#include <string>

class FileReader: public IFileReader 
{

  private:
    std::ifstream _fileStream; 
    std::string _currentLine;

  public:
    virtual void OpenFile(std::string filename);
    virtual std::string ReadLine();
    virtual bool HasNext();
    virtual void CloseFile();
    FileReader();
    ~FileReader();
};

#endif


