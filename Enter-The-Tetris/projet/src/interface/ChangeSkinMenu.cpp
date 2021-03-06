#include "interface/ChangeSkinMenu.hpp"

void ChangeSkinMenu::show(){
    RenderingInterface::show();
    _program2D._program.use();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
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
        case SDLK_d:
            arrowDown();
            break;
        case SDLK_q:
            arrowUp();
            break;
        case SDLK_ESCAPE:
            throw GoToPlayerMenu();
            break;
        case SDLK_SPACE:
            try{
                _player.buyskin(_listSkins.at(_currentButton));
                _player.selectedSkin() = _listSkins.at(_currentButton);
                throw GoToPlayerMenu();
            }catch(const Insufficient_funds &e){ std::cout << "Not enouth money, " << _listSkins.at(_currentButton).price() << "needed" << _player << std::endl; }
            break;
        default:
            break;
    }   
}

void ChangeSkinMenu::updateArrow(){
    _elements.back().setPosY(_selectableElements.at(_currentButton).posY());
    _elements.back().setPosX(_selectableElements.at(_currentButton).posX() - 0.15f);
}

void ChangeSkinMenu::updateScreen(){
    _elements.clear();
    _frontElements.clear();
    _selectableElements.clear();

    _elements.push_back(Element2D("background.png",   0.f, 0.f, 1.f, 1.f, _applicationPath));
    _elements.push_back(Element2D("frame.png", 0.f, 0.f, 1.3f, 1.3f, _applicationPath));
    _listSkins = Skin::loadSkins();
    std::string fontPath = _applicationPath.dirPath() + "assets/fonts/retro.ttf";
    float arrowX = -.45f;
    for (int i = 0; i < _listSkins.size(); ++i)
    {
        float x = .3f*i-.3f;
        _selectableElements.push_back(Element2D(_listSkins.at(i).previewPng(), x, 0.0f, 0.10f, 0.10f, _applicationPath));
        if(std::find(_player.unlockedSkins().begin(), _player.unlockedSkins().end(),_listSkins.at(i)) == _player.unlockedSkins().end()){
            _frontElements.push_back(Element2D("buy.png", x, 0.f, .1f, .1f, _applicationPath));
            _frontElements.push_back(Text("Buy", 255, 255, 255, fontPath.c_str(), 20, x, 0.f));
        }
        if(_listSkins.at(i) == _player.selectedSkin())
           arrowX = .3f*i-.3f-0.15f;
    }
    _elements.push_back(Element2D("arrow.png", arrowX, 0.f, 0.03f, 0.03f, _applicationPath));
}