#ifndef _ILLUSTRATION_
#define _ILLUSTRATION_

#include <glimac/Image.hpp>
#include <GL/glew.h>
#include <string>
#include <cstddef>
#include <iostream>

#include "Element2D.hpp"

/// \class Illustration
/// \brief In order to display the wanted images / textures
class Illustration: public Element2D{
	public:
		Illustration(){}
		/// \param: imageName : name of the image
		/// \param: posX, posY : position of the element
		/// \param: width, height : dimension of the element
		/// \param: Game applicationPath 
		Illustration(const std::string &imageName, const float &posX, const float &posY, const float &width, const float &height, const glimac::FilePath &applicationPath):Element2D(imageName, posX, posY, width, height, applicationPath){}
		~Illustration(){}
};

#endif