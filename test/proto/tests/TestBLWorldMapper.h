#ifndef TEST_BL_WORLD_MAPPER_H
#define TEST_BL_WORLD_MAPPER_H

#include <exception>
#include <iostream>
#include <stdio.h>

#ifdef BOOST_ANDROID
  #include <boost/smart_ptr/shared_ptr.hpp>
#else
  #include <boost/shared_ptr.hpp>
#endif


#include <BLWorldMapper.h>
#include <cpptest.h>
#include <string>
#include <vector>

class TestBLWorldMapper : public Test::Suite {

  public:
    TestBLWorldMapper() {
      TEST_ADD(TestBLWorldMapper::testProcessFile);
    }

  private:
    void testProcessFile();
};



#endif
