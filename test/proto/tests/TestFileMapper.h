#ifndef TEST_FILEMAPPER_H
#define TEST_FILEMAPPER_H

#include <cpptest.h>
#include <exception>
#include <iostream>
#include <stdio.h>

class TestFileMapper : public Test::Suite {

  public:
    TestFileMapper() {
      TEST_ADD(TestFileMapper::testProcessFile);
    }

  private:
    void testProcessFile();
};



#endif
