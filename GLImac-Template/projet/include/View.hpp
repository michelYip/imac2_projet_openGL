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
#include "Music.hpp"

#include "interface/throwableEvents/QuitGame.hpp"

using namespace glimac;


/// \class View
/// \brief View of the Game that control the window
class View
{
	private:
		bool _done;	///< reveals when the render is done
		unsigned int _screen; ///< reveals which screen we're in
		Rendering *_rendering; ///< the render to display
		SDLWindowManager _windowManager; ///< allows to display a window
		Music _audio; ///< music of the game

	public:
		//CONSTRUCTORS & DESTRUCTORS
		//Default constructor
		View()
		:_done(false),
		_screen(0),
		_windowManager(WINDOW_WIDTH, WINDOW_HEIGHT, "Enter The Tetris"),
		_rendering(NULL)
		{};

		//Default destructor
		~View(){
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
		/// \param: applicationPath : filePath of the game
		/// \param: param : world to display
		/// \brief creates the window for the render
		int createWindow(const glimac::FilePath &applicationPath, const World &world);
		/// \brief display window and render
		void displayWindow();
		/// \brief clears properly window
		void clearWindow();
		/// \brief manages the events of the window
		void waitEvents();
};

#endif