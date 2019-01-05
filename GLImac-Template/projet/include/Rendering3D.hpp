#ifndef _RENDERING3D_ 
#define _RENDERING3D_

#include "Camera.hpp"
#include "Rendering.hpp"
#include "Mesh.hpp"
#include "Light.hpp"
#include "World.hpp"
#include <glimac/Sphere.hpp>
#include "GPUProgram3D.hpp"

const float WINDOW_WIDTH = 1200;
const float WINDOW_HEIGHT = 800;


/// \class Rendering3D
/// \bried Rendering module that is able to create a 3D environment from the world informations
class Rendering3D : public Rendering
{
	protected:
		const Camera *_camera;
		World &_world;
	
	private:
		glm::mat4 _ProjMatrix;
		glm::mat4 _MVMatrix;
		glm::mat4 _NormalMatrix;
		GPUProgram3D _program3D;
		Light _light;

	public:
		Rendering3D() = default;

		Rendering3D(const glimac::FilePath &applicationPath, const Camera* camera, World &world);

		~Rendering3D() = default;

		// deals with the events
		virtual void manageEvents(const SDL_Event &e) = 0;
		// deals with key up events
		virtual void manageKeyUpEvents(const SDLKey &k) = 0;
		// deals with key down events
		virtual void manageKeyDownEvents(const SDLKey &k) = 0;		

		void show();
};

#endif