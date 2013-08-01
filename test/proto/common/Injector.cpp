#include "Injector.h"


Injector::Injector(std::string filename) {
  this->_filename = filename;
}


Injector::~Injector() {

}

DynamicGridSharedPtr Injector::GetDynamicGrid() {
  DynamicGridSharedPtr ptr = NULL_PTR;
  return ptr;
}

ConfigFileReaderSharedPtr Injector::GetConfigFileReader() {
  ConfigFileReaderSharedPtr ptr = NULL_PTR;
  if(!_filename.empty()) {

  }
  return ptr;
}

std::string Injector::GetFilename() {
  return _filename;
}


RendererSharedPtr Injector::GetRenderer() {
  RendererSharedPtr ptr = NULL_PTR;

  //RendererSharedPtr<SDL_Surface> ptr;
  //return NULL_PTR_TYPE;
  return ptr;
}



