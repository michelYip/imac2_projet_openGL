#ifndef _RENDERING3D_ 
#define _RENDERING3D_

#include "Camera.hpp"
#include "Rendering.hpp"
#include "interface/GameInterface.hpp"
#include "Mesh.hpp"
#include "World.hpp"
#include "GPUProgram3D.hpp"

const float WINDOW_WIDTH = 1600;
const float WINDOW_HEIGHT = 1200;


/// \class Rendering3D
/// \bried Rendering module that is able to create a 3D environment from the world informations
class Rendering3D : public Rendering
{
	protected:
		Camera *_camera;
		World &_world;
		GameInterface _interface;
	
	private:
		glm::mat4 _ProjMatrix;
		glm::mat4 _MVMatrix;
		glm::mat4 _NormalMatrix;
		std::vector<GPUProgram3D> _programs;

	public:
		Rendering3D() = default;

		Rendering3D(const glimac::FilePath &applicationPath, Camera* camera, World &world);

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