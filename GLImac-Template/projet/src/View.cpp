#include "View.hpp"

glm::mat3 translate(float tx, float ty){
    return glm::mat3(
        1.f, 0.f, tx,
        0.f, 1.f, ty,
        0.f, 0.f, 1.f
    );
};
glm::mat3 scale(float sx, float sy){
    return glm::mat3(
        sx, 0.f, 0.f,
        0.f, sy, 0.f,
        0.f, 0.f, 1.f
    );
}
glm::mat3 rotate(float a){
    return glm::mat3(
        glm::cos(glm::radians(a)), glm::sin(glm::radians(a)), 0.f,
        -glm::sin(glm::radians(a)), glm::cos(glm::radians(a)), 0.f,
        0.f, 0.f, 1.f
    );
}

// initializes sdl window
int View::window(const glimac::FilePath &applicationPath){
	GLenum glewInitError = glewInit();
	if(GLEW_OK != glewInitError){
		std::cerr << glewGetErrorString(glewInitError) << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    glimac::Program program = glimac::loadProgram(applicationPath.dirPath() + "shaders/tex2D.vs.glsl", applicationPath.dirPath() + "shaders/tex2D.fs.glsl");
    program.use();

    // variables uniformes des shaders
    GLint uLoc = glGetUniformLocation(program.getGLId(), "uModelMatrix");
    GLint uCol = glGetUniformLocation(program.getGLId(), "uColor");
    GLint uTex = glGetUniformLocation(program.getGLId(), "uTexture");

    std::unique_ptr<Image> triforceImg = loadImage(applicationPath.dirPath() + "assets/textures/menus/try.png");
    if(triforceImg == NULL) std::cout << "oups" << std::endl;
    // création objet texture
    GLuint triforceText;
    glGenTextures(1, &triforceText);
    glBindTexture(GL_TEXTURE_2D, triforceText);
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        triforceImg->getWidth(),
        triforceImg->getHeight(),
        0,
        GL_RGBA,
        GL_FLOAT,
        triforceImg->getPixels()
    );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);


    // _renderingEngine.push_back(RenderingInterface('s'));
    // for(int i = 0; i < this->_renderingEngine.size(); i++){
    // 	_renderingEngine[i].initialize();
    // }

	GLuint vbo;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // => Tableau de sommets : un seul exemplaire de chaque sommet
    Vertex2DUV vertices[] = {
        Vertex2DUV(glm::vec2(-0.5, -0.5), glm::vec2( 0, 1)), // Sommet 0
        Vertex2DUV(glm::vec2(0.5, -0.5), glm::vec2(1, 1)), // Sommet 1
        Vertex2DUV(glm::vec2(0.5, 0.5), glm::vec2(1, 0)), // Sommet 2
        Vertex2DUV(glm::vec2(-0.5, 0.5), glm::vec2(0, 0)) // Sommet 3
    };
    // => Penser à bien changer le nombre de sommet (4 au lieu de 6):
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex2DUV), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // => Creation du IBO
    GLuint ibo;
    glGenBuffers(1, &ibo);

    // => On bind sur GL_ELEMENT_ARRAY_BUFFER, cible reservée pour les IBOs
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    // => Tableau d'indices: ce sont les indices des sommets à dessiner
    // On en a 6 afin de former deux triangles
    // Chaque indice correspond au sommet correspondant dans le VBO
    uint32_t indices[] = {
        0, 1, 2, 0, 2, 3
    };

    // => On remplit l'IBO avec les indices:
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint32_t), indices, GL_STATIC_DRAW);

    // => Comme d'habitude on debind avant de passer à autre chose
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    GLuint vao;
    glGenVertexArrays(1, &vao);

    glBindVertexArray(vao);

    // => On bind l'IBO sur GL_ELEMENT_ARRAY_BUFFER; puisqu'un VAO est actuellement bindé,
    // cela a pour effet d'enregistrer l'IBO dans le VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 
        sizeof(Vertex2DUV), (const GLvoid*) offsetof(Vertex2DUV, _pos));
    glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, 
        sizeof(Vertex2DUV), (const GLvoid*) offsetof(Vertex2DUV, _tex));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);    

    float speedSelfRotation = 1440.f;
    float speedRotation = 100.f;

    float radius = 1.f;

    clock_t begin = clock();
    clock_t end = clock();
    double timelapse;

    while(!this->_done){
    	SDL_Event e;
    	while(this->_windowManager.pollEvent(e)){
			this->manageEvents(e);
    	}
    	glClear(GL_COLOR_BUFFER_BIT);
		// for(int i = 0; i < this->_renderingEngine.size(); i++){
		// 	_renderingEngine[i].show();
		// }

 		glBindVertexArray(vao);


        glBindTexture(GL_TEXTURE_2D, triforceText);

        glUniform1i(uTex, 0);
        glUniformMatrix3fv(uLoc, 1, GL_FALSE,glm::value_ptr(glm::mat3(1)));
        glUniform3f(uCol, 1.f, 0.f, 0.f);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glBindTexture(GL_TEXTURE_2D, 0);

        glBindVertexArray(0);


    	this->_windowManager.swapBuffers();
    }

        glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    glDeleteTextures(1, &triforceText);
    // for(int i = 0; i < this->_renderingEngine.size(); i++){
    // 	_renderingEngine[i].end();
    // }    
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
	y = -(y - WINDOW_HEIGHT * 2 / 3); 
	return glm::vec2(x, y);
}

// deals with key up events
void View::manageKeyUpEvents(const SDLKey &k){
	switch(k){
		case SDLK_DOWN:
			std::cout << "menu down !" << std::endl; 
			break;
		case SDLK_ESCAPE:
			this->_done = true;
			break;
		case SDLK_LEFT:
			std::cout << "menu left" << std::endl;
			break;
		case SDLK_RETURN:
			std::cout << "ok !" << std::endl;
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