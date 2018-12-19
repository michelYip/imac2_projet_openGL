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
		Button(const std::string &imageName, const float &posX, const float &posY, const glimac::FilePath &applicationPath);
		~Button(){};

		inline GLuint texture() const{
			return _texture;
		};
		inline float posX() const{
			return _position.x;
		};
		inline float posY() const{
			return _position.y;
		};
};

#endif