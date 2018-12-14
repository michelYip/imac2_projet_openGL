#include "View.hpp"

// initializes sdl window
int View::createWindow(){
	SDLWindowManager windowManager(1600, 1200, "SanGLimac");

	GLenum glewInitError = glewInit();
	if(GLEW_OK != glewInitError){
		std::cerr << glewGetErrorString(glewInitError) << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    while(!this->_done){
    	SDL_Event e;
    	while(windowManager.pollEvent(e)){
			this->manageEvents(e);
    	}
    	windowManager.swapBuffers();
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
		case SDL_MOUSEBUTTON:
			break;
		case SDL_MOUSEMOTION:
			this->cameraRotation();
			break;
		default: 
			std::cout << "le sanglier court" << std::endl;
			break;
	}
	if(this->_keyPressed) this->manageKeyDownEvents(e.key.keysym.sym);
}

//
void View::manageKeyUpEvents(const SDLKey &k){
	switch(k){
		case SDLK_ESCAPE:
			this->_done = true;
			break;
		case SDLK_c:
			std::cout << "changement de caméra !" << std::endl;
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
			std::cout << "saut !" << std::endl;
			break;
		default:
			break;
	}
}

//
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
void View::cameraRotation(){
	float x = windowManager.getMousePosition().x, y = windowManager.getMousePosition().y;
}