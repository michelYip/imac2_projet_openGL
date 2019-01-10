#include "Texture.hpp"


const std::string Texture::DEFAULT_TEXTURE = "default.png";
const std::string Texture::TEXTURE_FOLDER = "main/assets/textures/obj/";

Texture::Texture(const std::string &filename){
	std::string tmpFilename = (filename.size() == 0) ? DEFAULT_TEXTURE : filename;
	std::unique_ptr<glimac::Image> image = glimac::loadImage(TEXTURE_FOLDER + tmpFilename);
	if(image == NULL)
		throw UNREACHABLE_FILE(TEXTURE_FOLDER + filename);
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
	std::cout << "Texture [" << TEXTURE_FOLDER + tmpFilename << "] loaded" << std::endl;
}

Texture::~Texture(){
	glDeleteTextures(1, &_texture);
}

void Texture::bind(){
	glBindTexture(GL_TEXTURE_2D, _texture);
}

void Texture::unbind(){
	glBindTexture(GL_TEXTURE_2D, 0);
}

