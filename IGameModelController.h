#ifndef I_GAME_MODEL_CONTROLLER_H
#define I_GAME_MODEL_CONTROLLER_H

#include "SDL/SDL.h"

class IGameModelController
{

	public:

		virtual bool handleKeyEvent() = 0;
		virtual int nextPosition() = 0;

		virtual void freeSurfaces() = 0; 
		virtual void applySurfaces() = 0; 

		virtual void flipSurfaces() = 0; 

		virtual void chargeSurface() = 0;

		virtual void chargeSurfaceMissile() = 0;



		virtual ~IGameModelController() {}; 
};


#endif
