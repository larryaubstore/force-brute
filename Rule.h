/**
* @file Rule.h
* @brief 
* @author Laurence Morin-Daoust
* @version 1.0
* @date 2011-07-09
*/

#ifndef RULE_H
#define RULE_H

#include <vector>
#include <string>
#include <sstream>

#include "EDirection.h"
#include "IRule.h"


class Rule : public IRule
{
    private:
        int m_OldFetcher_directory;
		int m_NewFetcher_directory;

        DIRECTION m_OldDirection;
		DIRECTION m_NewDirection;

		int m_OldPosition;
		int m_NewPosition;



    public:
		/**
		* @brief Default constructor.
		*/
        Rule();


        Rule(int a_OldFetcher_directory, int a_NewFetcher_directory,
			 DIRECTION a_OldDirection, DIRECTION a_NewDirection,
			 int a_OldPosition, int a_NewPosition);

		/**
		* @brief Destructor.
		*/
        ~Rule();

		int GetOldFetcherDirectory();

		int GetNewFetcherDirectory();

		DIRECTION GetOldDirection();

		DIRECTION GetNewDirection();

		int GetOldPosition(); 

		int GetNewPosition(); 


};


#endif
