#ifndef TEST_DYNAMIC_GRID_H
#define TEST_DYNAMIC_GRID_H

//#include "MockDynamicGrid.h"

#include <DynamicGrid.h>
#include <Tile.h>

#include <cpptest.h>
#include <exception>
#include <iostream>

#ifdef BOOST_ANDROID
  #include <boost/smart_ptr/shared_ptr.hpp>
#else
  #include <boost/shared_ptr.hpp>
#endif


                                                                                        
class TestDynamicGrid : public Test::Suite
{

	public:
		TestDynamicGrid() 
		{
			TEST_ADD(TestDynamicGrid::testTileRendering);
		}

	private:
		void testTileRendering();
};


#endif                 
