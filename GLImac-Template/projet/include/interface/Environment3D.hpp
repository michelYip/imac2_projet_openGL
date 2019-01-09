#ifndef _ENVIRONMENT3D_ 
#define _ENVIRONMENT3D_

#include "Rendering3D.hpp"
#include "Player.hpp"
#include "FreeflyCamera.hpp"
#include "TrackballCamera.hpp"
#include "interface/throwableEvents/QuitGame.hpp"
#include "interface/throwableEvents/GoToPlayerMenu.hpp"
#include "exceptions/Unreachable_file.hpp"

/// \class PlayerMenu
class Environment3D : public Rendering3D
{
	private:
		Player &_player; 
		FreeflyCamera _ffcamera;
		TrackballCamera _tbcamera;
	public:
		Environment3D(const glimac::FilePath &applicationPath, World &world, Player &player)
		:Rendering3D(applicationPath,&_ffcamera,world), _player(player)
		{updateCharaterTexture();} 


		~Environment3D() = default;

		/// \brief Update character texture from player selected skin
		void updateCharaterTexture(){_world.character().texture() = _player.selectedSkin().texture();}
		
		/// \brief Manage the events
		/// \param e: SDL_Event that comme from the view's SDLWindowManager
		void manageEvents(const SDL_Event &e);
		
		/// \brief Manage the keyUp events
		/// \param k: [SDL_Event].key.keysym.sym
		void manageKeyUpEvents(const SDLKey &k);

		/// \brief Manage the keyDown events
		/// \param k: [SDL_Event].key.keysym.sym
		void manageKeyDownEvents(const SDLKey &k);

		/// \brief setter to update player if it has change of object
		Player& player(){return _player;}

};

#endif