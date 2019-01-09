#include "interface/StartMenu.hpp"

// deals with the events
void StartMenu::manageEvents(const SDL_Event &e){
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
void StartMenu::manageKeyUpEvents(const SDLKey &k){
    switch(k){
        default:
            break;
    }
}

// deals with key down events
void StartMenu::manageKeyDownEvents(const SDLKey &k){
    switch(k){
        case SDLK_DOWN:
            arrowDown();
            break;
        case SDLK_ESCAPE:
            throw QuitGame();
            break;
        case SDLK_SPACE:
            if(_currentButton == 0) throw GoToSaveMenu();
            throw QuitGame();
            break;
        case SDLK_UP:
            arrowUp();
            break;
        default:
            break;
    }   
}