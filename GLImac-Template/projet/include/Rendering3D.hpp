#ifndef _RENDERING3D_ 
#define _RENDERING3D_

#include "Rendering.hpp"
#include <glimac/Sphere.hpp>

const GLuint POS_ATTRIB_IND = 0;
const GLuint NORM_ATTRIB_IND = 1;
const GLuint TEXT_ATTRIB_IND = 2;

class Rendering3D : public Rendering
{
	private:
		glm::mat4 _ProjMatrix;
		glm::mat4 _MVMatrix;
		glm::mat4 _NormalMatrix;
		GLuint _texture;
		glimac::Sphere _sphere;
	public:
		Rendering3D(){};
		Rendering3D(const glimac::FilePath &appllicationPath, const unsigned int &screen);
		~Rendering3D(){};

		void show(const GPUProgram2D &program2D);
};

#endif