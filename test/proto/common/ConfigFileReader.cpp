#include "ConfigFileReader.h"

ConfigFileReader::ConfigFileReader(std::string rowDirectory, 
                                   std::string colDirectory, 
                                   boost::shared_ptr<IFileReader> fileReaderPtr) {
  this->_rowDirectory = rowDirectory;
  this->_colDirectory = colDirectory;
  this->_fileReaderPtr = fileReaderPtr;
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


bool ConfigFileReader::HasNext() {
  bool hasNext = false;
  if(this->_fileListIterator != this->_fileList.end()) {
    hasNext = true;
  }
  return hasNext;
}


Filename_DataPair ConfigFileReader::Next() {
  std::pair<std::string, std::vector <std::string> > fileDataPair;

  if(this->HasNext()) {
    path aFile = (*_fileListIterator);
    std::string line;
    std::vector <std::string> fileData;

    this->_fileReaderPtr->OpenFile(aFile.string());
      
    while (this->_fileReaderPtr->HasNext()) {
      line = this->_fileReaderPtr->ReadLine();
      std::cout << line << '\n';
      fileData.push_back(line);
    }
    this->_fileReaderPtr->CloseFile();

    fileDataPair = std::make_pair(aFile.string(), fileData);
    this->_fileListIterator++;
  }
  return fileDataPair;
}
