#include "ConfigFileReader.h"


ConfigFileReader::ConfigFileReader(std::string rowDirectory, std::string colDirectory) {
  this->_rowDirectory = rowDirectory;
  this->_colDirectory = colDirectory;
}


ConfigFileReader::~ConfigFileReader() {

}

void ConfigFileReader::GetFiles(const path & dir_path) {
  if ( exists( dir_path ) ) {
    directory_iterator end_itr; 
    for ( directory_iterator itr( dir_path ); itr != end_itr; ++itr ) {
      if ( is_directory(itr->status()) ) {
        this->GetFiles( itr->path() );
      } else {
        this->_fileList.push_back(itr->path());
      }
    }
  }
}


void ConfigFileReader::Initialize() {
  this->GetFiles(path(this->_rowDirectory));
  this->GetFiles(path(this->_colDirectory));
}

void ConfigFileReader::Reset() {

}

std::vector<path> ConfigFileReader::GetFileList() {
  return _fileList;
}
