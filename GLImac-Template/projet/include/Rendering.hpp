#ifndef _RENDERING_ 
#define _RENDERING_

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>
#include "ImageButton.hpp"

/// \class Rendering
/// \bried Rendering module of the View
class Rendering
{
	public:
		//CONSTRUCTORS & DESTRUCTORS
		//Default constructor
		Rendering(){};

		//Parameter constructor
		Rendering(const glimac::FilePath &applicationPath, const unsigned int &screen);
		
		//Reference constructor
		Rendering(const Rendering &rendering){}

		//Default destructor
		~Rendering(){}

		//
		virtual void show() = 0;

		// deals with the events
		virtual void manageEvents(const SDL_Event &e) = 0;
		// deals with key up events
		virtual void manageKeyUpEvents(const SDLKey &k) = 0;
		// deals with key down events
		virtual void manageKeyDownEvents(const SDLKey &k) = 0;
};

#endif