/**
* @file SceneStack.h
* @brief 
* @author Laurence Morin-Daoust
* @version 1.0
* @date 2013-06-06
*/

#ifndef SCENE_STACK_H
#define SCENE_STACK_H

#include <vector>
#include <string>
#include <sstream>

#include "ISceneStack.h"
#include "Animation.h"
#include "../TypeDefEngine.h"

class SceneStack : public ISceneStack
{
	private:
			
		std::vector<AnimationPtr> m_AnimationList;


	public:
		/**
		* @brief Default constructor.
		*/
		SceneStack();


		/**
		* @brief Destructor.
		*/
		~SceneStack();

		void Push(std::string a_name, 
											int a_startFrame,
											int a_endFrame,
											bool a_isPermanent,
											int a_xPos,
											int a_yPos, 
											int a_currentFrame);

	
	 std::vector<AnimationPtr> GetAnimationList();


};


#endif
