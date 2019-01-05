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




/// \class PlayerMenu
class Environment3D : public Rendering3D
{
	private:
		Player &_player; 
		FreeflyCamera _ffcamera;
		TrackballCamera _tccamera;
	public:
		Environment3D(const glimac::FilePath &applicationPath, World &world, Player &player)
		:Rendering3D(applicationPath,&_ffcamera,world), _player(player)
		{}

	// deals with the events
	void manageEvents(const SDL_Event &e);
	// deals with key up events
	void manageKeyUpEvents(const SDLKey &k);
	// deals with key down events
	void manageKeyDownEvents(const SDLKey &k);
};

#endif