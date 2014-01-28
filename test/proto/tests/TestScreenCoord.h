#ifndef TEST_SCREEN_COORD_H
#define TEST_SCREEN_COORD_H

#include <exception>
#include <iostream>
#include <stdio.h>

#ifdef BOOST_ANDROID
  #include <boost/smart_ptr/shared_ptr.hpp>
#else
  #include <boost/shared_ptr.hpp>
#endif


#include <ScreenCoord.h>
#include <cpptest.h>
#include <string>
#include <vector>

class TestScreenCoord : public Test::Suite {

  public:
    TestScreenCoord() {
      TEST_ADD(TestScreenCoord::testProcessOneCoord);
    }

  private:
    void testProcessOneCoord();
};



#endif
