#ifndef _SAVEMENU_ 
#define _SAVEMENU_

#include "RenderingInterface.hpp"
#include "Player.hpp"
#include "interface/throwableEvents/QuitGame.hpp"
#include "interface/throwableEvents/GoToCreatePlayerMenu.hpp"
#include "interface/throwableEvents/GoToPlayerMenu.hpp"
#include "exceptions/Unreachable_file.hpp"




/// \class SaveMenu
class SaveMenu : public RenderingInterface
{
	private:
		Player &_player; 
	public:
		SaveMenu(const glimac::FilePath &applicationPath, Player &player)
		:RenderingInterface(applicationPath), _player(player)
		{
			_elements.push_back(ImageButton("background.png",   0.f, 0.f, 1.f, 1.f, applicationPath));
            _elements.push_back(ImageButton("frame.png", 0.f, 0.f, 1.3f, 1.3f, applicationPath));
            _elements.push_back(ImageButton("saves-frames.png",   0.f, 0.f, 0.5f, 0.5f, applicationPath));
            _elements.push_back(ImageButton("arrow.png", -0.475f, 0.31, 0.03f, 0.03f, applicationPath));
   		}

	// deals with the events
	void manageEvents(const SDL_Event &e);
	// deals with key up events
	void manageKeyUpEvents(const SDLKey &k);
	// deals with key down events
	void manageKeyDownEvents(const SDLKey &k);

	void arrowDown();
	void arrowUp();
	void updateArrow();
};

#endif