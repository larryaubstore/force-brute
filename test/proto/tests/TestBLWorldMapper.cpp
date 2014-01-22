#include "TestBLWorldMapper.h"

void TestBLWorldMapper::testProcessFile() {
  try { 
    std::vector<std::string> data;

    data.push_back("-19.151283, 1.621236, 0.380611,");
    data.push_back("2.296391, -18.799578, 0.375799,");
    data.push_back("-8.427446, -8.589170, 0.378205,");

    //std::string filename = "ROW_4"; 

    std::pair<std::string, std::vector<std::string> > pair_filename_vectorstring;

    boost::shared_ptr<BLWorldMapper> blWorldMapperPtr ( new BLWorldMapper() );

    pair_filename_vectorstring = std::make_pair("filename", data);
    blWorldMapperPtr->ProcessFile(pair_filename_vectorstring);

    std::cout << "Vertex Col Map Size => " << blWorldMapperPtr->GetVertexPair_Map().size() << "\n";
    TEST_ASSERT(blWorldMapperPtr->GetVertexPair_Map().size() == 3);

  } catch ( const std::exception & e ) {
    std::cerr << e.what();
  }
}
