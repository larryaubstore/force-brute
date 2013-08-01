#ifndef INJECTOR_H
#define INJECTOR_H

#include "IInjector.h"


class Injector: public IInjector {

  private:
    std::string _filename;
  public:
    Injector(std::string filename);
    ~Injector();
    virtual std::string GetFilename();
    virtual DynamicGridSharedPtr GetDynamicGrid();
    virtual ConfigFileReaderSharedPtr GetConfigFileReader();
    virtual RendererSharedPtr GetRenderer(); 

};

#endif
