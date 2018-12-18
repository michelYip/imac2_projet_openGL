#ifndef _VIEW_
#define _VIEW_

#include <glimac/SDLWindowManager.hpp>
#include <glimac/glm.hpp>
#include <glimac/FilePath.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>

#include "Rendering.hpp"
#include "Rendering3D.hpp"
#include "RenderingInterface.hpp"

const float WINDOW_WIDTH = 1600;
const float WINDOW_HEIGHT = 1200;

const GLuint VERTEX_ATTR_POSITION = 0;
const GLuint VERTEX_ATTR_COLOR = 1;

using namespace glimac;

class View
{
	private:
		bool _done;			// end app loop
		bool _keyPressed;	// a key is pressed
		bool _locked;		// camera locked or not
		std::string _cameraType;
		std::vector<Rendering> _renderingEngine;
		SDLWindowManager _windowManager;

	public:
		View():_done(false), _keyPressed(false), _locked(true), _cameraType("third"), _windowManager(SDLWindowManager(WINDOW_WIDTH, WINDOW_HEIGHT, "SanGLimac")){};
		~View(){};

		int window(const glimac::FilePath &applicationPath);
		void manageEvents(const SDL_Event &e);
		glm::vec2 getMousePosition();

		void manageKeyUpEvents(const SDLKey &k);
		void manageKeyDownEvents(const SDLKey &k);

		void firstPersonCameraMotion();
		void thirdPersonCameraMotion();
};

#endif 