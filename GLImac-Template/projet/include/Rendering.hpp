#ifndef _RENDERING_ 
#define _RENDERING_

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>
#include "ImageButton.hpp"

/// \class Rendering
/// \brief Rendering module of the View
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

	
		/// \brief Manage the events
		/// \param e: SDL_Event that comme from the view's SDLWindowManager
		void manageEvents(const SDL_Event &e) = 0;
		
		/// \brief Manage the keyUp events
		/// \param k: [SDL_Event].key.keysym.sym
		void manageKeyUpEvents(const SDLKey &k) = 0;

		/// \brief Manage the keyDown events
		/// \param k: [SDL_Event].key.keysym.sym
		void manageKeyDownEvents(const SDLKey &k) = 0;
};

#endif