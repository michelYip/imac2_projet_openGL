#include "Rendering3D.hpp"

Rendering3D::Rendering3D(const glimac::FilePath & applicationPath, Camera* camera, World &world)
:_world(world), _camera(camera)
{  
    _programs.push_back(GPUProgram3D(applicationPath, "3D.vs.glsl", "directionalLight.fs.glsl"));  
    _ProjMatrix = glm::perspective(glm::radians(70.f), (float)(WINDOW_WIDTH / WINDOW_HEIGHT), 0.1f, 100.f);
}

void Rendering3D::show(){
    _camera->updatePos(_world.character().getPosition());
    _MVMatrix = _camera->getViewMatrix();
    _NormalMatrix = glm::transpose(glm::inverse(_MVMatrix));

    _programs[0].setMaterials(
        glm::vec3(1.f, 1.f, 1.f),
        glm::vec3(1.f, 1.f, 1.f),
        10.f
    );
    glm::vec4 lightPos = _MVMatrix * glm::vec4(0.0f, 1.0f, 1.5f, 0.0f);
    _programs[0].setLight(lightPos, glm::vec3(20.f, 20.f, 20.f));

    std::vector<Object> list_obj = _world.getAllPrintableObjects();
    _programs[0]._program.use();
    for (int i = 0; i < list_obj.size(); ++i){
        glm::mat4 tmp_MVMatrix = glm::translate(_MVMatrix, list_obj.at(i).position());
        glUniformMatrix4fv(_programs[0]._uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * tmp_MVMatrix));
        glUniformMatrix4fv(_programs[0]._uMVMatrix, 1, GL_FALSE, glm::value_ptr(tmp_MVMatrix));
        glUniformMatrix4fv(_programs[0]._uNormalMatrix, 1, GL_FALSE, glm::value_ptr(_NormalMatrix));
        list_obj.at(i).modele3D().show(_programs[0]._uTexture);
    }
}
