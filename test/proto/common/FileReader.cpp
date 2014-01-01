#include "FileReader.h"


FileReader::FileReader() {


}


FileReader::~FileReader() {


}


void FileReader::OpenFile(std::string filename) {
  //this->_fileStream (filename);
  _fileStream.open(filename.c_str());
}

std::string FileReader::ReadLine() {
  return _currentLine;
}

bool FileReader::HasNext() {
  bool hasNext = getline(_fileStream, _currentLine);
  return hasNext;
}

void FileReader::CloseFile() {
  _fileStream.close();
}
