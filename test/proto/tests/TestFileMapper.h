#ifndef TEST_FILEMAPPER_H
#define TEST_FILEMAPPER_H

#include <exception>
#include <iostream>
#include <stdio.h>

#ifdef BOOST_ANDROID
  #include <boost/smart_ptr/shared_ptr.hpp>
#else
  #include <boost/shared_ptr.hpp>
#endif

#include <FileMapper.h>
#include <cpptest.h>

class TestFileMapper : public Test::Suite {

  public:
    TestFileMapper() {
      TEST_ADD(TestFileMapper::testProcessFile);
      TEST_ADD(TestFileMapper::testProcessFileDuplicate);
    }

  private:
    void testProcessFile();
    void testProcessFileDuplicate();
};



#endif
