#include "GameModelControllerTest.h"

void GameModelControllerTest::testHandleKeyEvent()
{

	MOCKPP_TRY
  	{
/*
		typedef struct{
		  	Uint8 type;
		    Uint8 state;
			SDL_keysym keysym;
		} SDL_KeyboardEvent;
*/

/*
		typedef struct{
			Uint8 scancode;
		    SDLKey sym;
			SDLMod mod;
		    Uint16 unicode;
		} SDL_keysym;
		*/

		SDL_KeyboardEvent keyboardEvent;
		SDL_keysym key;
		key.sym = SDLK_LEFT;
		keyboardEvent.keysym = key;

		GameModelControllerMock mock;
		//mock.handleKeyEvent_name.addExpected(SDLK_LEFT);

		mock.handleKeyEvent_name.addExpected(SDLK_LEFT);

		// Run Consumer object
		MOCKPP_STD_NS::cout 
			<< MOCKPP_STD_NS::endl
			<< "GameModelControllerTest::testHandleKeyEvent" 
			<< MOCKPP_STD_NS::endl;


		/********************** SCENARIO ****************************/ 
		//GameModelController gameModelController( &mock );
		//gameModelController.handleKeyEvent(5);


		//mock.handleKeyEvent(&keyboardEvent);

	   	MOCKPP_STD_NS::cout << "Tests finished" << MOCKPP_STD_NS::endl;

		/*********************** VERIFY *****************************/
		mock.verify();

		MOCKPP_STD_NS::cout 
			<< "All tests have passed successfully" 
			<< MOCKPP_STD_NS::endl
			<< MOCKPP_STD_NS::endl;
	}
	MOCKPP_CATCH(MOCKPP_STD_NS::exception &ex)
	{
		#ifndef MOCKPP_NO_EXCEPTIONS
		MOCKPP_STD_NS::cout << MOCKPP_STD_NS::endl
	     << "Error occured.\n" << ex.what() << MOCKPP_STD_NS::endl
	     << MOCKPP_STD_NS::endl;
		#endif
	}
}


void GameModelControllerTest::testCommunicationWithGameModel()
{

	MOCKPP_TRY
  	{
		GameModelMock mock;
		LoaderMock loaderMock;
		FetcherMock fetcherMock;

		SDL_KeyboardEvent keyboardEvent;
		SDL_keysym key;
		key.sym = SDLK_LEFT;
		keyboardEvent.keysym = key;
		mock.changeDirection_name.addExpected(LEFT);


		// Run Consumer object
		MOCKPP_STD_NS::cout 
			<< MOCKPP_STD_NS::endl
			<< "GameModelControllerTest::testCommunicationWithGameModel" 
			<< MOCKPP_STD_NS::endl;

		GameModelController* controller = new GameModelController(&mock, &loaderMock,
																&fetcherMock, NULL, 
																NULL);
		//controller->handleKeyEvent(&keyboardEvent);

		MOCKPP_STD_NS::cout << "Tests finished" << MOCKPP_STD_NS::endl;

		/*********************** VERIFY *****************************/
		mock.verify();

		MOCKPP_STD_NS::cout << "All tests have passed successfully" 
							<< MOCKPP_STD_NS::endl
							<< MOCKPP_STD_NS::endl;
	}
	MOCKPP_CATCH(MOCKPP_STD_NS::exception &ex)
	{
		#ifndef MOCKPP_NO_EXCEPTIONS
		MOCKPP_STD_NS::cout << MOCKPP_STD_NS::endl
	     << "Error occured.\n" << ex.what() << MOCKPP_STD_NS::endl
	     << MOCKPP_STD_NS::endl;
		#endif
	}
}


void GameModelControllerTest::testPathMissile()
{

	MOCKPP_TRY
  	{
		GameModel gameModel(UP, 0, 0, "", "");
		LoaderMock loaderMock;
		FetcherMock fetcherMock;


		// Run Consumer object
		MOCKPP_STD_NS::cout 
			<< MOCKPP_STD_NS::endl
			<< "GameModelControllerTest::testCommunicationWithGameModel" 
			<< MOCKPP_STD_NS::endl;

		GameModelController* controller = new GameModelController(&gameModel, 
																  &loaderMock,
																&fetcherMock, NULL, 
																NULL);

		gameModel.nextPosition();
		TEST_ASSERT(gameModel.getPosition() == 1);



		printf("Ajout Missile \n");
		gameModel.lanceMissile();


		TEST_ASSERT(gameModel.GetPathMissileList().size() == 1 );


		PathMissilePtr missilePtr = gameModel.GetPathMissileList()[0];


		IPathMissile* missile = missilePtr.get();


		
		printf("Test coordonnées missile - Position 1\n");
		TEST_ASSERT(missile->getPosition() == 1);
		TEST_ASSERT(missile->getEndPosition() == 121);
		TEST_ASSERT(missile->getStartPosition() == 1);


		// Avancer à la prochaine position
		gameModel.nextPosition();
		TEST_ASSERT(missile->getPosition() == 2);
		TEST_ASSERT(missile->getEndPosition() == 121);
		TEST_ASSERT(missile->getStartPosition() == 1);

		MOCKPP_STD_NS::cout << "Tests finished" << MOCKPP_STD_NS::endl;

		/*********************** VERIFY *****************************/
		//mock.verify();

		MOCKPP_STD_NS::cout << "All tests have passed successfully" 
							<< MOCKPP_STD_NS::endl
							<< MOCKPP_STD_NS::endl;
	}
	MOCKPP_CATCH(MOCKPP_STD_NS::exception &ex)
	{
		#ifndef MOCKPP_NO_EXCEPTIONS
		MOCKPP_STD_NS::cout << MOCKPP_STD_NS::endl
	     << "Error occured.\n" << ex.what() << MOCKPP_STD_NS::endl
	     << MOCKPP_STD_NS::endl;
		#endif
	}
}


void GameModelControllerTest::testMissileAutoDestruction()
{

	MOCKPP_TRY
  	{
		GameModel gameModel(UP, 0, 0, "", "");
		LoaderMock loaderMock;
		FetcherMock fetcherMock;


		// Run Consumer object
		MOCKPP_STD_NS::cout 
			<< MOCKPP_STD_NS::endl
			<< "GameModelControllerTest::testCommunicationWithGameModel" 
			<< MOCKPP_STD_NS::endl;

		GameModelController* controller = new GameModelController(&gameModel, 
																  &loaderMock,
																&fetcherMock, NULL, 
																NULL);

		// Position GameModel
		gameModel.nextPosition();
		TEST_ASSERT(gameModel.getPosition() == 1);

		// Ajout missile #1
		gameModel.lanceMissile();

		// Est-ce que nous avons un missile dans la liste 
		TEST_ASSERT(gameModel.GetPathMissileList().size() == 1 );


		// Est-ce que le missile #1 est à la bonne position
		PathMissilePtr missilePtr = gameModel.GetPathMissileList()[0];
		IPathMissile* missile = missilePtr.get();
		TEST_ASSERT(missile->getPosition() == 1);
		TEST_ASSERT(missile->getEndPosition() == 121);
		TEST_ASSERT(missile->getStartPosition() == 1);

		// Avancer à la prochaine position
		// Tester si le missile a avancé correctement
		gameModel.nextPosition();
		TEST_ASSERT(missile->getPosition() == 2);
		TEST_ASSERT(missile->getEndPosition() == 121);
		TEST_ASSERT(missile->getStartPosition() == 1);


		// Avancer de 10 positions
		for(int i = 0; i < 10; i++)
		{
			gameModel.nextPosition();
		}

		// Tester si le missile a avancé correctement
		TEST_ASSERT(missile->getPosition() == 12);

		// Ajout missile #2
		gameModel.lanceMissile();

		// Vérifier qu'il y a deux missiles dans la liste 
		TEST_ASSERT(gameModel.GetPathMissileList().size() == 2 );

		// Avancer de 109 positions
		for(int i = 0; i < 109; i++)
		{
			gameModel.nextPosition();
		}

		// Vérifier qu'il n'y plus qu'un missile
		TEST_ASSERT(gameModel.GetPathMissileList().size() == 1 );

		// On réaffecte le pointeur du missile
		missile = gameModel.GetPathMissileList()[0].get();

		// Tester si le missile #2 a avancé correctement
		TEST_ASSERT(missile->getPosition() == 109);



		MOCKPP_STD_NS::cout << "Tests finished" << MOCKPP_STD_NS::endl;

		/*********************** VERIFY *****************************/
		//mock.verify();

		MOCKPP_STD_NS::cout << "All tests have passed successfully" 
							<< MOCKPP_STD_NS::endl
							<< MOCKPP_STD_NS::endl;
	}
	MOCKPP_CATCH(MOCKPP_STD_NS::exception &ex)
	{
		#ifndef MOCKPP_NO_EXCEPTIONS
		MOCKPP_STD_NS::cout << MOCKPP_STD_NS::endl
	     << "Error occured.\n" << ex.what() << MOCKPP_STD_NS::endl
	     << MOCKPP_STD_NS::endl;
		#endif
	}
}


