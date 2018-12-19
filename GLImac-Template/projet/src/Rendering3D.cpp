#include "Rendering3D.hpp"

Rendering3D::Rendering3D(const glimac::FilePath &applicationPath, const unsigned int &screen){
glEnable(GL_DEPTH_TEST);

    _ProjMatrix = glm::perspective(glm::radians(70.f), (float)(1600 / 1200), 0.1f, 100.f );
    _MVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, -5.f));
    _NormalMatrix = glm::transpose(glm::inverse(_MVMatrix));

    // Variable type sphere, rayon 1, 32 segments lat, 16 segments long
    _sphere = glimac::Sphere(1, 32, 16);

    // textures
    //Chargement image
    std::unique_ptr<glimac::Image> earthMapImg = glimac::loadImage("/home/lea-harabagiu/Documents/OpenGL/GLImac-Template/assets/textures/EarthMap.jpg");
    if(earthMapImg == NULL) std::cout << "ERROR EARTH IMG" << std::endl;
    std::unique_ptr<glimac::Image> moonMapImg = glimac::loadImage("/home/lea-harabagiu/Documents/OpenGL/GLImac-Template/assets/textures/MoonMap.jpg");
    if(moonMapImg == NULL) std::cout << "ERROR MOON IMG" << std::endl;
    // terre
    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        earthMapImg->getWidth(),
        earthMapImg->getHeight(),
        0,
        GL_RGBA,
        GL_FLOAT,
        earthMapImg->getPixels()
    );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    //_vbo
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    // les données sont dans sphere.getDataPointer();
    glBufferData(
        GL_ARRAY_BUFFER,
        _sphere.getVertexCount() * sizeof(glimac::ShapeVertex),
        _sphere.getDataPointer(),
        GL_STATIC_DRAW
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //_vao
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);
    //position
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
    //normales
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
    //texture
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

    std::vector<glm::vec3> initPos(32);
    for(int i = 0; i < 32; i++){
        initPos[i] = glm::sphericalRand(2.f);
    }

    std::vector<glm::vec3> axis(32);
    for(int i = 0; i < 32; i++){
        axis[i] = glm::sphericalRand(1.f);
    }	
}

void Rendering3D::show(const GPUProgram2D &program2D, const GPUProgram3D &program3D){
		_MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
  //       _MVMatrix = glm::rotate(_MVMatrix, windowManager.getTime(), glm::vec3(0, 1, 0));
        glUniformMatrix4fv(program3D._uMVPMatrix, 1, GL_FALSE, glm::value_ptr(_ProjMatrix * _MVMatrix));
        glUniformMatrix4fv(program3D._uMVMatrix, 1, GL_FALSE, glm::value_ptr(_MVMatrix));
        glUniformMatrix4fv(program3D._uNormalMatrix, 1, GL_FALSE, glm::value_ptr(_NormalMatrix));

        glBindVertexArray(_vao);
        glBindTexture(GL_TEXTURE_2D, _texture);
        glUniform1i(program3D._uTexture, 0);
        glDrawArrays(GL_TRIANGLES, 0, _sphere.getVertexCount());
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0);
}