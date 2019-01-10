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
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){
		std::cerr << "ERROR MUSIC" << Mix_GetError() << std::endl;
		return EXIT_FAILURE;
	}			
	_audio.play("blue-monday");
    return EXIT_SUCCESS;
}

void View::displayWindow(){
	if (!_done){
		SDL_ShowCursor(SDL_DISABLE);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		_rendering->show();
		_windowManager.swapBuffers();
	}
}

void View::clearWindow(){
	TTF_Quit();
	_audio.clear();
	Mix_CloseAudio();
	SDL_Quit();
}

void View::waitEvents(){
	try{
		SDL_Event e;
		while(_windowManager.pollEvent(e)){
			_rendering->manageEvents(e);
		}
	}catch(const QuitGame &e){
		std::cout << "Game exit requested..." << std::endl;
		clearWindow();
		_done = 1;
	}
}