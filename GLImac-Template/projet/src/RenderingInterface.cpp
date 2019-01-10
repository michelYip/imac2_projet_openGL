#include "RenderingInterface.hpp"

RenderingInterface::RenderingInterface(const glimac::FilePath &applicationPath)
{    
    _program2D = GPUProgram2D(applicationPath, "tex2D.vs.glsl", "tex2D.fs.glsl");

    glGenBuffers(1, &this->_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);

    Vertex2DUV vertices[] = {
        Vertex2DUV(glm::vec2(-1, -1), glm::vec2( 0, 1)),
        Vertex2DUV(glm::vec2(1, -1), glm::vec2(1, 1)),
        Vertex2DUV(glm::vec2(1, 1), glm::vec2(1, 0)), 
        Vertex2DUV(glm::vec2(-1, 1), glm::vec2(0, 0)) 
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
glm::mat3 scale(float sx, float sy){
    return glm::mat3(
        sx, 0.f, 0.f,
        0.f, sy, 0.f,
        0.f, 0.f, 1.f
    );
}


void RenderingInterface::show() {
    if(!_elements.empty() || !_selectableElements.empty()){
    _program2D._program.use();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glBindVertexArray(this->_vao);
    for(int i = 0; i < _elements.size(); i++)
        showElement(_elements.at(i));
    for(int i = 0; i < _selectableElements.size(); i++)
        showElement(_selectableElements.at(i));   
    glBindVertexArray(0);
    }
}


void RenderingInterface::showElement(const Element2D &image){
    glBindTexture(GL_TEXTURE_2D, image.texture());
    glUniform1i(_program2D._uTexture, 0);
    glUniformMatrix3fv(_program2D._uModelMatrix, 1, GL_FALSE,glm::value_ptr(scale(image.width(), image.height()) * translate(image.posX(), image.posY())));
    glUniform3f(_program2D._uColor, 1.f, 0.f, 0.f);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
}


RenderingInterface::~RenderingInterface(){
    glDeleteBuffers(1, &this->_vbo);
    glDeleteVertexArrays(1, &this->_vao);
    for(int i = 0; i < this->_elements.size(); i++){
        GLuint texture = this->_elements[i].texture();
        glDeleteTextures(1, &texture);  
    }
    for(int i = 0; i < this->_selectableElements.size(); i++){
        GLuint texture = this->_selectableElements[i].texture();
        glDeleteTextures(1, &texture);  
    }
 }


void RenderingInterface::arrowDown(){
    if(_currentButton != _selectableElements.size()-1){
        _currentButton++;
        updateArrow();
    }
}

void RenderingInterface::arrowUp(){
    if(_currentButton != 0){
        _currentButton--;
        updateArrow();
    }
}

void RenderingInterface::updateArrow(){
    _elements.back().setPosY(_selectableElements.at(_currentButton).posY());
}
