#include "BLWorldMapper.h"



BLWorldMapper::BLWorldMapper() {


}


BLWorldMapper::~BLWorldMapper() {


}


std::map<std::string, std::pair<int, int> > BLWorldMapper::GetVertexPair_Map() {
  std::map<std::string, std::pair<int, int> > vertexPair_Map;
  return vertexPair_Map;
}


void BLWorldMapper::ProcessFile(std::pair<std::string, std::vector <std::string> > pair_filename_dataFile) {

 
  std::stringstream concat;
  std::vector<std::string> listSplitted;
  std::vector<std::string> v = pair_filename_dataFile.second; 
  std::string keyMap;

  for(std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) {
    listSplitted.clear();
    split( listSplitted, *it, boost::algorithm::is_any_of( "," ) );
    concat.str("");

    if(listSplitted.size() >= 3) {
        boost::algorithm::trim(listSplitted[0]);
        boost::algorithm::trim(listSplitted[1]);
        boost::algorithm::trim(listSplitted[2]);

        concat << listSplitted[0] << "_" << listSplitted[1] << "_" << listSplitted[2];
        keyMap = concat.str();
    }
    /* std::cout << *it; ... */
  }

}
