#ifndef TEST_DYNAMIC_GRID_H
#define TEST_DYNAMIC_GRID_H

//#include "MockDynamicGrid.h"

#include <DynamicGrid.h>
#include <Tile.h>

#include <IConfigFileReader.h>
#include <ConfigFileReader.h>

#include <cpptest.h>
#include <exception>
#include <iostream>
#include <stdio.h>

#ifdef BOOST_ANDROID
  #include <boost/smart_ptr/shared_ptr.hpp>
#else
  #include <boost/shared_ptr.hpp>
#endif


                                                                                        
class TestDynamicGrid : public Test::Suite {

  public:
    TestDynamicGrid() {
      TEST_ADD(TestDynamicGrid::testTileRendering);
      TEST_ADD(TestDynamicGrid::testZoom);
    }

  private:
    void testTileRendering();
    void testZoom();
};


#endif                 