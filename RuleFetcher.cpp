#include "RuleFetcher.h"


typedef boost::shared_ptr< IRule > RulePtr;


vector<RulePtr> RuleFetcher::GetRuleList(vector<std::string> a_stringList)
{
	vector<RulePtr> ruleList;
	std::string element; 

	RulePtr rulePtr;
	for(int i = 0; i < a_stringList.size(); i++)
	{
		element = a_stringList[i];	
		rulePtr.reset();
	 	rulePtr = ParseLine(element);
		ruleList.push_back(rulePtr);

	}
	return ruleList;
	

}


RuleFetcher::~RuleFetcher()
{

}


RuleFetcher::RuleFetcher()
{

}

RulePtr RuleFetcher::ParseLine(string a_line)
{

	int length = 0;

	/* Start domain */
	string::size_type markerStartDomain = a_line.find(":");
	string startDomain = a_line.substr(0, markerStartDomain);
	int i_startDomain = atoi(startDomain.c_str());

	/* Start position */
	string::size_type markerStartPosition 
		= a_line.find_first_of(":", markerStartDomain + 1);
	length = markerStartPosition - (markerStartDomain + 1);	
	string startPositionStr = a_line.substr(markerStartDomain + 1, length);
	int i_startPosition = atoi(startPositionStr.c_str());

	/* Start direction */
	string::size_type markerStartDirection
		= a_line.find_first_of(";", markerStartPosition + 1);
	length = markerStartDirection - (markerStartPosition + 1);
	string startDirection = 
		a_line.substr(markerStartPosition + 1, length);
	DIRECTION d_startDirection = ConvertStringToEDirection(startDirection);


	/* END DOMAIN */
	string::size_type markerEndDomain 
		= a_line.find_first_of(":", markerStartDirection + 1);
	length = markerEndDomain - (markerStartDirection + 1 );	
	string endDomainStr = a_line.substr(markerStartDirection + 1, length);
	int i_endDomain = atoi(endDomainStr.c_str());


	/* END POSITION */
	string::size_type markerEndPosition 
		= a_line.find_first_of(":", markerEndDomain + 1);
	length = markerEndPosition - (markerEndDomain + 1);	
	string endPositionStr = a_line.substr(markerEndDomain + 1, length);
	int i_endPosition = atoi(endPositionStr.c_str());


	/* END DIRECTION */
	string::size_type markerEndDirection
		= a_line.find_first_of(";", markerEndPosition + 1);
	length = markerEndDirection - (markerEndPosition + 1);
	string endDirection = 
		a_line.substr(markerEndPosition + 1, length);
	DIRECTION d_endDirection = ConvertStringToEDirection(endDirection);




	RulePtr rulePtr(new Rule(i_startDomain,
							 i_endDomain,
							 d_startDirection,
							 d_endDirection, 
							 i_startPosition, 
						     i_endPosition));	
	return rulePtr;

}

DIRECTION RuleFetcher::ConvertStringToEDirection(std::string a_direction)
{
	DIRECTION direction;
	if(a_direction.compare("DOWN") == 0)
	{
		direction = DOWN;
	}
	else if(a_direction.compare("UP") == 0)
	{
		direction = UP;
	}
	else if(a_direction.compare("LEFT") == 0)
	{
		direction = LEFT;
	}
	else
	{
		direction = RIGHT;
	}
	return direction;
}



vector<std::string> RuleFetcher::ReadRuleFile(std::string a_fileName)
{
	vector<std::string> listOfLines;
	string line;
  	ifstream myfile (a_fileName.c_str());
    if (myfile.is_open())
	{
		while ( myfile.good() )
		{
			getline (myfile,line);
			listOfLines.push_back(line);
		}
		myfile.close();
	}
	return listOfLines;

}

void RuleFetcher::Initialize(std::string a_fileName)
{
	vector<string> rawRules =
        ReadRuleFile(a_fileName);

	m_ruleList = GetRuleList(rawRules);


}

RulePtr RuleFetcher::GetRule(int a_startDomain, 
							 int a_startPosition, 
							 DIRECTION a_startDirection)
{

	
	RulePtr rulePtr; 
	IRule* element; 
	for(int i = 0; i < m_ruleList.size()  ; i++)
	{

		element = m_ruleList[i].get();

		/*
		TEST_ASSERT( rule->GetOldFetcherDirectory() == 1);
		TEST_ASSERT( rule->GetOldDirection() == UP);
		TEST_ASSERT( rule->GetOldPosition() == 2);
		*/

		
		if(element->GetOldFetcherDirectory() == a_startDomain &&
		   element->GetOldPosition() == a_startPosition &&
		   element->GetOldDirection() == a_startDirection)
		{

			return m_ruleList[i];
		}
	}

	return rulePtr;


}
