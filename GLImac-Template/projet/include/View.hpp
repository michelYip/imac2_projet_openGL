#ifndef _VIEW_
#define _VIEW_

#include <glimac/SDLWindowManager.hpp>
#include <glimac/glm.hpp>
#include <glimac/FilePath.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>

#include "Camera.hpp"
#include "Mesh.hpp"
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
		std::vector<Rendering*> _renderingEngine;
		SDLWindowManager _windowManager;
		Camera _camera;

	public:
		//CONSTRUCTORS & DESTRUCTORS
		//Default constructor
		View()
		:_done(false),
		_keyPressed(false), 
		_locked(true),
		_screen(0),
		_windowManager(WINDOW_WIDTH, WINDOW_HEIGHT, "SanGLimac")		
		{};

		//Default destructor
		~View(){
			for(int i = 0; i < _renderingEngine.size(); i++){
 				_renderingEngine[i]->end();
				delete _renderingEngine.at(i);
			}
			_renderingEngine.clear();

			//Free static loaded Mesh
			Mesh::clearAllLoadedMesh();
		};

		//GETTERS & SETTERS
		glm::vec2 getMousePosition();
		inline bool done() const{
			return _done;
		}

		//PUBLIC METHODS

		int createWindow(const glimac::FilePath &applicationPath, const World &world);
		void displayWindow();
		void clearWindow();

		void waitEvents();
		void manageEvents(const SDL_Event &e);

		void manageKeyUpEvents(const SDLKey &k);
		void manageKeyDownEvents(const SDLKey &k);
};

#endif