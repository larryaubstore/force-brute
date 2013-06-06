#ifndef SCENE_STACK_TEST_H
#define SCENE_STACK_TEST_H

#include <mockpp/mockpp.h> 

#include <mockpp/MockObject.h>
#include <mockpp/ExpectationList.h>
#include <mockpp/ReturnObjectList.h>
#include <mockpp/ExpectationCounter.h>


#include <SceneStack.h>

#include <cpptest.h>

#include <exception>
#include <iostream>




                                                                                        
class SceneStackTest : public Test::Suite
{

	public:
		SceneStackTest() 
		{
			TEST_ADD(SceneStackTest::testPush);
		}

	private:
		void testPush();
};


#endif                 
