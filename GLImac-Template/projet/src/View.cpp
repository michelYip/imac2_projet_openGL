#include "View.hpp"

// initializes sdl window
int View::window(const glimac::FilePath &applicationPath){
	GLenum glewInitError = glewInit();
	if(GLEW_OK != glewInitError){
		std::cerr << glewGetErrorString(glewInitError) << std::endl;
		return EXIT_FAILURE;
	}

    GPUProgram2D program2D(applicationPath, "tex2D.vs.glsl", "tex2D.fs.glsl");
    
    GPUProgram3D program3D(applicationPath, "3D.vs.glsl", "tex3D.fs.glsl");

    RenderingInterface startMenu(applicationPath, 0);
    this->_renderingEngine.push_back(&startMenu);
    RenderingInterface savesMenu(applicationPath, 1);
    this->_renderingEngine.push_back(&savesMenu);
    RenderingInterface playerMenu(applicationPath, 2);
    this->_renderingEngine.push_back(&playerMenu);

    Rendering3D sphere(applicationPath, 0);
    this->_renderingEngine.push_back(&sphere);

    while(!this->_done){
    	SDL_Event e;
    	while(this->_windowManager.pollEvent(e)){
			this->manageEvents(e);
    	}

    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   		this->_renderingEngine[this->_screen]->show(program2D, program3D);
    	this->_windowManager.swapBuffers();
    }
	for(int i = 0; i < this->_renderingEngine.size(); i++){
 		this->_renderingEngine[i]->end();
	} 
    return EXIT_SUCCESS;
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
			std::cout << "zomm out" << std::endl;
			break;
		case SDL_MOUSEBUTTONUP:
			std::cout << "zoom int" << std::endl;
			break;
		case SDL_MOUSEMOTION:
			if(this->_cameraType == "first") this->firstPersonCameraMotion();
			else this->thirdPersonCameraMotion();
			break;
		default: 
			std::cout << "le sanglier court" << std::endl;
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
			if(this->_screen != 0) this->_screen -= 1;
			break;
		case SDLK_DOWN:
			std::cout << "menu down !" << std::endl; 
			break;
		case SDLK_ESCAPE:
			this->_done = true;
			break;
		case SDLK_LEFT:
			std::cout << "menu left" << std::endl;
			break;
		case SDLK_SPACE:
		 	if(this->_screen != NB_SCREEN - 1) this->_screen += 1;
			break;
		case SDLK_RIGHT:
			std::cout << "menu right" << std::endl;
			break;
		case SDLK_UP:
			std::cout << "menu up !" << std::endl;
			break;

		case SDLK_c:
			if(this->_cameraType == "third") this->_cameraType = "first";
			else this->_cameraType = "third";
			break;
		case SDLK_l:
			if(this->_locked) this->_locked = false;
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

//
void View::firstPersonCameraMotion(){

}
//
void View::thirdPersonCameraMotion(){

}