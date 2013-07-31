#ifndef DEPENDENCY_INJECTION_H
#define DEPENDENCY_INJECTION_H

#include <sauce/sauce.h>

#include "IConfigFileReader.h"
#include "ConfigFileReader.h"


using sauce::AbstractModule;

class DependencyInjection: public AbstractModule {

  void configure() const {
    bind<IConfigFileReader>().to<ConfigFileReader()>();
  }
};

#endif
