#include "TestDynamicGrid.h"

void TestDynamicGrid::testTileRendering()
{

    SurfaceSharedPtr surfaceSharedPtr;
    TileSharedPtr firstTile(new Tile(0, 0, surfaceSharedPtr));
    //boost::shared_ptr<DynamicGrid> DynamicGridSharedPtr(new ;
//		GameModel gameModel(UP, 0, 0, "", "");
//		LoaderMock loaderMock;
//		FetcherMock fetcherMock;
//
//
//		GameModelController* controller = new GameModelController(&gameModel, 
//																  &loaderMock,
//																NULL, 
//																NULL);
//
//		gameModel.nextPosition();
//		TEST_ASSERT(gameModel.getPosition() == 1);
//
//
//
//		printf("Ajout Missile \n");
//		gameModel.lanceMissile();
//		TEST_ASSERT(gameModel.GetPathMissileList().size() == 1 );
//		PathMissilePtr missilePtr = gameModel.GetPathMissileList()[0];
//		IPathMissile* missile = missilePtr.get();
//
//		
//		printf("Test coordonnées missile - Position 1\n");
//		TEST_ASSERT(missile->getPosition() == 1);
//		TEST_ASSERT(missile->getEndPosition() == 121);
//		TEST_ASSERT(missile->getStartPosition() == 1);
//
//
//		// Avancer à la prochaine position
//		gameModel.nextPosition();
//		TEST_ASSERT(missile->getPosition() == 2);
//		TEST_ASSERT(missile->getEndPosition() == 121);
//		TEST_ASSERT(missile->getStartPosition() == 1);
//
//
//		/*********************** VERIFY *****************************/
//		//mock.verify();

}
