#ifndef RULE_FETCHER_TEST
#define RULE_FETCHER_TEST


#include <cpptest.h>

#include <cstdlib>
#include <cstring>
#include <iostream>


#include <RuleFetcher.h>


#include <boost/shared_ptr.hpp>
#include "mock/RuleFetcherMock.h"

class RuleFetcherTest : public Test::Suite
{

	typedef boost::shared_ptr< IRule > RulePtr;  

    public:
        RuleFetcherTest()
        {
			TEST_ADD(RuleFetcherTest::testParseLineFile);
        }

    protected:
        virtual void setup()     {

			//createTestFile("/home/larry/devel/engine/test/testrules.txt");

			// 3 --> buffer_dimension
            //loader = new Loader(&fetcherMock, 3);
			// 1 --> position, initialize a buffer 3x3 at position 1.
			//loader->initialize(1);
        
        } // setup resources... 

        virtual void tear_down() {

			//remove("/home/larry/devel/engine/test/testrules.txt");
            //delete loader; 
        } // remove resources...
    private:

		void testParseLineFile();
		void testGetRuleList();



};

#endif
