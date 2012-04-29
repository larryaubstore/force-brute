#include "Fetcher.h"


Fetcher::Fetcher()
{

}

Fetcher::Fetcher(int m_frameBySecond, int m_grid_dimension, std::string prefix)
{
    this->m_frameBySecond = m_frameBySecond;
    this->m_grid_dimension = m_grid_dimension;
	this->m_prefix = prefix;
}

Fetcher::~Fetcher()
{

}


/**
* @brief This method converts the position into the dimension of map. 
*
* @param position The raw position. 
*
* @return The position converted. 
*/
int Fetcher::GetRelativePositionInTheMap(int position)
{
	/****
		WRONG PROBLEM TO FIX
		********/

	int positionConverted = position;
	int grid_dimensionByDimension = m_grid_dimension * m_grid_dimension;
	if(position < 0)
	{
		positionConverted = position + grid_dimensionByDimension;
	}
	else if(position > grid_dimensionByDimension)
	{
		positionConverted = position - grid_dimensionByDimension;
	}
	return positionConverted;
}


std::string Fetcher::GetFileNameLinkedToPosition(int position)
{
	return(GetFileNameLinkedToPosition(position, m_prefix));
}

std::string Fetcher::GetFileNameLinkedToPosition(int position,
											std::string fetcher_directory)
{
    std::string result;
    std::string index;
    std::stringstream out;
    out.str("");
    out << position;

    if(position < 10)
    {
        index = "/000";
    }
    else if( position < 100)
    {
        index = "/00";
    }
    else if(position < 1000)
    {
        index = "/0";
    }
	else
	{
		index = "/";
	}

    std::string extension = ".jpg";
    //result = m_prefix + directoryConverted.str() + index + out.str() +  extension;

    result = fetcher_directory + index + out.str() +  extension;
    return result;
}


void Fetcher::SetPrefix(std::string prefix)
{
	this->m_prefix = prefix;
}

std::string Fetcher::GetPrefix()
{
	return(this->m_prefix);
}
