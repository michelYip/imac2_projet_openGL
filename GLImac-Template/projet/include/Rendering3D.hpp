#ifndef _RENDERING3D_ 
#define _RENDERING3D_

#include "Camera.hpp"
#include "Rendering.hpp"
#include "Mesh.hpp"
#include "World.hpp"
#include <glimac/Sphere.hpp>

const float WINDOW_WIDTH = 1600;
const float WINDOW_HEIGHT = 1200;


/// \class Rendering3D
/// \bried Rendering module that is able to create a 3D environment from the world informations
class Rendering3D : public Rendering
{
	private:
		glm::mat4 _ProjMatrix;
		glm::mat4 _MVMatrix;
		glm::mat4 _NormalMatrix;
		GPUProgram3D _program3D;
		const World &_world;

	public:
		Rendering3D() = default;

		Rendering3D(const glimac::FilePath &applicationPath, const unsigned int &screen, const World &world);

		~Rendering3D() = default;


		void show(const Camera &camera);
		void end(){} //A DELETE
};

#endif