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
		glm::vec2 _dimension;
		GLuint _texture;
	public:
		Button(){};
		Button(const std::string &imageName, const float &posX, const float &posY, const float &width, const float &height, const glimac::FilePath &applicationPath);
		Button(const Button &button):_position(glm::vec2(button._position.x, button._position.y)),_dimension(glm::vec2(button._dimension.x, button._dimension.y)), _texture(button._texture){
		};
		~Button(){};

		inline GLuint texture() const{
			return _texture;
		}
		inline float posX() const{
			return _position.x;
		}
		inline float posY() const{
			return _position.y;
		}
		inline float width() const{
			return _dimension.x;
		}
		inline float height() const{
			return _dimension.y;
		}

		void setPosY(const float &posY){
			_position.y = posY;
		}

		Button &operator=(const Button &button){
			if(this != &button){
				_position = glm::vec2(button._position.x, button._position.y);
				_texture = button._texture;
			}
		}
};

#endif