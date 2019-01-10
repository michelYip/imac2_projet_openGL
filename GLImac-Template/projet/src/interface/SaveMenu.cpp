#include "interface/SaveMenu.hpp"

SaveMenu::SaveMenu(const glimac::FilePath &applicationPath, Player &player, World &world)
:RenderingInterface(applicationPath), _player(player), _world(world)
{
    Player p1, p2, p3;  
    Player *pp1, *pp2, *pp3;  
    //Load player to print which ones are already created
    try{ p1 = Player::load("player_1"); pp1 = &p1; }catch(const Unreachable_file &e){ pp1 = NULL; }
    try{ p2 = Player::load("player_2"); pp2 = &p2; }catch(const Unreachable_file &e){ pp2 = NULL; }
    try{ p3 = Player::load("player_3"); pp3 = &p3; }catch(const Unreachable_file &e){ pp3 = NULL; }

    std::string fontPath = "main/assets/fonts/retro.ttf";
    _elements.push_back(Illustration("background.png",   0.f, 0.f, 1.f, 1.f, applicationPath));
    _elements.push_back(Illustration("frame.png", 0.f, 0.f, 1.3f, 1.3f, applicationPath));
    _elements.push_back(Illustration("saves-frames.png",   0.f, 0.f, 0.5f, 0.5f, applicationPath));
    // display player 1 infos
    if(pp1 == NULL){
        _selectableElements.push_back(Text("Empty", 255, 255, 255, fontPath.c_str(), 40, -0.25f, 0.35f));       
    }
    else{
        _selectableElements.push_back(Text(pp1->name().c_str(), 255, 255, 255, fontPath.c_str(), 40, -0.25f, 0.35f));
        std::string money = std::to_string(pp1->money());
        _elements.push_back(Text(money.c_str(), 255, 255, 255, fontPath.c_str(), 40, 0.25f, 0.35f));
    }
    // display player 2 infos
    if(pp2 == NULL){
        _selectableElements.push_back(Text("Empty", 255, 255, 255, fontPath.c_str(), 40, -0.25f, 0.05f));       
    }
    else{
        _selectableElements.push_back(Text(pp2->name().c_str(), 255, 255, 255, fontPath.c_str(), 40, -0.25f, 0.1f));
        std::string money = std::to_string(pp2->money());
        _elements.push_back(Text(money.c_str(), 255, 255, 255, fontPath.c_str(), 40, 0.25f, 0.1f));
    }
    // display player 3 infos
    if(pp3 == NULL){
        _selectableElements.push_back(Text("Empty", 255, 255, 255, fontPath.c_str(), 40, -0.25f, -0.25f));       
    }
    else{
        _selectableElements.push_back(Text(pp3->name().c_str(), 255, 255, 255, fontPath.c_str(), 40, -0.25f, -0.25f));
        std::string money = std::to_string(pp3->money());
        _elements.push_back(Text(money.c_str(), 255, 255, 255, fontPath.c_str(), 40, 0.25f, -0.25f));
    }
    _elements.push_back(Illustration("arrow.png", -0.475f, 0.31, 0.03f, 0.03f, applicationPath));
    
}

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
        default:
            break;
    }
}

// deals with key down events
void SaveMenu::manageKeyDownEvents(const SDLKey &k){
    switch(k){
        case SDLK_s:
            arrowDown();
            break;
        case SDLK_ESCAPE:
            throw GoToStartMenu();
            break;
        case SDLK_SPACE:
            try{ 
                _player = Player::load(std::string("player_")+std::to_string(_currentButton+1));
                _world.character().texture(_player.selectedSkin().texture());
                throw GoToPlayerMenu();
            }
            catch(const Unreachable_file &e){ throw GoToCreatePlayerMenu(_currentButton+1);}
            break;
        case SDLK_z:
            arrowUp();
            break;
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
