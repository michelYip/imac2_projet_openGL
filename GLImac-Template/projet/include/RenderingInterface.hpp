#ifndef _RENDERINGINTERFACE_ 
#define _RENDERINGINTERFACE_

#include <vector>

#include "Rendering.hpp"
#include "Vertex2DColor.hpp"
#include "Vertex2DUV.hpp"
#include "GPUProgram2D.hpp"

#include "Illustration.hpp"

const GLuint VERTEX_ATTR_POSITION = 0;
const GLuint VERTEX_ATTR_COLOR = 1;

const GLuint NB_SCREEN = 4;
const std::vector<unsigned int> NB_BUTTON = {2, 3, 4};

/// \class RenderingInterface
/// \brief Rendering module that is able to create a 2D environment to create an interface
class RenderingInterface : public Rendering
{
	protected:
		std::vector<Element2D> _elements; ///< 2D elements to display
		std::vector<Element2D> _selectableElements; ///< 2D elements that are selectable by the arrow and triggers actions
		unsigned int _currentButton = 0; ///< currentButton revealing what is the action to trigger if the button is selected 
		GPUProgram2D _program2D; ///< GPUProgram that will allow to display the 2D render
		GLuint _vbo; ///< id to Vertex Buffer Objects
		GLuint _vao; ///< id to Vertex Array Objects
		GLuint _ibo; ///< id to Index Buffer Objects
		bool isFinished = 0; ///< reveals if it is the end of the render
		void showElement(const Element2D &image); ///< displays a 2D element
	
	public:
		RenderingInterface(){}
		/// \param: applicationPath : filePath of the Game
		RenderingInterface(const glimac::FilePath &applicationPath);
		/// \param: renderingInterface : object to copy;
		RenderingInterface(const RenderingInterface &renderingInterface):Rendering(renderingInterface), _ibo(renderingInterface._ibo){
			_elements = renderingInterface._elements;
		}
		~RenderingInterface();



		/// \brief Manage the events
		/// \param e: SDL_Event that comme from the view's SDLWindowManager
		virtual void manageEvents(const SDL_Event &e) = 0;
		
		/// \brief Manage the keyUp events
		/// \param k: [SDL_Event].key.keysym.sym
		virtual void manageKeyUpEvents(const SDLKey &k) = 0;

		/// \brief Manage the keyDown events
		/// \param k: [SDL_Event].key.keysym.sym
		virtual void manageKeyDownEvents(const SDLKey &k) = 0;

		/// \brief show the object content on the window
		void show();

		/// \brief Used to select the next selectableElement
		virtual void arrowDown();
		
		/// \brief Used to select the previous selectableElement
		virtual void arrowUp();

		/// \brief Used to update the Arrow position 
		virtual void updateArrow();
};

#endif