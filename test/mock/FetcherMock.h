#ifndef FETCHER_MOCK_H
#define FETCHER_MOCK_H

#include <mockpp/mockpp.h> 
#include <mockpp/MockObject.h>
#include <mockpp/ExpectationList.h>
#include <mockpp/ReturnObjectList.h>
#include <mockpp/ExpectationCounter.h>


#include <mockpp/constraint/ConstraintList.h>

#include "SDL/SDL.h"

#include <IFetcher.h>

#include <exception>
#include <iostream>


USING_NAMESPACE_MOCKPP

                                                                                        
class FetcherMock : public IFetcher
                	, public MOCKPP_NS::MockObject
{

	public:
		FetcherMock() : 
		 MOCKPP_NS::MockObject(MOCKPP_PCHAR("FetcherMock"), 0),
		 getPositionList_data(MOCKPP_PCHAR("Fetcher/getPositionList_data"), this),
		 getFileNameLinked_data(MOCKPP_PCHAR("Fetcher/getFileNameLinked_data"), this),
		 getRelativePositionInt_data(MOCKPP_PCHAR("Fetcher/getRelativePositionInt_data"), this),
		 position_param_getRelativePositionInTheMap(MOCKPP_PCHAR("Fetcher/position_param_getRelativePositionInTheMap"), this)
		{



		}

		virtual string GetFileNameLinkedToPosition(int position) 
		{
			return getFileNameLinked_data.nextReturnObject();
		}

		virtual string GetFileNameLinkedToPosition(int position, 
										std::string fetcher_directory)
		{
			return getFileNameLinked_data.nextReturnObject();
		}


		virtual int GetRelativePositionInTheMap(int position)
		{
			position_param_getRelativePositionInTheMap.addActual(position);	
			return getRelativePositionInt_data.nextReturnObject();

		}

		virtual std::string GetPrefix()
		{
			return 0;
		}

		virtual void SetPrefix(std::string prefix)
		{

		}

		MOCKPP_NS::ReturnObjectList< vector<int> > getPositionList_data;
		MOCKPP_NS::ReturnObjectList< string > getFileNameLinked_data;
		MOCKPP_NS::ReturnObjectList< int > getRelativePositionInt_data;
		MOCKPP_NS::ExpectationList<int>  position_param_getRelativePositionInTheMap;

};

#endif                 
