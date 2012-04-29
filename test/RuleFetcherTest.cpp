#include "RuleFetcherTest.h"


void RuleFetcherTest::testParseLineFile()
{

	//RuleFetcherMock ruleFetcherMock;



	RuleFetcher* ruleFetcher = new RuleFetcher();

	ruleFetcher->Initialize("/home/larry/engine/rules.txt");


	RulePtr testFirstRule = ruleFetcher->GetRule(1, 2, UP);
	IRule* rule = testFirstRule.get();


	if(rule != NULL)
	{
		//1:2:UP;3:4:DOWN:
		//4:5:LEFT;6:7:RIGHT:
		TEST_ASSERT( rule->GetOldFetcherDirectory() == 1);
		TEST_ASSERT( rule->GetOldDirection() == UP);
		TEST_ASSERT( rule->GetOldPosition() == 2);

		TEST_ASSERT( rule->GetNewFetcherDirectory() == 3);
		TEST_ASSERT( rule->GetNewDirection() == DOWN);
		TEST_ASSERT( rule->GetNewPosition() == 4);

	}
	else
	{
		TEST_FAIL("RULE IS NULL");
	}


	RulePtr testSecondRule = ruleFetcher->GetRule(4, 5, LEFT);
	rule = testSecondRule.get();


	if(rule != NULL)
	{

		TEST_ASSERT( rule->GetOldFetcherDirectory() == 4);
		TEST_ASSERT( rule->GetOldDirection() == LEFT);
		TEST_ASSERT( rule->GetOldPosition() == 5);

		TEST_ASSERT( rule->GetNewFetcherDirectory() == 6);
		TEST_ASSERT( rule->GetNewDirection() == RIGHT)
		TEST_ASSERT( rule->GetNewPosition() == 7);

	}
	else
	{
		TEST_FAIL("RULE IS NULL");
	}
}

