#include "Button.hpp"

Button::Button(const std::string imageName){
	std::unique_ptr<glimac::Image> image = glimac::loadImage("/home/lea-harabagiu/Documents/projet_ogl/imac2_projet_openGL/GLImac-Template/assets/textures/menus/" + imageName + ".png");
	if(image == NULL) std::cout << "ERROR IMG " << imageName << std::endl;
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