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
		Rendering renderingEngine;
	public:
		View(){};
		~View(){};

		int createWindow() const;
};

#endif 