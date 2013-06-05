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
