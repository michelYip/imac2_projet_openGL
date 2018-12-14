#include "View.hpp"

// initializes sdl window
int View::createWindow() const{
	SDLWindowManager windowManager(1600, 1200, "SanGLimac");

	GLenum glewInitError = glewInit();
	if(GLEW_OK != glewInitError){
		std::cerr << glewGetErrorString(glewInitError) << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    bool done = false;
    while(!done){
    	SDL_Event e;
    	while(windowManager.pollEvent(e)){
    		if(e.type == SDL_QUIT){
    			done = true;
    		}
    	}
    	windowManager.swapBuffers();
    }
    return EXIT_SUCCESS;
}	