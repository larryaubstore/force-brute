#ifndef TEST_DYNAMIC_GRID_H
#define TEST_DYNAMIC_GRID_H

//#include "MockDynamicGrid.h"

#include <DynamicGrid.h>

#include <cpptest.h>
#include <exception>
#include <iostream>



                                                                                        
class TestDynamicGrid : public Test::Suite
{

	public:
		TestDynamicGrid() 
		{
			TEST_ADD(TestDynamicGrid::testConfigFileReading);
		}

	private:
		void testConfigFileReading();
};


#endif                 
