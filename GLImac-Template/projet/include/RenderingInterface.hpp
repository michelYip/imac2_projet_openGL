#ifndef _RENDERINGINTERFACE_ 
#define _RENDERINGINTERFACE_

#include <vector>

#include "Rendering.hpp"
#include "Vertex2DColor.hpp"
#include "Vertex2DUV.hpp"
#include "GPUProgram2D.hpp"

const GLuint VERTEX_ATTR_POSITION = 0;
const GLuint VERTEX_ATTR_COLOR = 1;

const GLuint NB_SCREEN = 4;
const std::vector<unsigned int> NB_BUTTON = {2, 3, 4};

/// \class RenderingInterface
/// \bried Rendering module that is able to create a 2D environment to create an interface
class RenderingInterface : public Rendering
{
	protected:
		std::vector<ImageButton> _elements;
		std::vector<ImageButton> _selectableElements;
		unsigned int _currentButton = 0;
	private:
		GLuint _vbo;
		GLuint _vao;
		GLuint _ibo;
		GPUProgram2D _program2D;
		bool isFinished = 0;
		
		void showElement(const ImageButton &image);
	public:
		RenderingInterface(){}
		RenderingInterface(const glimac::FilePath &applicationPath);
		RenderingInterface(const RenderingInterface &renderingInterface):Rendering(renderingInterface), _ibo(renderingInterface._ibo){
			_elements = renderingInterface._elements;
		}
		~RenderingInterface();


		// deals with the events
		virtual void manageEvents(const SDL_Event &e) = 0;
		// deals with key up events
		virtual void manageKeyUpEvents(const SDLKey &k) = 0;
		// deals with key down events
		virtual void manageKeyDownEvents(const SDLKey &k) = 0;		



		void show();

		virtual void arrowDown();
		virtual void arrowUp();
		virtual void updateArrow();
};

#endif