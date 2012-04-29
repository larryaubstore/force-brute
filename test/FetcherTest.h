#ifndef FETCHER_TEST
#define FETCHER_TEST


#include <cpptest.h>

#include <cstdlib>
#include <cstring>
#include <iostream>

#include <Fetcher.h>

class FetcherTest : public Test::Suite
{

    public:
        FetcherTest()
        {
            TEST_ADD(FetcherTest::testGetFileNameLinkedToPosition);

        }

    protected:
        virtual void setup()     {

//            fetcher = new Fetcher(30, 7, "/home/larry/devel/engine/images/");
            fetcher = new Fetcher(30, 7, "/home/larry/devel/engine/images");
        } // setup resources... 

        virtual void tear_down() {
            delete fetcher; 
        } // remove resources...
    private:


        Fetcher* fetcher;
        void testGetFileNameLinkedToPosition();
};

#endif
