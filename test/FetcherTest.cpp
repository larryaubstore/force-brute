#include "FetcherTest.h"


void FetcherTest::testGetFileNameLinkedToPosition()
{

    std::string fileNameLinkedToPosition = fetcher->GetFileNameLinkedToPosition(3);
	std::cout << "FILENAME --> " << fileNameLinkedToPosition << "\n";
    TEST_ASSERT( fileNameLinkedToPosition.compare(fetcher->GetPrefix() //+ 
//							directoryToString.str() 
							+ "/" + "0003.jpg") == 0);


    fileNameLinkedToPosition = fetcher->GetFileNameLinkedToPosition(13);
	std::cout << "FILENAME --> " << fileNameLinkedToPosition << "\n";
    TEST_ASSERT( fileNameLinkedToPosition.compare(fetcher->GetPrefix() + 
		/*directoryToString.str() + */ "/" + "0013.jpg") == 0);


    fileNameLinkedToPosition = fetcher->GetFileNameLinkedToPosition(113);
	std::cout << "FILENAME --> " << fileNameLinkedToPosition << "\n";
    TEST_ASSERT( fileNameLinkedToPosition.compare(fetcher->GetPrefix() + 
		/*directoryToString.str() + */ "/" + "0113.jpg") == 0);


}
