#ifndef _RENDERING_ 
#define _RENDERING_

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glimac/Image.hpp>

#include "Button.hpp"
#include "GPUProgram2D.hpp"
#include "GPUProgram3D.hpp"

#include "TrackballCamera.hpp"
#include "FreeflyCamera.hpp"

class Rendering
{
	protected:
		GLuint _vbo;
		GLuint _vao;

	public:
		//CONSTRUCTORS & DESTRUCTORS
		//Default constructor
		Rendering(){};

		//Parameter constructor
		Rendering(const glimac::FilePath &applicationPath, const unsigned int &screen);
		
		//Reference constructor
		Rendering(const Rendering &rendering)
		:_vbo(rendering._vbo), 
		_vao(rendering._vao)
		{};

		//Default destructor
		~Rendering(){
		    glDeleteBuffers(1, &_vbo);
		    glDeleteVertexArrays(1, &_vao);
		};

		//
		virtual inline std::vector<Button> elements() const{};
		virtual inline unsigned int currentButton() const{};

		virtual void show(){ std::cout << "Rendering" << std::endl; }
		virtual void show(const TrackballCamera &tbCamera, const FreeflyCamera &ffCamera, const std::string &cameraType){}
		
		virtual void end(){}

		virtual void arrowDown(const unsigned int &screen){}
		virtual void arrowUp(const unsigned int &screen){}
		virtual bool actionButton(unsigned int &screen) const{}
};

#endif