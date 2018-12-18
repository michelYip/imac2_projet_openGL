#ifndef _RENDERINGINTERFACE_ 
#define _RENDERINGINTERFACE_

#include <vector>

#include "Button.hpp"
#include "Rendering.hpp"
#include "Vertex2DColor.hpp"
#include "Vertex2DUV.hpp"

class RenderingInterface : public Rendering
{
	private:
		GLuint _ibo;
		std::vector<Button> _elements;
	public:
		RenderingInterface(){};
		RenderingInterface(const char &type);
		~RenderingInterface(){};

		void initialize();
		void show();
		void end();
};

#endif