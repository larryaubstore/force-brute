#include "TestFileMapper.h"

void TestFileMapper::testProcessFile() {
  try { 
    std::vector<std::string> data;

    data.push_back("-19.151283, 1.621236, 0.380611,");
    data.push_back("2.296391, -18.799578, 0.375799,");
    data.push_back("-8.427446, -8.589170, 0.378205,");

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
    data.push_back("-19.151283, 1.621236, 0.380611,");
    data.push_back("2.296391, -18.799578, 0.375799,");
    data.push_back("2.296391, -18.799578, 0.375799,");
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
