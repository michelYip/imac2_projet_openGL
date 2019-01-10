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
	public:
		/// \param: applicationPath: Game applicationPath
		/// \param: player: Game _player param
		PlayerMenu(const glimac::FilePath &applicationPath, Player &player)
		:RenderingInterface(applicationPath), _player(player)
		{
			std::string fontPath = applicationPath.dirPath() + "assets/fonts/retro.ttf";
			_elements.push_back(Illustration("background.png",   0.f, 0.f, 1.f, 1.f, applicationPath));
            _elements.push_back(Illustration("frame.png", 0.f, 0.f, 1.3f, 1.3f, applicationPath));
            _selectableElements.push_back(Text("play", 255, 255, 255, fontPath.c_str(), 50, 0.f, 0.25f));
            _selectableElements.push_back(Text("change skin", 255, 255, 255, fontPath.c_str(), 50, 0.f, 0.125f));
            _selectableElements.push_back(Text("change player", 255, 255, 255, fontPath.c_str(), 50, 0.f, 0.f));
            _selectableElements.push_back(Text("quit", 255, 255, 255, fontPath.c_str(), 50, 0.f, -0.125f));
            _elements.push_back(Illustration("arrow.png", -0.4f, 0.25, 0.03f, 0.03f, applicationPath));
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
};

#endif