#ifndef CONFIG_FILE_READER_H
#define CONFIG_FILE_READER_H

#include "IConfigFileReader.h"
#include <boost/filesystem.hpp>   // includes all needed Boost.Filesystem declarations
#include <boost/algorithm/string.hpp>
#include <vector>

#include <iostream>
#include <fstream>
#include <string>

//#include <wallaroo/registered.h>

#ifdef BOOST_ANDROID
  #include <boost/smart_ptr/shared_ptr.hpp>
#else
  #include <boost/shared_ptr.hpp>
#endif

#include "IFileReader.h"
//#include <sauce/sauce.h>

using namespace boost::filesystem;
//using namespace wallaroo;


//class ConfigFileReader: public IConfigFileReader, public Device {
class ConfigFileReader: public IConfigFileReader {
  private:

    std::vector<path> _fileList;
    std::string _rowDirectory;
    std::string _colDirectory;
    boost::shared_ptr<IFileReader> _fileReaderPtr;
    std::vector<path>::iterator _fileListIterator;

    void GetFiles(const path & dir_path);
  public:


    ConfigFileReader(std::string rowDirectory, 
                     std::string colDirectory,
                     boost::shared_ptr<IFileReader> fileReaderPth);
    ~ConfigFileReader();

    void Initialize();
    void Reset();

    bool HasNext();

    Filename_DataPair Next();

};


#endif
