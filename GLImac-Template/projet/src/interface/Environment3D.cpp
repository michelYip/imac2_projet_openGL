#include "interface/Environment3D.hpp"

// deals with the events
void Environment3D::manageEvents(const SDL_Event &e){
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
void Environment3D::manageKeyUpEvents(const SDLKey &k){
    switch(k){
        case SDLK_DOWN:
            break;
        case SDLK_ESCAPE:
            throw QuitGame();
            break;
        case SDLK_SPACE:
            break;
        case SDLK_UP:
            break;
        default:
            break;
    }
}

// deals with key down events
void Environment3D::manageKeyDownEvents(const SDLKey &k){
    switch(k){
        case SDLK_c:
            _camera = (_camera != &_ffcamera) ? (Camera*)&_ffcamera : (Camera*)&_tccamera;
            break;
        default:
            break;
    }   
}