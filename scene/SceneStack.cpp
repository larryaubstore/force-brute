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

void SceneStack::NextPosition() {

	AnimationPtr ptr;
	for(int i = 0; i < m_AnimationList.size(); i++) {
		ptr = m_AnimationList[i];
	}	
}

void SceneStack::GetAnimationForRendering() {

	m_AnimationListForRendering.clear();

//	std::vector<AnimationPtr>::iterator begin = m_AnimationListForRendering.begin();
//	std::vector<AnimationPtr>::iterator end = m_AnimationListForRendering.end();

	std::vector<AnimationPtr>::iterator begin; 
	std::vector<AnimationPtr>::iterator end;
		
	AnimationPtr ptr;
	for(int i = 0; i < m_AnimationList.size(); i++) {
		ptr = m_AnimationList[i];


		//IAnimation* test = ptr.get();

		begin = m_AnimationListForRendering.begin();
		end = m_AnimationListForRendering.end();

		//Animation test = *ptr;

		if(std::find(begin, end, ptr) == end) {
			//m_AnimationListForRendering.push_back(ptr);
		//}
		
	}	

	


//	if(std::find(v.begin(), v.end(), x) != v.end()) {
//			/* v contains x */
//	} else {
//			/* v does not contain x */
//	}



}


