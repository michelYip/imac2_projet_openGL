#ifndef _CreatePlayerMenu_ 
#define _CreatePlayerMenu_

#include "RenderingInterface.hpp"
#include "Player.hpp"
#include "interface/throwableEvents/QuitGame.hpp"
#include "interface/throwableEvents/GoToPlayerMenu.hpp"
#include "exceptions/Unreachable_file.hpp"
#include <string>




/// \class CreatePlayerMenu
/// \brief Manage all the Player creation Menu of the game, can create a new saving file and load the player to the player given, it create all the needed elements and is able to modify the player    
/// \brief Like all others Interfaces folder class it has its own key event manager to control every elements       
class CreatePlayerMenu : public RenderingInterface
{
	private:
		Player &_player; ///< _player parameter of the Game
		int _playerNum; ///< _player parameter of the Game

		///\brief temp function that create the player until the menu is ready
		void createPlayer(){
			_player = Player();
			_player.savingFile() = "player_" + std::to_string(_playerNum);
			_player.name() = _player.savingFile();
			std::vector<Skin> listSkins = Skin::loadSkins();
			_player.buyskin(listSkins.at(0));
			_player.selectedSkin() = listSkins.at(0);
			_player.save();
		}
	public:
		/// \param: applicationPath: Game applicationPath
		/// \param: player: Game _player param
		/// \param: playerNum: unique player number (used for saving file)
		CreatePlayerMenu(const glimac::FilePath &applicationPath, Player &player, const int playerNum = 0)
		:RenderingInterface(applicationPath), _player(player), _playerNum(playerNum)
		{
			if( playerNum != 0)
				createPlayer();
		}
		~CreatePlayerMenu() = default;


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
	
	/// \brief setter to update playerNum
	int playerNum(const int num){
		_playerNum = num;
		createPlayer();
	}
};

#endif