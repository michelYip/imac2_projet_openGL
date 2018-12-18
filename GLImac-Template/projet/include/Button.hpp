#ifndef _BUTTON_
#define _BUTTON_

#include <glimac/Image.hpp>
#include <GL/glew.h>
#include <string>
#include <cstddef>
#include <iostream>

class Button{
	private:
		glm::vec2 _position;
		GLuint _texture;
	public:
		Button(){};
		Button(std::string imageName);
		~Button(){};

		inline GLuint getTexture() const{
			return this->_texture;
		};
};

#endif