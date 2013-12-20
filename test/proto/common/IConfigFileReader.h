#ifndef I_CONFIG_FILE_READER_H
#define I_CONFIG_FILE_READER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <vector>
#include "boost/filesystem.hpp" 

using namespace boost::filesystem;

class IConfigFileReader
{
	public:

    virtual ~IConfigFileReader() {};

    virtual void Initialize() = 0;

    virtual void Reset() = 0;

    virtual std::vector<path> GetFileList() = 0;
};

#endif
