#include "FileMapper.h"




FileMapper::FileMapper() {


}


FileMapper::~FileMapper() {


}


std::map<std::string, int> FileMapper::GetVertexRowMap() {
  return _vertexRowMap;
}

std::map<std::string, int> FileMapper::GetVertexColMap() {
  return _vertexColMap;
}


void FileMapper::ProcessFile(std::pair<std::string, std::vector <std::string> > pair_filename_dataFile) {

  std::string filename = pair_filename_dataFile.first;
  std::vector<std::string> data = pair_filename_dataFile.second;

 
  std::vector<std::string> filenameSplitted;
  split( filenameSplitted, filename, boost::algorithm::is_any_of( "_" ) );

  std::string keyMap;
  std::stringstream concat;

  if(filenameSplitted.size() == 2) {

    std::vector<std::string> listSplitted;

    int row = -1;
    int col = -1;
 
    if(filenameSplitted[0] == "ROW") {
      row = atoi(filenameSplitted[1].c_str());
    } else {
      col = atoi(filenameSplitted[1].c_str());
    }

    for (std::vector<std::string>::iterator it = data.begin() ; it != data.end(); ++it) {
      listSplitted.clear();
      split( listSplitted, *it, boost::algorithm::is_any_of( "," ) );

      concat.str("");
      
      if(listSplitted.size() >= 3) {

        boost::algorithm::trim(listSplitted[0]);
        boost::algorithm::trim(listSplitted[1]);
        boost::algorithm::trim(listSplitted[2]);

        concat << listSplitted[0] << "_" << listSplitted[1] << "_" << listSplitted[2];
        keyMap = concat.str();

        if(row != -1) {
          if(this->_vertexRowMap.find( keyMap ) == this->_vertexRowMap.end() ) {
            this->_vertexRowMap.insert( std::make_pair<std::string, int>(keyMap, row));
          }
        } else {
          if(this->_vertexColMap.find( keyMap ) == this->_vertexColMap.end() ) {
            this->_vertexColMap.insert( std::make_pair<std::string, int>(keyMap, col));
          }
        }
      }
    }
  } 
}
