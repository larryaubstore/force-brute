#ifndef GAME_MODEL_TEST
#define GAME_MODEL_TEST


#include <cpptest.h>

#include <cstdlib>
#include <cstring>
#include <iostream>

//#include <Loader.h>
//#include "mock/FetcherMock.h"
//#include <boost/shared_ptr.hpp>

class GameModelTest : public Test::Suite
{

    public:
        GameModelTest()
        {

        }

    protected:
        virtual void setup()     {

			// 3 --> buffer_dimension
            //loader = new Loader(&fetcherMock, 3);
			// 1 --> position, initialize a buffer 3x3 at position 1.
			//loader->initialize(1);
        
        } // setup resources... 

        virtual void tear_down() {
            //delete loader; 
        } // remove resources...
    private:

		void testAjoutMissile();


};

#endif
