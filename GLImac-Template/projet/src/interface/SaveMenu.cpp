#include "interface/SaveMenu.hpp"

SaveMenu::SaveMenu(const glimac::FilePath &applicationPath, Player &player)
:RenderingInterface(applicationPath), _player(player)
{
    Player p1, p2, p3;  
    Player *pp1, *pp2, *pp3;  
    //Load player to print which ones are already created
    try{ p1 = Player::load("player_1"); pp1 = &p1; }catch(const Unreachable_file &e){ pp1 = NULL; }
    try{ p2 = Player::load("player_2"); pp2 = &p2; }catch(const Unreachable_file &e){ pp2 = NULL; }
    try{ p3 = Player::load("player_3"); pp3 = &p3; }catch(const Unreachable_file &e){ pp3 = NULL; }

    if(pp1 == NULL) std::cout <<  "Player1 saving file not found" << std::endl;
    else std::cout << *pp1 << " found" << std::endl;
    
    if(pp2 == NULL) std::cout <<  "Player2 saving file not found" << std::endl;
    else std::cout << *pp2 << " found" << std::endl;
    
    if(pp3 == NULL) std::cout <<  "Player3 saving file not found" << std::endl;
    else std::cout << *pp3 << " found" << std::endl;
     
    _elements.push_back(ImageButton("background.png",   0.f, 0.f, 1.f, 1.f, applicationPath));
    _elements.push_back(ImageButton("frame.png", 0.f, 0.f, 1.3f, 1.3f, applicationPath));
    _elements.push_back(ImageButton("saves-frames.png",   0.f, 0.f, 0.5f, 0.5f, applicationPath));
    _elements.push_back(ImageButton("arrow.png", -0.475f, 0.31, 0.03f, 0.03f, applicationPath));
    
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
        case SDLK_DOWN:
            arrowDown();
            break;
        case SDLK_BACKSPACE:
            throw GoToStartMenu();
            break;
        case SDLK_ESCAPE:
            throw QuitGame();
            break;
        case SDLK_SPACE:
            try{ 
                _player = Player::load(std::string("player_")+std::to_string(_currentButton+1));
                throw GoToPlayerMenu();
            }
            catch(const Unreachable_file &e){ throw GoToCreatePlayerMenu(_currentButton+1);}
            break;
        case SDLK_UP:
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
