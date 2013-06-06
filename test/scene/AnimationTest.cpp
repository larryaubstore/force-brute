#include "AnimationTest.h"

void AnimationTest::testConstructor()
{

	MOCKPP_TRY {
		Animation* animation = new Animation("BOAT", 1, 30, true, 10, 100, 25); 

		TEST_ASSERT(animation->GetName() == "BOAT");
		TEST_ASSERT(animation->GetStartFrame() == 1);
		TEST_ASSERT(animation->GetEndFrame() == 30);
		TEST_ASSERT(animation->IsPermanent() == true);
		TEST_ASSERT(animation->GetXPosition() == 10);
		TEST_ASSERT(animation->GetYPosition() == 100);
		TEST_ASSERT(animation->GetCurrentFrame() == 25);

	}
	MOCKPP_CATCH(MOCKPP_STD_NS::exception &ex)
	{
		#ifndef MOCKPP_NO_EXCEPTIONS
		MOCKPP_STD_NS::cout << MOCKPP_STD_NS::endl
	     << "Error occured.\n" << ex.what() << MOCKPP_STD_NS::endl
	     << MOCKPP_STD_NS::endl;
		#endif
	}
}
