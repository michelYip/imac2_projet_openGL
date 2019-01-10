#ifndef _CHANGESKINMENU_ 
#define _CHANGESKINMENU_

#include "RenderingInterface.hpp"
#include "Player.hpp"
#include "Skin.hpp"
#include "interface/throwableEvents/QuitGame.hpp"
#include "interface/throwableEvents/GoToPlayerMenu.hpp"
#include "exceptions/Unreachable_file.hpp"

/// \class ChangeSkinMenu
/// \brief Manage all the Player creation Menu of the game, can create a new saving file and load the player to the player given, it create all the needed elements and is able to modify the player    
/// \brief Like all others Interfaces folder class it has its own key event manager to control every elements       
class ChangeSkinMenu : public RenderingInterface
{
	private:
		Player &_player; ///< _player parameter of the Game
		std::vector<Skin> _listSkins; ///< List of the playables skins
		std::vector<Element2D> _frontElements;
		const glimac::FilePath _applicationPath;
		
	public:
		/// \param: applicationPath: Game applicationPath
		/// \param: player: Game _player param
		ChangeSkinMenu(const glimac::FilePath &applicationPath, Player &player)
		:RenderingInterface(applicationPath), _player(player), _applicationPath(applicationPath)
		{
			updateScreen();
            
		}
		~ChangeSkinMenu() = default;

		/// \brief Manage the events
		/// \param e: SDL_Event that comme from the view's SDLWindowManager
		void manageEvents(const SDL_Event &e);
		
		/// \brief Manage the keyUp events
		/// \param k: [SDL_Event].key.keysym.sym
		void manageKeyUpEvents(const SDLKey &k);

		/// \brief Manage the keyDown events
		/// \param k: [SDL_Event].key.keysym.sym
		void manageKeyDownEvents(const SDLKey &k);

		/// \brief Used to update the Arrow position 
		void updateArrow();

		void show();

		/// \brief setter to update player if it has change of object
		void player(Player &p){_player = p;}
		
		/// \brief Set screen elements
		void updateScreen();
};

#endif