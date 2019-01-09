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
		std::vector<ImageButton> _frontElements;
		
	public:
		/// \param: applicationPath: Game applicationPath
		/// \param: player: Game _player param
		ChangeSkinMenu(const glimac::FilePath &applicationPath, Player &player)
		:RenderingInterface(applicationPath), _player(player)
		{
			_elements.push_back(ImageButton("background.png",   0.f, 0.f, 1.f, 1.f, applicationPath));
            _elements.push_back(ImageButton("frame.png", 0.f, 0.f, 1.3f, 1.3f, applicationPath));
			_listSkins = Skin::loadSkins();
			float arrowX = -.45f;
			for (int i = 0; i < _listSkins.size(); ++i)
			{
				float x = .3f*i-.3f;
            	_selectableElements.push_back(ImageButton(_listSkins.at(i).previewPng(), x, 0.0f, 0.10f, 0.10f, applicationPath));
				if(std::find(_player.unlockedSkins().begin(), _player.unlockedSkins().end(),_listSkins.at(i)) == _player.unlockedSkins().end())
            		_frontElements.push_back(ImageButton("buy.png", x, 0.f, .1f, .1f, applicationPath));
				if(_listSkins.at(i) == _player.selectedSkin())
         		   arrowX = .3f*i-.3f-0.15f;
			}
         	_elements.push_back(ImageButton("arrow.png", arrowX, 0.f, 0.03f, 0.03f, applicationPath));
            
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
	Player& player(){return _player;}
};

#endif