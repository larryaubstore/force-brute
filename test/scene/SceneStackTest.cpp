#include "SceneStackTest.h"

using namespace std;

void SceneStackTest::testPush()
{

	MOCKPP_TRY {
	
		auto_ptr<SceneStack> ptr(new SceneStack());
		ptr->Push("BOAT", 1, 30, true, 10, 100, 25); 
		ptr->Push("BOAT2", 1, 30, true, 10, 100, 25);

		 
		TEST_ASSERT(ptr->GetAnimationList().size() == 2);


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
