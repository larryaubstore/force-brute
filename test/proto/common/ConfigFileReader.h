#ifndef CONFIG_FILE_READER_H
#define CONFIG_FILE_READER_H

#include "IConfigFileReader.h"
#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations
#include <vector>

using namespace boost::filesystem;

class ConfigFileReader: public IConfigFileReader {

  private:

    std::vector<path> _fileList;
    std::string _rowDirectory;
    std::string _colDirectory;
    
    void GetFiles(const path & dir_path);

  public:
    ConfigFileReader(std::string rowDirectory, std::string colDirectory);
    ~ConfigFileReader();

    void Initialize();
    void Reset();

    std::vector<path> GetFileList();
};

#endif
