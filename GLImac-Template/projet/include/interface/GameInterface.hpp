#ifndef _GAMEINTERFACE_ 
#define _GAMEINTERFACE_

#include "RenderingInterface.hpp"

/// \class GameInterface
/// \brief Show infos of current game during the game    
class GameInterface : public RenderingInterface
{
	public:
		GameInterface(){}
		/// \param: applicationPath: Game applicationPath
		GameInterface(const glimac::FilePath &applicationPath)
		:RenderingInterface(applicationPath)
		{
			std::string fontPath = "main/assets/fonts/retro.ttf";
            // _elements.push_back(Illustration("title.png", 0.05f, 0.f, 0.5f, 0.5f, applicationPath));
            _selectableElements.push_back(Text("start", 255, 255, 255, fontPath.c_str(), 50, 0.f, -0.25f));
            // _selectableElements.push_back(Text("quit", 255, 255, 255, fontPath.c_str(), 50, 0.f, -0.35f));
            // _elements.push_back(Illustration("arrow.png", -0.20f, -0.25, 0.03f, 0.03f, applicationPath));   
		}

		~GameInterface() = default;

	void manageEvents(const SDL_Event &e){}
	void manageKeyUpEvents(const SDLKey &k){}
	void manageKeyDownEvents(const SDLKey &k){}
};

#endif