/**
* @file Animation.h
* @brief 
* @author Laurence Morin-Daoust
* @version 1.0
* @date 2013-06-06
*/

#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <string>
#include <sstream>

#include "../EDirection.h"
#include "IAnimation.h"


class Animation : public IAnimation
{
	private:
			
		std::string m_name;

		int m_startFrame;

		int m_endFrame;

		bool m_permanent;

		int m_xPosition;

		int m_yPosition;

		int m_currentFrame;



	public:
		/**
		* @brief Default constructor.
		*/
		Animation();


    Animation(std::string a_name, 	
							int a_startFrame,
							int a_endFrame,
							bool a_permanent,
							int a_xPosition,
							int a_yPosition,
							int a_currentFrame);

		/**
		* @brief Destructor.
		*/
		~Animation();

		
		/**
		* @brief Get the name of the animation. Must be unique.
		*
		* @return Name of the animation.
		*/
		std::string GetName();

		int GetStartFrame();

		int GetEndFrame();

		bool IsPermanent();

		int GetXPosition();

		int GetYPosition();

		int GetCurrentFrame();

};


#endif
