#include "TestFileReader.h"
#include <TypeDefEngine.h>

class MockFileReader: public IFileReader {

  private:

    boost::shared_ptr<FileReader> _realInstance;
    bool _openFileCalled;
    bool _readLineCalled;
    bool _closeFileCalled;
    bool _hasNextCalled;

    std::vector<std::string> _lines;


  public:
    MockFileReader(boost::shared_ptr<FileReader> realInstance) {
      this->_realInstance = realInstance;
      this->_openFileCalled = false;
      this->_readLineCalled = false;
      this->_closeFileCalled = false;
      this->_hasNextCalled = false;

      this->_lines.push_back("144, 155");
      this->_lines.push_back("164, 175");
      this->_lines.push_back("184, 195");
    }

    void OpenFile(std::string filename) {
      this->_openFileCalled = true;
    }

    std::string ReadLine() {
      this->_readLineCalled = true;
      return ""; 
    }

    void CloseFile() {
      this->_closeFileCalled = true;
    }

    bool OpenFileCalled() {
      return this->_openFileCalled;
    }

    bool ReadLineCalled() {
      return this->_readLineCalled;
    }

    bool HasNextCalled() {
      return this->_hasNextCalled;
    }

    bool HasNext() {
      this->_hasNextCalled = true;
      return true;
    }


    bool CloseFileCalled() {
      return this->_closeFileCalled;
    }
};



void TestFileReader::testFileReaderProcess() {
  try {

    boost::shared_ptr<FileReader> fileSharedPtr ( new FileReader() );
    boost::shared_ptr<MockFileReader> mockFileSharedPtr ( new MockFileReader(fileSharedPtr) );


    
    //TEST_ASSERT(tileConverted_vector[1]->GetXPos() == -125);



    //fileSharedPtr->
  } catch ( const std::exception & e ) {
    std::cerr << e.what();
  }
}
