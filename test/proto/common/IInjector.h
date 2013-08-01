#ifndef I_INJECTOR_H
#define I_INJECTOR_H

#include "TypeDefEngine.h"

class IInjector
{
	public:

    virtual ~IInjector() {};
    virtual std::string GetFilename() = 0;
    virtual DynamicGridSharedPtr GetDynamicGrid() = 0;
    virtual ConfigFileReaderSharedPtr GetConfigFileReader() = 0;
    virtual RendererSharedPtr GetRenderer() = 0;
};

#endif
