#ifndef _RENDERING3D_ 
#define _RENDERING3D_

#include "Rendering.hpp"
#include <glimac/Sphere.hpp>

const GLuint POS_ATTRIB_IND = 0;
const GLuint NORM_ATTRIB_IND = 1;
const GLuint TEXT_ATTRIB_IND = 2;

const float WINDOW_WIDTH = 1600;
const float WINDOW_HEIGHT = 1200;

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
		Rendering3D(const Rendering3D &rendering3D):Rendering(rendering3D), _ProjMatrix(rendering3D._ProjMatrix), _MVMatrix(rendering3D._MVMatrix), _NormalMatrix(rendering3D._NormalMatrix), _texture(rendering3D._texture), _sphere(rendering3D._sphere){};
		~Rendering3D(){};

		void show(const GPUProgram2D &program2D, const GPUProgram3D &program3D);
		void end();
};

#endif