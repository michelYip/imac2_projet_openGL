#include "interface/PlayerMenu.hpp"

// deals with the events
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

// deals with key up events
void PlayerMenu::manageKeyUpEvents(const SDLKey &k){
    switch(k){
            break;
        default:
            break;
    }
}

// deals with key down events
void PlayerMenu::manageKeyDownEvents(const SDLKey &k){
    switch(k){
        case SDLK_UP:
            arrowUp();
            break;
        case SDLK_DOWN:
            arrowDown();
            break;
        case SDLK_ESCAPE:
            throw QuitGame();
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