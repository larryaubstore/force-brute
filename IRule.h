#ifndef I_RULE_H
#define I_RULE_H

#include <string>
#include <vector>

#include "EDirection.h"

using namespace std;

class IRule
{
	public:

	
		virtual int GetOldFetcherDirectory() = 0;

		virtual int GetNewFetcherDirectory() = 0;

		virtual DIRECTION GetOldDirection() = 0;

		virtual DIRECTION GetNewDirection() = 0;

		virtual int GetOldPosition() = 0; 

		virtual int GetNewPosition() = 0; 


		virtual ~IRule() {};

};


#endif
