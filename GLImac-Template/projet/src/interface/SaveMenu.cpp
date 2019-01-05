#include "interface/SaveMenu.hpp"

// deals with the events
void SaveMenu::manageEvents(const SDL_Event &e){
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

// deals with key up events
void SaveMenu::manageKeyUpEvents(const SDLKey &k){
    switch(k){
        case SDLK_DOWN:
            arrowDown();
            break;
        case SDLK_ESCAPE:
            throw QuitGame();
            break;
        case SDLK_SPACE:
            try{ 
                _player = Player::load(std::string("player_")+std::to_string(_currentButton+1));
                throw GoToPlayerMenu();
            }
            catch(const Unreachable_file &e){ throw GoToCreatePlayerMenu();}
            break;
        case SDLK_UP:
            arrowUp();
            break;
        default:
            break;
    }
}

// deals with key down events
void SaveMenu::manageKeyDownEvents(const SDLKey &k){
    switch(k){
        default:
            break;
    }   
}

void SaveMenu::arrowDown(){
    if(_currentButton != 2){
        _currentButton++;
        updateArrow();
    }
}

void SaveMenu::arrowUp(){
    if(_currentButton != 0){
        _currentButton--;
        updateArrow();
    }
}

void SaveMenu::updateArrow(){
    _elements.back().setPosY((2-_currentButton)*0.30f-0.30f);
}
