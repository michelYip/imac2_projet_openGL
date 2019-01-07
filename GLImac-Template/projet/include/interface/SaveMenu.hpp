#ifndef _SAVEMENU_ 
#define _SAVEMENU_

#include "RenderingInterface.hpp"
#include "Player.hpp"
#include "interface/throwableEvents/QuitGame.hpp"
#include "interface/throwableEvents/GoToCreatePlayerMenu.hpp"
#include "interface/throwableEvents/GoToPlayerMenu.hpp"
#include "exceptions/Unreachable_file.hpp"




/// \class SaveMenu
/// \brief Manage all the Saving Menu of the game, it create all the needed elements and is able to modify the player    
/// \brief Like all others Interfaces folder class it has its own key event manager to control every elements
class SaveMenu : public RenderingInterface
{
	private:
		Player &_player; 
	public:
		/// \param: applicationPath: Game applicationPath
		/// \param: player: Game _player param
		SaveMenu(const glimac::FilePath &applicationPath, Player &player)
		:RenderingInterface(applicationPath), _player(player)
		{
			_elements.push_back(ImageButton("background.png",   0.f, 0.f, 1.f, 1.f, applicationPath));
            _elements.push_back(ImageButton("frame.png", 0.f, 0.f, 1.3f, 1.3f, applicationPath));
            _elements.push_back(ImageButton("saves-frames.png",   0.f, 0.f, 0.5f, 0.5f, applicationPath));
            _elements.push_back(ImageButton("arrow.png", -0.475f, 0.31, 0.03f, 0.03f, applicationPath));
   		}


	/// \brief Manage the events
	/// \param e: SDL_Event that comme from the view's SDLWindowManager
	void manageEvents(const SDL_Event &e);
	
	/// \brief Manage the keyUp events
	/// \param k: [SDL_Event].key.keysym.sym
	void manageKeyUpEvents(const SDLKey &k);

	/// \brief Manage the keyDown events
	/// \param k: [SDL_Event].key.keysym.sym
	void manageKeyDownEvents(const SDLKey &k);

	void arrowDown();
	void arrowUp();
	void updateArrow();
};

#endif