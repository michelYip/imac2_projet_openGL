#include "RenderingInterface.hpp"

std::vector<Button> buttonsScreen(const unsigned int &screen, const glimac::FilePath &applicationPath){
    std::vector<Button> elements; 
    switch(screen){
        case 0:
            elements.push_back(Button("background.png",   0.f, 0.f, 1.f, 1.f, applicationPath));
            elements.push_back(Button("frame.png", 0.f, 0.f, 1.3f, 1.3f, applicationPath));
            elements.push_back(Button("title.png", 0.05f, 0.f, 0.5f, 0.5f, applicationPath));
            elements.push_back(Button("start.png", 0.f, -0.25f, 0.1f, 0.05f, applicationPath));
            elements.push_back(Button("quit.png", 0.f, -0.35f, 0.07f, 0.05f, applicationPath));
            elements.push_back(Button("arrow.png", -0.15f, -0.25, 0.03f, 0.03f, applicationPath));
            break;
        case 1:
            elements.push_back(Button("background.png",   0.f, 0.f, 1.f, 1.f, applicationPath));
            elements.push_back(Button("frame.png", 0.f, 0.f, 1.3f, 1.3f, applicationPath));
            elements.push_back(Button("saves-frames.png",   0.f, 0.f, 0.5f, 0.5f, applicationPath));
            elements.push_back(Button("arrow.png", -0.475f, 0.35, 0.03f, 0.03f, applicationPath));
            break;
        case 2:
            elements.push_back(Button("background.png",   0.f, 0.f, 1.f, 1.f, applicationPath));
            elements.push_back(Button("frame.png", 0.f, 0.f, 1.3f, 1.3f, applicationPath));
            elements.push_back(Button("play.png", 0.05f, 0.25f, 0.07f, 0.05f, applicationPath));
            elements.push_back(Button("change-skin.png", 0.175f, 0.15f, 0.2f, 0.05f, applicationPath));
            elements.push_back(Button("change-player.png", 0.175f, 0.05f, 0.2f, 0.05f, applicationPath));
            elements.push_back(Button("quit.png", 0.05f, -0.05f, 0.07f, 0.05f, applicationPath));
            elements.push_back(Button("arrow.png", -0.1f, 0.25, 0.03f, 0.03f, applicationPath));
            break;
        default:
            break;
    }
    return elements;
}

RenderingInterface::RenderingInterface(const glimac::FilePath &applicationPath, const unsigned int &screen)
{    
    _program2D = GPUProgram2D(applicationPath, "tex2D.vs.glsl", "tex2D.fs.glsl");

    std::vector<Button> buttons = buttonsScreen(screen, applicationPath);
    _elements = buttons;

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
mat3 scale(float sx, float sy){
    return mat3(
        sx, 0.f, 0.f,
        0.f, sy, 0.f,
        0.f, 0.f, 1.f
    );
}

void RenderingInterface::show() {
    _program2D._program.use();
    glBindVertexArray(this->_vao);
    for(int i = 0; i < this->_elements.size(); i++){
        glBindTexture(GL_TEXTURE_2D, this->_elements[i].texture());
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glUniform1i(_program2D._uTexture, 0);
        glUniformMatrix3fv(_program2D._uModelMatrix, 1, GL_FALSE,glm::value_ptr(scale(this->_elements[i].width(), this->_elements[i].height()) * translate(this->_elements[i].posX(), this->_elements[i].posY())));
        glUniform3f(_program2D._uColor, 1.f, 0.f, 0.f);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_BLEND);
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

void RenderingInterface::arrowDown(const unsigned int &screen){
    float distance = 0.1;
    if(screen == 1) distance = 0.325;
    if(_currentButton != NB_BUTTON[screen]) {
        _elements.back().setPosY(_elements.back().posY() - distance);
        _currentButton += 1;
    }
}

void RenderingInterface::arrowUp(const unsigned int &screen){
    float distance = 0.1;
    if(screen == 1) distance = 0.325;
    if(_currentButton != 1){
        _elements.back().setPosY(_elements.back().posY() + distance);
        _currentButton -= 1;        
    }
}


bool RenderingInterface::actionButton(unsigned int &screen) const{
    if(screen == 1 || _currentButton == 1) screen += 1;
    else if(NB_BUTTON[screen] == _currentButton) return false;
    else if(screen == 2){
        if(_currentButton == 3) screen -= 1;
    }
    return true;
}