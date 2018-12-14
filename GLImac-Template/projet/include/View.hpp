#ifndef _VIEW_
#define _VIEW_

#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>

#include "Rendering.hpp"

using namespace glimac;

class View
{
	private:
		bool _done;
		bool _keyPressed;
		bool _locked;
		Rendering renderingEngine;
	public:
		View():_done(false), _keyPressed(false), _locked(true){};
		~View(){};

		int createWindow();
		void manageEvents(const SDL_Event &e);

		void manageKeyUpEvents(const SDLKey &k);
		void manageKeyDownEvents(const SDLKey &k);

		void cameraRotation();
};

#endif 