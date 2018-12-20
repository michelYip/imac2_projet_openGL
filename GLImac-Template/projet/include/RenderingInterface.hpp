#ifndef _RENDERINGINTERFACE_ 
#define _RENDERINGINTERFACE_

#include <vector>

#include "Rendering.hpp"
#include "Vertex2DColor.hpp"
#include "Vertex2DUV.hpp"

const GLuint VERTEX_ATTR_POSITION = 0;
const GLuint VERTEX_ATTR_COLOR = 1;

const GLuint NB_SCREEN = 4;

class RenderingInterface : public Rendering
{
	private:
		GLuint _ibo;
		std::vector<Button> _elements;
		GPUProgram2D _program2D;
	public:
		RenderingInterface(){};
		RenderingInterface(const glimac::FilePath &applicationPath, const unsigned int &screen);
		RenderingInterface(const RenderingInterface &renderingInterface):Rendering(renderingInterface), _ibo(renderingInterface._ibo){
			_elements = renderingInterface._elements;
		};
		~RenderingInterface(){};

		inline std::vector<Button> elements() const{
			return _elements;
		};

		void show(const GPUProgram2D &program2D, const GPUProgram3D &program3D);
		void end();
};

#endif