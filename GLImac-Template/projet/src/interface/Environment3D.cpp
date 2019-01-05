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
            manageKeyUpEvents(e.key.keysym.sym);
            break;
        case SDL_MOUSEMOTION:
            _ffcamera.motion(e.motion.xrel, e.motion.yrel);
            _tbcamera.motion(e.motion.xrel, e.motion.yrel);
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(e.button.button == SDL_BUTTON_WHEELUP)
                _tbcamera.zoomIn();
            else if(e.button.button == SDL_BUTTON_WHEELDOWN)
                _tbcamera.zoomOut();
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
            _camera = (_camera != &_ffcamera) ? (Camera*)&_ffcamera : (Camera*)&_tbcamera;
            break;
        case SDLK_l:
            _ffcamera.changeLock();
            _tbcamera.changeLock();
            break;
        default:
            break;
    }   
}