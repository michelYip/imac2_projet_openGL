#ifndef _ENVIRONMENT3D_ 
#define _ENVIRONMENT3D_

#include "Rendering3D.hpp"
#include "Player.hpp"
#include "FreeflyCamera.hpp"
#include "TrackballCamera.hpp"
#include "interface/throwableEvents/QuitGame.hpp"
#include "interface/throwableEvents/GoToSaveMenu.hpp"
#include "interface/throwableEvents/GoTo3DEnvironment.hpp"
#include "interface/throwableEvents/GoToChangeSkinMenu.hpp"
#include "exceptions/Unreachable_file.hpp"

/// \class Environment3D
/// \brief Manage all the 3D Environnement of the game, it create cameras and is able to modify the player and the world    
/// \brief Like all others Interfaces folder class it has its own key event manager to control every elements       
class Environment3D : public Rendering3D
{
	private:
		Player &_player; ///< _player parameter of the Game
		FreeflyCamera _ffcamera; ///< Third person camera
		TrackballCamera _tbcamera; ///< First person camera
	public:
		/// \param: applicationPath: Game applicationPath
		/// \param: world: Game _world param
		/// \param: player: Game _player param
		Environment3D(const glimac::FilePath &applicationPath, World &world, Player &player)
		:Rendering3D(applicationPath,&_ffcamera,world), _player(player)
		{}


	/// \brief Manage the events
	/// \param e: SDL_Event that comme from the view's SDLWindowManager
	void manageEvents(const SDL_Event &e);
	
	/// \brief Manage the keyUp events
	/// \param k: [SDL_Event].key.keysym.sym
	void manageKeyUpEvents(const SDLKey &k);

	/// \brief Manage the keyDown events
	/// \param k: [SDL_Event].key.keysym.sym
	void manageKeyDownEvents(const SDLKey &k);
};

#endif