#ifndef _SAVEMENU_ 
#define _SAVEMENU_

#include "RenderingInterface.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "interface/throwableEvents/QuitGame.hpp"
#include "interface/throwableEvents/GoToCreatePlayerMenu.hpp"
#include "interface/throwableEvents/GoToPlayerMenu.hpp"
#include "interface/throwableEvents/GoToStartMenu.hpp"
#include "exceptions/Unreachable_file.hpp"

/// \class SaveMenu
/// \brief Manage all the Saving Menu of the game, it create all the needed elements and is able to modify the player    
/// \brief Like all others Interfaces folder class it has its own key event manager to control every elements
class SaveMenu : public RenderingInterface
{
	private:
		Player &_player; ///< _player parameter of the Game 
		World &_world; ///< _player parameter of the Game 
	public:
		/// \param: applicationPath: Game applicationPath
		/// \param: player: Game _player param
		SaveMenu(const glimac::FilePath &applicationPath, Player &player, World &world);

		~SaveMenu() = default;   		

		/// \brief Manage the events
		/// \param e: SDL_Event that comme from the view's SDLWindowManager
		void manageEvents(const SDL_Event &e);
		
		/// \brief Manage the keyUp events
		/// \param k: [SDL_Event].key.keysym.sym
		void manageKeyUpEvents(const SDLKey &k);

		/// \brief Manage the keyDown events
		/// \param k: [SDL_Event].key.keysym.sym
		void manageKeyDownEvents(const SDLKey &k);

		/// \brief Used to select the next selectableElement
		void arrowDown();
		
		/// \brief Used to select the previous selectableElement
		void arrowUp();

		/// \brief Used to update the Arrow position 
		void updateArrow();

		/// \brief setter to update player if it has change of object
		Player& player(){return _player;}
};

#endif