#ifndef _STARTMENU_ 
#define _STARTMENU_

#include "RenderingInterface.hpp"
#include "interface/throwableEvents/QuitGame.hpp"
#include "interface/throwableEvents/GoToSaveMenu.hpp"





/// \class StartMenu
/// \brief Manage all the Start Menu of the game, it create all the needed elements    
/// \brief Like all others Interfaces folder class it has its own key event manager to control every elements
class StartMenu : public RenderingInterface
{
	public:
		/// \param: applicationPath: Game applicationPath
		StartMenu(const glimac::FilePath &applicationPath)
		:RenderingInterface(applicationPath)
		{
			_elements.push_back(ImageButton("background.png",   0.f, 0.f, 1.f, 1.f, applicationPath));
            _elements.push_back(ImageButton("frame.png", 0.f, 0.f, 1.3f, 1.3f, applicationPath));
            _elements.push_back(ImageButton("title.png", 0.05f, 0.f, 0.5f, 0.5f, applicationPath));
            _selectableElements.push_back(ImageButton("start.png", 0.f, -0.25f, 0.1f, 0.05f, applicationPath));
            _selectableElements.push_back(ImageButton("quit.png", 0.f, -0.35f, 0.07f, 0.05f, applicationPath));
            _elements.push_back(ImageButton("arrow.png", -0.15f, -0.25, 0.03f, 0.03f, applicationPath));   
		}

		~StartMenu() = default;

	/// \brief Manage the events
	/// \param e: SDL_Event that comme from the view's SDLWindowManager
	void manageEvents(const SDL_Event &e);
	
	/// \brief Manage the keyUp events
	/// \param k: [SDL_Event].key.keysym.sym
	void manageKeyUpEvents(const SDLKey &k);

	/// \brief Manage the keyDown events
	/// \param k: [SDL_Event].key.keysym.sym
	void manageKeyDownEvents(const SDLKey &k);
};

#endif