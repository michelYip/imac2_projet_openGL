#ifndef _PLAYERMENU_ 
#define _PLAYERMENU_

#include "RenderingInterface.hpp"
#include "Player.hpp"
#include "interface/throwableEvents/QuitGame.hpp"
#include "interface/throwableEvents/GoToSaveMenu.hpp"
#include "interface/throwableEvents/GoTo3DEnvironment.hpp"
#include "interface/throwableEvents/GoToChangeSkinMenu.hpp"
#include "exceptions/Unreachable_file.hpp"


/// \class PlayerMenu
/// \brief Manage all the Player selection Menu of the game, it create all the needed elements and is able to modify the player    
/// \brief Like all others Interfaces folder class it has its own key event manager to control every elements       
class PlayerMenu : public RenderingInterface
{
	private:
		Player &_player; ///< _player parameter of the Game
		glimac::FilePath _applicationPath;
	public:
		/// \param: applicationPath: Game applicationPath
		/// \param: player: Game _player param
		PlayerMenu(const glimac::FilePath &applicationPath, Player &player)
		:RenderingInterface(applicationPath), _player(player), _applicationPath(applicationPath)
		{
			updateScreen();	
		}

		~PlayerMenu() = default;

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

	/// \brief update screen according to change in the game
	void updateScreen();
};

#endif