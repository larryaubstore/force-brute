#ifndef CONFIG_FILE_READER_H
#define CONFIG_FILE_READER_H

#include "IConfigFileReader.h"


class ConfigFileReader: public IConfigFileReader {

  private:
    std::string _filename;
  public:
    ConfigFileReader(std::string filename);
    ~ConfigFileReader();
    virtual std::vector<TileSharedPtr> ReadFile(std::string filename);
};

#endif
