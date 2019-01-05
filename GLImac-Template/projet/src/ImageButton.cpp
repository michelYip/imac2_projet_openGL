#include "ImageButton.hpp"

ImageButton::ImageButton(const std::string &imageName, const float &posX, const float &posY, const float &width, const float &height, const glimac::FilePath &applicationPath):_position(glm::vec2(posX, posY)), _dimension(glm::vec2(width, height)){
    std::unique_ptr<glimac::Image> image = glimac::loadImage(applicationPath.dirPath() + "assets/interface/" + imageName);
    if(image == NULL) std::cout << "ERROR IMG : " << imageName << std::endl;
    glEnable(GL_BLEND);
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
}