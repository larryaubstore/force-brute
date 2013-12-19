#include "ConfigFileReader.h"


ConfigFileReader::ConfigFileReader(std::string rowDirectory, std::string colDirectory) {
  this->_rowDirectory = rowDirectory;
  this->_colDirectory = colDirectory;
}


ConfigFileReader::~ConfigFileReader() {

}


std::map<std::string, std::pair<int, int> > ConfigFileReader::GetVerticesMap() {
  return _verticesMap;
}

void ConfigFileReader::Initialize(const path & dir_path) {
  if ( exists( dir_path ) ) {
    directory_iterator end_itr; 
    for ( directory_iterator itr( dir_path ); itr != end_itr; ++itr ) {
      if ( is_directory(itr->status()) ) {
        this->Initialize( itr->path() );
      } else {
        _fileList.push_back(itr->path());
      }
    }
  }
}

void ConfigFileReader::Reset() {

}
