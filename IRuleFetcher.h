#ifndef I_RULE_FETCHER_H
#define I_RULE_FETCHER_H

#include <string>
#include <vector>

#include "EDirection.h"
#include "IRule.h"

#include <boost/shared_ptr.hpp>

using namespace std;


class IRuleFetcher
{


	public:

		typedef boost::shared_ptr< IRule > RulePtr;

		/*
		virtual void SetFetcherDirectory(int a_fetcherDirectory) = 0;
		virtual int GetFetcherDirectory() = 0;
		*/

		/*
		virtual vector<RulePtr> GetRuleList(vector<std::string> a_stringList) = 0;
		virtual vector<std::string> ReadRuleFile(std::string a_fileName) = 0;
		*/

		virtual void Initialize(std::string a_fileName) = 0;

		virtual RulePtr GetRule(int a_startDomain, int a_startPosition, DIRECTION a_startDirection) = 0;


		virtual ~IRuleFetcher() {};

};


#endif
