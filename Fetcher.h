/**
* @file Fetcher.h
* @brief 
* @author Laurence Morin-Daoust
* @version 1.0
* @date 2011-07-09
*/

#ifndef FETCHER_H
#define FETCHER_H

#include <vector>
#include <string>
#include <sstream>

#include "IFetcher.h"


/**
* @brief This class provides several utility function
*		 to help the engine. 
*/
class Fetcher : public IFetcher
{
    private:
			/**
			* @brief This is the constant for frames by second.
			*/
			int m_frameBySecond;


			/**
			* @brief This is the grid dimension.
			*/
   	 	int m_grid_dimension;

			std::string m_prefix;


    public:

			std::string GetPrefix();
			void SetPrefix(std::string prefix);

			/**
			* @brief This method returns the file name 
			* corresponding to the position.
			*
			* @param position Position in the grid. 
			*
			* @return File name corresponding to the position. 
			*/
			std::string GetFileNameLinkedToPosition(int position);


			std::string GetFileNameLinkedToPosition(int position, 
													std::string fetcher_directory);
		
			/**
			* @brief Default constructor.
			*/
			Fetcher();

			/**
			* @brief Constructor.
			*
			* @param m_frameBySecond Frame by second. 
			* @param m_grid_dimension Grid dimension.
			*/
			Fetcher(int m_frameBySecond, int m_grid_dimension, std::string prefix);

			/**
			* @brief Destructor.
			*/
			~Fetcher();
};


#endif
