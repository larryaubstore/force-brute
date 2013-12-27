#include "ConfigFileReader.h"


WALLAROO_REGISTER( ConfigFileReader, std::string, std::string )

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
  this->Reset();
}


void ConfigFileReader::Initialize() {
  this->GetFiles(path(this->_rowDirectory));
  this->GetFiles(path(this->_colDirectory));
}

void ConfigFileReader::Reset() {
  _fileListIterator = this->_fileList.begin();
}

std::vector<path> ConfigFileReader::GetFileList() {
  return _fileList;
}


Filename_DataPair ConfigFileReader::Next() {
  std::pair<std::string, std::vector <std::string> > fileDataPair;
  path aFile = (*_fileListIterator);
  std::string line;
  std::ifstream myfile (aFile.string().c_str());

  std::vector <std::string> fileData;

  //std::vector <std::string> fields;

 if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //fields.clear();
      //boost::split( fields, line, boost::is_any_of( "," ) );
      //

      std::cout << line << '\n';
      fileData.push_back(line);
    }
    myfile.close();
  }

  fileDataPair = std::make_pair(aFile.string(), fileData);
  return fileDataPair;
}
