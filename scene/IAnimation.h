#ifndef I_ANIMATION_H
#define I_ANIMATION_H

#include <string>
#include <vector>


using namespace std;

class IAnimation
{
	public:

		virtual std::string GetName() = 0;

		virtual int GetStartFrame() = 0;

		virtual int GetEndFrame() = 0;

		virtual bool IsPermanent() = 0;

		virtual int GetXPosition() = 0;

		virtual int GetYPosition() = 0;

		virtual int GetCurrentFrame() = 0;

		virtual ~IAnimation() {};

};


#endif
