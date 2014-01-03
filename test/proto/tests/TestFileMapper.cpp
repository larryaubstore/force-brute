#include "TestFileMapper.h"

void TestFileMapper::testProcessFile() {
  try { 
    std::vector<std::string> data;
    data.push_back("133,31");
    data.push_back("156,58");
    data.push_back("191,28");

    std::string filename = "ROW_4"; 

    std::pair<std::string, std::vector<std::string> > filename_dataFile;
    filename_dataFile = std::make_pair(filename, data);

    boost::shared_ptr<FileMapper> fileMapperPtr ( new FileMapper() );

    fileMapperPtr->ProcessFile(filename_dataFile);

    std::cout << "Vertex Row Map Size => " << fileMapperPtr->GetVertexRowMap().size() << "\n";
    std::cout << "Vertex Col Map Size => " << fileMapperPtr->GetVertexColMap().size() << "\n";
    TEST_ASSERT(fileMapperPtr->GetVertexRowMap().size() == 3);

  } catch ( const std::exception & e ) {
    std::cerr << e.what();
  }
}

void TestFileMapper::testProcessFileDuplicate() {
  try { 
    std::vector<std::string> data;
    data.push_back("133,31");
    data.push_back("133,31");
    data.push_back("191,28");

    std::string filename = "ROW_4"; 

    std::pair<std::string, std::vector<std::string> > filename_dataFile;
    filename_dataFile = std::make_pair(filename, data);

    boost::shared_ptr<FileMapper> fileMapperPtr ( new FileMapper() );

    fileMapperPtr->ProcessFile(filename_dataFile);

    std::cout << "Vertex Row Map Size => " << fileMapperPtr->GetVertexRowMap().size() << "\n";
    std::cout << "Vertex Col Map Size => " << fileMapperPtr->GetVertexColMap().size() << "\n";
    TEST_ASSERT(fileMapperPtr->GetVertexRowMap().size() == 2);

  } catch ( const std::exception & e ) {
    std::cerr << e.what();
  }
}
