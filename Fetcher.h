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
		/**
		* @brief This method returns the exact position after conversion.
		* For example, the position looks like this for 4x4 square grid.
		* | 01 | 05 | 09 | 13 |
		* | 02 | 06 | 10 | 14 |
		* | 03 | 07 | 11 | 15 |
		* | 04 | 08 | 12 | 16 |
	    * 
		* Let's say we  navigate through the grid and we go further
		* than 14. Logically, we should be at 18, but actually we go 
		* back to 02. This method takes 18 as input and returns 02.
		*
		* @param position The position before the conversion.
		*
		* @return The position after the conversion.
		*/
		int GetRelativePositionInTheMap(int position);

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
