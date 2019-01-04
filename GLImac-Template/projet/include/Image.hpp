#ifndef _IMAGE_
#define _IMAGE_

#include <glimac/Image.hpp>
#include <GL/glew.h>
#include <string>
#include <cstddef>
#include <iostream>

class Image{
	private:
		glm::vec2 _position;
		glm::vec2 _dimension;
		GLuint _texture;
	public:
		Image(){};
		Image(const std::string &imageName, const float &posX, const float &posY, const float &width, const float &height, const glimac::FilePath &applicationPath);
		Image(const Image &image):_position(glm::vec2(image._position.x, image._position.y)),_dimension(glm::vec2(image._dimension.x, image._dimension.y)), _texture(image._texture){
		};
		~Image(){};

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

		Image &operator=(const Image &image){
			if(this != &image){
				_position = glm::vec2(image._position.x, image._position.y);
				_texture = image._texture;
			}
		}
};

#endif