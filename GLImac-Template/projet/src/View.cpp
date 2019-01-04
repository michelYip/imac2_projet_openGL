#include "View.hpp"

// initializes sdl window
int View::createWindow(const glimac::FilePath &applicationPath, const World &world){
	GLenum glewInitError = glewInit();
	if(GLEW_OK != glewInitError){
		std::cerr << glewGetErrorString(glewInitError) << std::endl;
		return EXIT_FAILURE;
	}
	// initialisation SDL_ttf
	GLenum ttfInitError = TTF_Init();
	if(ttfInitError == -1){
		std::cerr << TTF_GetError() << std::endl;
		return EXIT_FAILURE;
	}

    // Rendering 2D (interface)
    RenderingInterface* startMenu = new RenderingInterface(applicationPath, 0);
    _renderingEngine.push_back(startMenu);
    RenderingInterface* savesMenu = new RenderingInterface(applicationPath, 1);
    _renderingEngine.push_back(savesMenu);
    RenderingInterface* playerMenu = new RenderingInterface(applicationPath, 2);
    _renderingEngine.push_back(playerMenu);

    // Rendering 3D (game)
    Rendering3D* sphere = new Rendering3D(applicationPath, 0, world);
    _renderingEngine.push_back(sphere);

    // Rendering 2D (gameinfos)
    RenderingInterface* gameInfos = new RenderingInterface(applicationPath, 3);
    _renderingEngine.push_back(gameInfos);

    return EXIT_SUCCESS;
}

void View::displayWindow(){
	if (!_done){
		SDL_ShowCursor(SDL_DISABLE);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		if (_screen != 3)	{
			_renderingEngine[this->_screen]->show();
		}
		else {
			_renderingEngine[_screen]->show(_camera);
			_renderingEngine[_screen+1]->show();
		}
		_windowManager.swapBuffers();
	}
}

void View::clearWindow(){
	for(int i = 0; i < _renderingEngine.size(); i++){
 		_renderingEngine[i]->end();
		delete _renderingEngine.at(i);
	}
	_renderingEngine.clear();
}

void View::waitEvents(){
	SDL_Event e;
	while(_windowManager.pollEvent(e)){
		manageEvents(e);
	}
}

// deals with the events
void View::manageEvents(const SDL_Event &e){
	switch(e.type){
		case SDL_QUIT:
			this->_done = true;
			break;
		case SDL_KEYDOWN:
			this->_keyPressed = true;
			break;
		case SDL_KEYUP:
			this->manageKeyUpEvents(e.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			if(_camera.cameraType() == "third" && _locked == false){
				if(e.button.button == SDL_BUTTON_WHEELUP) _camera.thirdPCamera().moveFront(0.5f);
				else if(e.button.button == SDL_BUTTON_WHEELDOWN) _camera.thirdPCamera().moveFront(-0.5f);	
			}
			break;
		case SDL_MOUSEMOTION:
			if(_locked == false) _camera.cameraMotion(getMousePosition(), _lastPos);
			break;
		default: 
			break;
	}
	if(_keyPressed) manageKeyDownEvents(e.key.keysym.sym);
}

// converts mouse position from windowManager to position for game landmark
glm::vec2 View::getMousePosition(){
	float x = _windowManager.getMousePosition().x, y = _windowManager.getMousePosition().y;
	x = x - WINDOW_WIDTH / 2;
	y = -(y - WINDOW_HEIGHT * 3 / 4); 
	return glm::vec2(x, y);
}

// deals with key up events
void View::manageKeyUpEvents(const SDLKey &k){
	switch(k){
		case SDLK_BACKSPACE:
			if(_screen != 0) _screen -= 1;
			break;
		case SDLK_DOWN:
			if(_screen != NB_SCREEN -1) _renderingEngine[_screen]->arrowDown(_screen);
			break;
		case SDLK_ESCAPE:
			this->_done = true;
			break;
		case SDLK_SPACE:
		 	if(!_renderingEngine[_screen]->actionButton(_screen)) _done = true;
			break;
		case SDLK_UP:
			if(_screen != NB_SCREEN -1) _renderingEngine[_screen]->arrowUp(_screen);
			break;

		case SDLK_c:
			_camera.changeCameraType();
			break;
		case SDLK_l:
			if(_locked){
				_lastPos = glm::vec2(getMousePosition().x, getMousePosition().y);
				this->_locked = false;
			}
			else this->_locked = true;
			break;
		case SDLK_d:
		case SDLK_q:
			this->_keyPressed = false;
			break;
		case SDLK_s:
			std::cout << "down !" << std::endl;
			break;
		case SDLK_z:
			std::cout << "jump !" << std::endl;
			break;
		default:
			break;
	}
}

// deals with key down events
void View::manageKeyDownEvents(const SDLKey &k){
	switch(k){
		case SDLK_d:
			std::cout << "droite !" << std::endl;
			break;
		case SDLK_q:
			std::cout << "gauche !" << std::endl;
			break;
		default:
			break;
	}	
}