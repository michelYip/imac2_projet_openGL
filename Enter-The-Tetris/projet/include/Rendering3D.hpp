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
		Camera *_camera; ///< current camera of the 3D render
		World &_world; ///< world of the game
		GameInterface _interface; ///< interface showing informations during the game
	
	private:
		glm::mat4 _ProjMatrix; ///< Projection matrix that will be sent to shaders
		glm::mat4 _MVMatrix; ///< ModelView Matrix that will be sent to the shaders
		glm::mat4 _NormalMatrix; ///< Normal Matrix that will be sent to the shaders
		std::vector<GPUProgram3D> _programs; ///< GPUPrograms cointaining programs to use according to different shaders

	public:
		Rendering3D() = default;

		/// \param: applicationPath : filePath of the Game
		/// \param: camera : the camera of the 3D render
		/// \param: world : world to render
		Rendering3D(const glimac::FilePath &applicationPath, Camera* camera, World &world);

		~Rendering3D() = default;

		/// \brief deals with the events
		virtual void manageEvents(const SDL_Event &e) = 0;
		/// \brief deals with key up events
		virtual void manageKeyUpEvents(const SDLKey &k) = 0;
		/// \briefdeals with key down events
		virtual void manageKeyDownEvents(const SDLKey &k) = 0;	

		/// \brief displays what is in the render
		void show();
};

#endif