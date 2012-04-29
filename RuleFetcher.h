#ifndef RULE_FETCHER_H
#define RULE_FETCHER_H

#include <vector>
//#include <string>
//#include <sstream>

#include "EDirection.h"
#include "IRuleFetcher.h"

#include <iostream>
#include <fstream>
#include <string>

#include "Rule.h"

using namespace std;


class RuleFetcher : public IRuleFetcher
{

    private:

		vector<RulePtr> m_ruleList;


		RulePtr ParseLine(string a_line);

		DIRECTION ConvertStringToEDirection(std::string a_direction);


    public:


        RuleFetcher();


		/**
		* @brief Destructor.
		*/
        ~RuleFetcher();

		vector<RulePtr> GetRuleList(vector<std::string> a_stringList);

		vector<std::string> ReadRuleFile(std::string a_fileName);

		void Initialize(std::string a_fileName);

		RulePtr GetRule(int a_startDomain, 
						int a_startPosition, 
						DIRECTION a_startDirection);

};


#endif
