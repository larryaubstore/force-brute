#ifndef ANIMATION_TEST_H
#define ANIMATION_TEST_H

#include <mockpp/mockpp.h> 

#include <mockpp/MockObject.h>
#include <mockpp/ExpectationList.h>
#include <mockpp/ReturnObjectList.h>
#include <mockpp/ExpectationCounter.h>


#include <Animation.h>

#include <cpptest.h>

#include <exception>
#include <iostream>

#include <GameModel.h>



                                                                                        
class AnimationTest : public Test::Suite
{

	public:
		AnimationTest() 
		{
			TEST_ADD(AnimationTest::testConstructor);
		}

	private:
		void testConstructor();
};


#endif                 
