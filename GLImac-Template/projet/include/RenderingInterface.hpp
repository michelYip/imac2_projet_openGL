#ifndef _RENDERINGINTERFACE_ 
#define _RENDERINGINTERFACE_

#include <vector>

#include "Rendering.hpp"
#include "Vertex2DColor.hpp"
#include "Vertex2DUV.hpp"

const GLuint VERTEX_ATTR_POSITION = 0;
const GLuint VERTEX_ATTR_COLOR = 1;

const GLuint NB_SCREEN = 4;
const std::vector<unsigned int> NB_BUTTON = {2, 3, 4};

class RenderingInterface : public Rendering
{
	private:
		GLuint _ibo;
		std::vector<Button> _elements;
		std::vector<Button> _buttons;
		GPUProgram2D _program2D;
		unsigned int _currentButton = 1;
	public:
		RenderingInterface(){};
		RenderingInterface(const glimac::FilePath &applicationPath, const unsigned int &screen);
		RenderingInterface(const RenderingInterface &renderingInterface):Rendering(renderingInterface), _ibo(renderingInterface._ibo){
			_elements = renderingInterface._elements;
		};
		~RenderingInterface(){};

		inline std::vector<Button> elements() const{
			return _elements;
		}
		inline unsigned int currentButton() const{
			return _currentButton;
		}

		void show(const GPUProgram2D &program2D, const GPUProgram3D &program3D, const TrackballCamera &tbCamera, const FreeflyCamera &ffCamera, const std::string &cameraType);
		void end();

		void arrowDown(const unsigned int &screen);
		void arrowUp(const unsigned int &screen);
		bool actionButton(unsigned int &screen) const;
};

#endif