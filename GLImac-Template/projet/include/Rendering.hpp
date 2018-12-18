#ifndef _RENDERING_ 
#define _RENDERING_

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glimac/Program.hpp>

class Rendering
{
	public:
		GLuint _vbo;
		GLuint _vao;

		Rendering(){};
		Rendering(const char &type){};
		~Rendering(){};

		virtual void initialize(){};
		virtual void show(){};
		virtual void end(){};
};

#endif