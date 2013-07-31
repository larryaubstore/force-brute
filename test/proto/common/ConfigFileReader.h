#ifndef CONFIG_FILE_READER_H
#define CONFIG_FILE_READER_H

#include "IConfigFileReader.h"


class ConfigFileReader: public IConfigFileReader {
  public:
    ConfigFileReader();
    ~ConfigFileReader();
    virtual std::vector<TileSharedPtr> ReadFile(std::string filename);
};

#endif
