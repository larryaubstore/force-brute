#ifndef CONFIG_FILE_READER_H
#define CONFIG_FILE_READER_H

#include "IConfigFileReader.h"
#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations
#include <boost/algorithm/string.hpp>
#include <vector>

#include <iostream>
#include <fstream>
#include <string>

#include "wallaroo/registered.h"

using namespace boost::filesystem;
using namespace wallaroo;


class ConfigFileReader: public IConfigFileReader, public Device {
  private:

    std::vector<path> _fileList;
    std::string _rowDirectory;
    std::string _colDirectory;
    
    void GetFiles(const path & dir_path);

    std::vector<path>::iterator _fileListIterator;

  public:


    ConfigFileReader(std::string rowDirectory, std::string colDirectory);
    ~ConfigFileReader();

    void Initialize();
    void Reset();



    Filename_DataPair Next();

    std::vector<path> GetFileList();
};


#endif
