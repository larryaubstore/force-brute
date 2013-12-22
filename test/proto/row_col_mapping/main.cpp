#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <ConfigFileReader.h>

#include "boost/filesystem.hpp"

using namespace boost::filesystem;

int main(int argc, char *argv[])
{
  ConfigFileReader* configFileReader = new ConfigFileReader("data", "test2");

  //path dataPath( "data" );

  configFileReader->Initialize();
  std::vector<path> fileList = configFileReader->GetFileList();


  for (std::vector<path>::iterator it = fileList.begin() ; it != fileList.end(); ++it) {
    std::cout << ' ' << *it;
  }

  return 0;
}
