#include "View.hpp"

// initializes sdl window
int View::createWindow(const glimac::FilePath &applicationPath){
	GLenum glewInitError = glewInit();
	if(GLEW_OK != glewInitError){
		std::cerr << glewGetErrorString(glewInitError) << std::endl;
		return EXIT_FAILURE;
	}

	// Programs
    GPUProgram2D program2D(applicationPath, "tex2D.vs.glsl", "tex2D.fs.glsl");
    GPUProgram3D program3D(applicationPath, "3D.vs.glsl", "tex3D.fs.glsl");

    // Rendering 2D (interface)
    RenderingInterface startMenu(applicationPath, 0, program2D);
    _renderingEngine.push_back(&startMenu);
    RenderingInterface savesMenu(applicationPath, 1, program2D);
    _renderingEngine.push_back(&savesMenu);
    RenderingInterface playerMenu(applicationPath, 2, program2D);
    _renderingEngine.push_back(&playerMenu);

    // Rendering 3D (game)
    Rendering3D sphere(applicationPath, 0, program3D);
    _renderingEngine.push_back(&sphere);

    // Cameras
    TrackballCamera tbCamera;
    _thirdPCamera = tbCamera;

    // while(!_done){
    // 	SDL_Event e;
    // 	while(_windowManager.pollEvent(e)){
	// 		manageEvents(e);
    // 	}
    // 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//     glEnable(GL_DEPTH_TEST);
	//     glDepthFunc(GL_LEQUAL);
   	// 	if (this->_screen != 3)	this->_renderingEngine[this->_screen]->show();
	// 	else {
	// 		this->_renderingEngine[this->_screen]->show(_thirdPCamera, _firstPCamera, _cameraType);
	// 	}
    // 	this->_windowManager.swapBuffers();
    // }
	// for(int i = 0; i < this->_renderingEngine.size(); i++){
 	// 	this->_renderingEngine[i]->end();
	// } 
    return EXIT_SUCCESS;
}

void View::displayWindow(){
	if (!_done){
		SDL_Event e;
		while(_windowManager.pollEvent(e)){
			manageEvents(e);
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		if (this->_renderingEngine.empty()) std::cout << "FUCKING EMPTY" << std::endl;
		else std::cout << this->_renderingEngine.size() << std::endl;
		if (this->_screen != 3)	{
			std::cout << "SEGFAULT NOT HERE : " << this->_screen << std::endl;
			this->_renderingEngine[this->_screen]->show();
			std::cout << "SEGFAULT HERE" << std::endl;
		}
		else {
			this->_renderingEngine[this->_screen]->show(_thirdPCamera, _firstPCamera, _cameraType);
		}
		this->_windowManager.swapBuffers();
	}
}

void View::clearWindow(){
	for(int i = 0; i < this->_renderingEngine.size(); i++){
 		this->_renderingEngine[i]->end();
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
			if(this->_cameraType == "third" && _locked == false){
				if(e.button.button == SDL_BUTTON_WHEELUP) this->_thirdPCamera.moveFront(0.5f);
				else if(e.button.button == SDL_BUTTON_WHEELDOWN) this->_thirdPCamera.moveFront(-0.5f);	
			}
			break;
		case SDL_MOUSEMOTION:
			if(_locked == false){
				if(this->_cameraType == "first") this->firstPersonCameraMotion();
				else this->thirdPersonCameraMotion();	
			}
			break;
		default: 
			break;
	}
	if(this->_keyPressed) this->manageKeyDownEvents(e.key.keysym.sym);
}

// converts mouse position from windowManager to position for game landmark
glm::vec2 View::getMousePosition(){
	float x = this->_windowManager.getMousePosition().x, y = this->_windowManager.getMousePosition().y;
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
			if(_cameraType == "third") _cameraType = "first";
			else _cameraType = "third";
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

// trackball Camera
void View::firstPersonCameraMotion(){
	float posX = getMousePosition().x, posY = getMousePosition().y;
	_firstPCamera.rotateLeft(posX - _lastPos.x);
	_firstPCamera.rotateUp(posY - _lastPos.y);		
}
// freefly Camera
void View::thirdPersonCameraMotion(){
	float posX = getMousePosition().x, posY = getMousePosition().y;
	_thirdPCamera.rotateLeft(posX - _lastPos.x);
	_thirdPCamera.rotateUp(posY - _lastPos.y);
}