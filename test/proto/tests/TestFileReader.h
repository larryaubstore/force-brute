#ifndef TEST_FILEREADER_H
#define TEST_FILEREADER_H


#include <IFileReader.h>
#include <FileReader.h>



#include <cpptest.h>
#include <exception>
#include <iostream>
#include <stdio.h>

#ifdef BOOST_ANDROID
  #include <boost/smart_ptr/shared_ptr.hpp>
#else
  #include <boost/shared_ptr.hpp>
#endif

class TestFileReader : public Test::Suite {

  public:
    TestFileReader() {
      TEST_ADD(TestFileReader::testFileReaderProcess);
    }

  private:
    void testFileReaderProcess();
};



#endif
