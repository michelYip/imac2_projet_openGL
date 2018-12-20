#ifndef _RENDERING_ 
#define _RENDERING_

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glimac/Image.hpp>

#include "Button.hpp"
#include "GPUProgram2D.hpp"
#include "GPUProgram3D.hpp"

class Rendering
{
	public:
		GLuint _vbo;
		GLuint _vao;

		Rendering(){};
		Rendering(const glimac::FilePath &applicationPath, const unsigned int &screen);
		Rendering(const Rendering &rendering):_vbo(rendering._vbo), _vao(rendering._vao){
		};
		~Rendering(){
		    glDeleteBuffers(1, &_vbo);
		    glDeleteVertexArrays(1, &_vao);
		};

		virtual inline std::vector<Button> elements() const{};

		virtual void show(const GPUProgram2D &program2D, const GPUProgram3D &program3D){};
		virtual void end(){};
};

#endif