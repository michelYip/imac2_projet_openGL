#include "interface/CreatePlayerMenu.hpp"

// deals with the events
void CreatePlayerMenu::manageEvents(const SDL_Event &e){
    throw GoToPlayerMenu();
}

// deals with key up events
void CreatePlayerMenu::manageKeyUpEvents(const SDLKey &k){
}

// deals with key down events
void CreatePlayerMenu::manageKeyDownEvents(const SDLKey &k){
}