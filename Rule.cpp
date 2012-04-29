#include "Rule.h"


int Rule::GetOldFetcherDirectory()
{
	return m_OldFetcher_directory;
}

int Rule::GetNewFetcherDirectory()
{
	return m_NewFetcher_directory;
}

DIRECTION Rule::GetOldDirection()
{
	return m_OldDirection;
}

DIRECTION Rule::GetNewDirection()
{
	return m_NewDirection;
}


int Rule::GetOldPosition()
{
	return m_OldPosition;
}

int Rule::GetNewPosition()
{
	return m_NewPosition;
}


Rule::Rule()
{


}


Rule::~Rule()
{

}

Rule::Rule(int a_OldFetcher_directory, int a_NewFetcher_directory,
			 DIRECTION a_OldDirection, DIRECTION a_NewDirection,
			 int a_OldPosition, int a_NewPosition)
{
	this->m_OldFetcher_directory 	= a_OldFetcher_directory;
	this->m_NewFetcher_directory 	= a_NewFetcher_directory;
	this->m_OldDirection 			= a_OldDirection;
	this->m_NewDirection			= a_NewDirection;
	this->m_OldPosition				= a_OldPosition;
	this->m_NewPosition				= a_NewPosition;
}
