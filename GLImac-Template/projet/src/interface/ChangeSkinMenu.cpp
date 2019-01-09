#include "interface/ChangeSkinMenu.hpp"

void ChangeSkinMenu::show(){
    RenderingInterface::show();
    
    _program2D._program.use();
    glBindVertexArray(this->_vao);
    for(int i = 0; i < _frontElements.size(); i++)
        showElement(_frontElements.at(i));    
    glBindVertexArray(0);
}
// deals with the events
void ChangeSkinMenu::manageEvents(const SDL_Event &e){
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
void ChangeSkinMenu::manageKeyUpEvents(const SDLKey &k){
    switch(k){
        default:
            break;
    }
}

// deals with key down events
void ChangeSkinMenu::manageKeyDownEvents(const SDLKey &k){
    switch(k){
        case SDLK_RIGHT:
            arrowDown();
            break;
        case SDLK_LEFT:
            arrowUp();
            break;
        case SDLK_ESCAPE:
            throw QuitGame();
            break;
        case SDLK_SPACE:
            _player.buyskin(_listSkins.at(_currentButton));
            _player.selectedSkin() = _listSkins.at(_currentButton);
            throw GoToPlayerMenu();
            break;
        default:
            break;
    }   
}


void ChangeSkinMenu::updateArrow(){
    _elements.back().setPosY(_selectableElements.at(_currentButton).posY());
    _elements.back().setPosX(_selectableElements.at(_currentButton).posX() - 0.15f);
}