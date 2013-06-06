#include "SceneStack.h"



SceneStack::SceneStack()
{

}




SceneStack::~SceneStack()
{

}

std::vector<AnimationPtr> SceneStack::GetAnimationList() {
	return m_AnimationList;
}

/**
* @brief This method add an animation instance to the list.
*
* @param a_name 
* @param a_startFrame 
* @param a_endFrame
* @param a_permanent
* @param a_xPosition
* @param a_yPosition
* @param a_currentFrame
*/
void SceneStack::Push(std::string a_name, 	
					int a_startFrame,
					int a_endFrame,
					bool a_permanent,
					int a_xPosition,
					int a_yPosition,
					int a_currentFrame) {
	Animation* animation = new Animation(a_name, 
																			 a_startFrame, 
																			 a_endFrame, 
																			 a_permanent, 
																			 a_xPosition,
																			 a_yPosition,
																			 a_currentFrame);

	AnimationPtr ptr(animation);
	m_AnimationList.push_back(ptr);
}

