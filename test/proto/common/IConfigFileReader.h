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

    virtual void Initialize(const path & dir_path) = 0;

    virtual void Reset() = 0;

    virtual std::map<std::string, std::pair<int, int> > GetVerticesMap() = 0;
};

#endif
