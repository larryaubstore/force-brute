#ifndef I_SCENE_STACK_H
#define I_SCENE_STACK_H

#include <string>
#include <vector>


using namespace std;

class ISceneStack
{
	public:

		virtual void Push(std::string a_name, 
											int a_startFrame,
											int a_endFrame,
											bool a_isPermanent,
											int a_xPos,
											int a_yPos, 
											int a_currentFrame) = 0;

		virtual ~ISceneStack() {};

};


#endif
