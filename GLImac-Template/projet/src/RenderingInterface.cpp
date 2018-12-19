#include "RenderingInterface.hpp"

std::vector<Button> buttonsScreen(const unsigned int &screen, const glimac::FilePath &applicationPath){
	std::vector<Button> elements; 
	switch(screen){
		case 0:
			elements.push_back(Button("title.png", -0.5f, 0.5f,  applicationPath));
			elements.push_back(Button("try.png", -0.5f, -0.5f,  applicationPath));
			break;
		case 1:
			elements.push_back(Button("title.png", 0.f, 0.5f,  applicationPath));
			elements.push_back(Button("try.png", 0.f, -0.5f,  applicationPath));
			break;
		case 2:
			elements.push_back(Button("title.png", 0.5f, 0.5f,  applicationPath));
			elements.push_back(Button("try.png", 0.5f, -0.5f,  applicationPath));
			break;
		default:
			break;
	}
	return elements;
}

RenderingInterface::RenderingInterface(const glimac::FilePath &applicationPath, const unsigned int &screen){
    
    _elements = buttonsScreen(screen, applicationPath);

    glGenBuffers(1, &this->_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);

    Vertex2DUV vertices[] = {
        Vertex2DUV(glm::vec2(-0.5, -0.5), glm::vec2( 0, 1)),
        Vertex2DUV(glm::vec2(0.5, -0.5), glm::vec2(1, 1)),
        Vertex2DUV(glm::vec2(0.5, 0.5), glm::vec2(1, 0)), 
        Vertex2DUV(glm::vec2(-0.5, 0.5), glm::vec2(0, 0)) 
    };
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex2DUV), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &this->_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ibo);
    uint32_t indices[] = {
        0, 1, 2, 0, 2, 3
    };

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint32_t), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glGenVertexArrays(1, &this->_vao);
    glBindVertexArray(this->_vao);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_ibo);

    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
    glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 
        sizeof(Vertex2DUV), (const GLvoid*) offsetof(Vertex2DUV, _pos));
    glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, 
        sizeof(Vertex2DUV), (const GLvoid*) offsetof(Vertex2DUV, _tex));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);    
}

glm::mat3 translate(float tx, float ty){
    return glm::mat3(
        1.f, 0.f, tx,
        0.f, 1.f, ty,
        0.f, 0.f, 1.f
    );
};

void RenderingInterface::show(const GPUProgram2D &program2D, const GPUProgram3D &program3D){
    program2D._program.use();
	glBindVertexArray(this->_vao);
	for(int i = 0; i < this->_elements.size(); i++){
	    glBindTexture(GL_TEXTURE_2D, this->_elements[i].texture());
	    glUniform1i(program2D._uTexture, 0);
	    glUniformMatrix3fv(program2D._uModelMatrix, 1, GL_FALSE,glm::value_ptr(translate(this->_elements[i].posX(), this->_elements[i].posY())));
	    glUniform3f(program2D._uColor, 1.f, 0.f, 0.f);
	    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	    glBindTexture(GL_TEXTURE_2D, 0);
	}
    glBindVertexArray(0);
}

void RenderingInterface::end(){
    glDeleteBuffers(1, &this->_vbo);
    glDeleteVertexArrays(1, &this->_vao);
    for(int i = 0; i < this->_elements.size(); i++){
	    GLuint texture = this->_elements[i].texture();
	    glDeleteTextures(1, &texture);	
    }
}