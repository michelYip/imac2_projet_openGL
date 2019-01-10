#ifndef _ILLUSTRATION_
#define _ILLUSTRATION_

#include <glimac/Image.hpp>
#include <GL/glew.h>
#include <string>
#include <cstddef>
#include <iostream>

#include "Element2D.hpp"

/// \class Illustration
/// \brief 2D element
class Illustration: public Element2D{
	public:
		Illustration(){}
		Illustration(const std::string &imageName, const float &posX, const float &posY, const float &width, const float &height, const glimac::FilePath &applicationPath):Element2D(imageName, posX, posY, width, height, applicationPath){}
		// Illustration(const Illustration &image):_position(glm::vec2(image._position.x, image._position.y)),_dimension(glm::vec2(image._dimension.x, image._dimension.y)), Element2D(image._texture){
		// }
		~Illustration(){}

		Illustration &operator=(const Illustration &image){
			if(this != &image){
				_position = glm::vec2(image._position.x, image._position.y);
				_texture = image._texture;
			}
		}
};

#endif