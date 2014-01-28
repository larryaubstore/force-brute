#include "TestScreenCoord.h"
#include <TypeGeometry.h>

void TestScreenCoord::testProcessOneCoord() {
  try { 
    Point3<float> point = Point3<float>(-0.199045f, 20.943529f, 0.378205f);

    boost::shared_ptr<ScreenCoord> screenCoordPtr ( new ScreenCoord() );
    vertex_screen_pair vertexScreenPair = screenCoordPtr->ProcessOneCoord(point);

    std::cout << "Screen coordinates  => " << vertexScreenPair.screen_x << "|" << vertexScreenPair.screen_y << "\n";
    TEST_ASSERT(vertexScreenPair.screen_x == 959);
    TEST_ASSERT(vertexScreenPair.screen_y == 539);
  } catch ( const std::exception & e ) {
    std::cerr << e.what();
  }
}
