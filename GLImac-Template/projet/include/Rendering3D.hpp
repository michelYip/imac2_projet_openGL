#ifndef _RENDERING3D_ 
#define _RENDERING3D_

#include "Rendering.hpp"
#include <glimac/Sphere.hpp>

const GLuint POS_ATTRIB_IND = 0;
const GLuint NORM_ATTRIB_IND = 1;
const GLuint TEXT_ATTRIB_IND = 2;

const float WINDOW_WIDTH = 1280;
const float WINDOW_HEIGHT = 720;

class Rendering3D : public Rendering
{
	private:
		glm::mat4 _ProjMatrix;
		glm::mat4 _MVMatrix;
		glm::mat4 _NormalMatrix;
		GLuint _texture;
		glimac::Sphere _sphere;
		GPUProgram3D _program3D;
	public:
		Rendering3D(){}

		Rendering3D(const glimac::FilePath &applicationPath, const unsigned int &screen);

		~Rendering3D(){	
		    glDeleteBuffers(1, &_vbo);
		    glDeleteVertexArrays(1, &_vao);
		    glDeleteTextures(1, &_texture);
		};

		void show(const TrackballCamera &tbCamera, const FreeflyCamera &ffCamera, const std::string &cameraType);
		void end();
};

#endif