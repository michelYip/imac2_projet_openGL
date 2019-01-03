#include "Rendering3D.hpp"

Rendering3D::Rendering3D(const glimac::FilePath & applicationPath, const unsigned int &screen)
{
    _program3D = GPUProgram3D(applicationPath, "3D.vs.glsl", "tex3D.fs.glsl");
    
    _ProjMatrix = glm::perspective(glm::radians(70.f), (float)(WINDOW_WIDTH / WINDOW_HEIGHT), 0.1f, 100.f);
    _MVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, -5.f));
    _NormalMatrix = glm::transpose(glm::inverse(_MVMatrix));


    _meshList.push_back(Mesh(applicationPath.dirPath(),"Crate1.obj",""));
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
    _meshList.at(0).show(_program3D._uTexture);
}
