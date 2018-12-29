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
#include "GPUProgram2D.hpp"

using namespace glimac;

class View
{
	private:
		bool _done;			// end app loop
		bool _keyPressed;	// a key is pressed
		bool _locked;		// camera locked or not
		unsigned int _screen;
		glm::vec2 _lastPos;
		std::string _cameraType;
		std::vector<Rendering*> _renderingEngine;
		SDLWindowManager _windowManager;
		TrackballCamera _thirdPCamera;	// tb = third person
		FreeflyCamera _firstPCamera;

	public:
		//CONSTRUCTORS & DESTRUCTORS
		//Default constructor
		View()
		:_done(false),
		_keyPressed(false), 
		_locked(true),
		_screen(0), 
		_lastPos(glm::vec2(0, 0)), 
		_cameraType("first"), 
		_windowManager(WINDOW_WIDTH, WINDOW_HEIGHT, "SanGLimac")		
		{};

		//Default destructor
		~View(){};

		//GETTERS & SETTERS
		glm::vec2 getMousePosition();

		//PUBLIC METHODS

		int createWindow(const glimac::FilePath &applicationPath);
		void displayWindow();
		void clearWindow();

		void manageEvents(const SDL_Event &e);

		void manageKeyUpEvents(const SDLKey &k);
		void manageKeyDownEvents(const SDLKey &k);

		void firstPersonCameraMotion();
		void thirdPersonCameraMotion();
};

#endif