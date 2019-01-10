#include "interface/PlayerMenu.hpp"

void PlayerMenu::manageEvents(const SDL_Event &e){
    switch(e.type){
        case SDL_QUIT:
            throw QuitGame();
            break;
        case SDL_KEYDOWN:
            manageKeyDownEvents(e.key.keysym.sym);
            break;
        case SDL_KEYUP:
            this->manageKeyUpEvents(e.key.keysym.sym);
            break;
        default: 
            break;
    }
}

void PlayerMenu::manageKeyUpEvents(const SDLKey &k){
    switch(k){
            break;
        default:
            break;
    }
}

void PlayerMenu::manageKeyDownEvents(const SDLKey &k){
    switch(k){
        case SDLK_z:
            arrowUp();
            break;
        case SDLK_s:
            arrowDown();
            break;
        case SDLK_ESCAPE:
            throw GoToSaveMenu();
            break;
        case SDLK_SPACE:
            if(_currentButton == 0) throw GoTo3DEnvironment();
            if(_currentButton == 1) throw GoToChangeSkinMenu();
            if(_currentButton == 2){
                _player.save();
                throw GoToSaveMenu();
            } 
            throw QuitGame();
            break;
        default:
            break;
    }   
}

void PlayerMenu::updateScreen(){
    _elements.clear();
    _selectableElements.clear();

    std::string fontPath = _applicationPath.dirPath() + "assets/fonts/retro.ttf";
            _elements.push_back(Illustration("background.png",   0.f, 0.f, 1.f, 1.f, _applicationPath));
            _elements.push_back(Illustration("frame.png", 0.f, 0.f, 1.3f, 1.3f, _applicationPath));
            _elements.push_back(Text((_player.name() + " : " + std::to_string(_player.money())).c_str(), 255, 255, 255, fontPath.c_str(), 60, 0.f, 0.40f));
            _selectableElements.push_back(Text("play", 255, 255, 255, fontPath.c_str(), 50, 0.f, 0.15f));
            _selectableElements.push_back(Text("change skin", 255, 255, 255, fontPath.c_str(), 50, 0.f, 0.025f));
            _selectableElements.push_back(Text("change player", 255, 255, 255, fontPath.c_str(), 50, 0.f, -0.1f));
            _selectableElements.push_back(Text("quit", 255, 255, 255, fontPath.c_str(), 50, 0.f, -0.225f));
            _elements.push_back(Illustration("arrow.png", -0.4f, 0.15, 0.03f, 0.03f, _applicationPath));
}