#include "Rendering3D.hpp"

Rendering3D::Rendering3D(const glimac::FilePath & applicationPath, const unsigned int &screen, const GPUProgram3D & program3D)
: _program3D(program3D)
{
    _ProjMatrix = glm::perspective(glm::radians(70.f), (float)(WINDOW_WIDTH / WINDOW_HEIGHT), 0.1f, 100.f);
    _MVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, -5.f));
    _NormalMatrix = glm::transpose(glm::inverse(_MVMatrix));

    glimac::Sphere sphere(1, 32, 16);
    _sphere = sphere;

    std::unique_ptr<glimac::Image> image = loadImage(applicationPath.dirPath() + "assets/textures/obj/EarthMap.jpg");
    if(image == NULL) std::cout << "ERROR IMG 3D" << std::endl;
    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        image->getWidth(),
        image->getHeight(),
        0,
        GL_RGBA,
        GL_FLOAT,
        image->getPixels()
    );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(
        GL_ARRAY_BUFFER,
        _sphere.getVertexCount() * sizeof(glimac::ShapeVertex),
        _sphere.getDataPointer(),
        GL_STATIC_DRAW
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    glEnableVertexAttribArray(POS_ATTRIB_IND);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glVertexAttribPointer(
        POS_ATTRIB_IND,
        3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(glimac::ShapeVertex),
        (const GLvoid*)offsetof(glimac::ShapeVertex, position)
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnableVertexAttribArray(NORM_ATTRIB_IND);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glVertexAttribPointer(
        NORM_ATTRIB_IND,
        3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(glimac::ShapeVertex),
        (const GLvoid*)offsetof(glimac::ShapeVertex, normal)
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnableVertexAttribArray(TEXT_ATTRIB_IND);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glVertexAttribPointer(
        TEXT_ATTRIB_IND,
        2,
        GL_FLOAT,
        GL_FALSE,
        sizeof(glimac::ShapeVertex),
        (const GLvoid*)offsetof(glimac::ShapeVertex, texCoords)
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

void Rendering3D::show(const TrackballCamera &tbCamera, const FreeflyCamera &ffCamera, const std::string &cameraType){

    if(cameraType == "third") _MVMatrix = tbCamera.getViewMatrix();
    else _MVMatrix = ffCamera.getViewMatrix();
    _NormalMatrix = glm::transpose(glm::inverse(_MVMatrix));

    // _MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
    glUniformMatrix4fv(_program3D._uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * _MVMatrix));
    glUniformMatrix4fv(_program3D._uMVMatrix, 1, GL_FALSE, glm::value_ptr(_MVMatrix));
    glUniformMatrix4fv(_program3D._uNormalMatrix, 1, GL_FALSE, glm::value_ptr(_NormalMatrix));

    _program3D._program.use(); 
    glBindVertexArray(_vao);
    glBindTexture(GL_TEXTURE_2D, _texture);
    glUniform1i(_program3D._uTexture, 0);
    glDrawArrays(GL_TRIANGLES, 0, _sphere.getVertexCount());
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindVertexArray(0);

    _MVMatrix = glm::translate(_MVMatrix, glm::vec3(3, 0, 0));
    glUniformMatrix4fv(_program3D._uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * _MVMatrix));
    glUniformMatrix4fv(_program3D._uMVMatrix, 1, GL_FALSE, glm::value_ptr(_MVMatrix));
    glUniformMatrix4fv(_program3D._uNormalMatrix, 1, GL_FALSE, glm::value_ptr(_NormalMatrix));

    _program3D._program.use();
    glBindVertexArray(_vao);
    glBindTexture(GL_TEXTURE_2D, _texture);
    glUniform1i(_program3D._uTexture, 0);
    glDrawArrays(GL_TRIANGLES, 0, _sphere.getVertexCount());
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindVertexArray(0);
}

void Rendering3D::end(){
    glDeleteBuffers(1, &_vbo);
    glDeleteVertexArrays(1, &_vao);
    glDeleteTextures(1, &_texture);
}