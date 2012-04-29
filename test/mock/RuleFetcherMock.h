#ifndef RULE_FETCHER_MOCK_H
#define RULE_FETCHER_MOCK_H

#include <mockpp/mockpp.h> 
#include <mockpp/MockObject.h>
#include <mockpp/ExpectationList.h>
#include <mockpp/ReturnObjectList.h>
#include <mockpp/ExpectationCounter.h>


#include <mockpp/constraint/ConstraintList.h>

#include "SDL/SDL.h"

#include <IRuleFetcher.h>

#include <exception>
#include <iostream>


USING_NAMESPACE_MOCKPP

                                                                                        
class RuleFetcherMock : public IRuleFetcher
                	, public MOCKPP_NS::MockObject
{

	public:
		RuleFetcherMock() : 
		 MOCKPP_NS::MockObject(MOCKPP_PCHAR("FetcherMock"), 0)

		 
		{



		}

		virtual void SetFetcherDirectory(int a_fetcherDirectory)
		{

		}

		virtual int GetFetcherDirectory()
		{
			return 0;
		}

		virtual vector<RulePtr> GetRuleList()
		{
		}

		virtual vector<std::string> ReadRuleFile()
		{

		}

/*
		MOCKPP_NS::ReturnObjectList< vector<int> > getPositionList_data;
		MOCKPP_NS::ReturnObjectList< string > getFileNameLinked_data;
		MOCKPP_NS::ReturnObjectList< int > getRelativePositionInt_data;
		MOCKPP_NS::ExpectationList<int>  position_param_getRelativePositionInTheMap;
		*/

};

#endif                 
