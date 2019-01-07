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

#include "interface/throwableEvents/QuitGame.hpp"

using namespace glimac;


/// \class View
/// \brief View of the Game that control the window
class View
{
	private:
		bool _done;			// end app loop
		bool _keyPressed;	// a key is pressed
		unsigned int _screen;
		Rendering *_rendering;
		SDLWindowManager _windowManager;

	public:
		//CONSTRUCTORS & DESTRUCTORS
		//Default constructor
		View()
		:_done(false),
		_keyPressed(false),
		_screen(0),
		_windowManager(WINDOW_WIDTH, WINDOW_HEIGHT, "SanGLimac"),
		_rendering(NULL)
		{};

		//Default destructor
		~View(){
			delete(_rendering);
			//Free static loaded Mesh
			Mesh::clearAllLoadedMesh();
		};

		void set_rendering(Rendering* r){
			_rendering = r;
		}

		//GETTERS & SETTERS
		glm::vec2 getMousePosition();
		inline bool done() const{
			return _done;
		}

		//PUBLIC METHODS
		int createWindow(const glimac::FilePath &applicationPath, const World &world);
		void displayWindow();

		void waitEvents();
};

#endif