#ifndef _ELEMENT2D_
#define _ELEMENT2D_

#include <glimac/Image.hpp>
#include <GL/glew.h>
#include <string>
#include <cstddef>
#include <iostream>

/// \class Element2D
/// \brief 2D Element, can be an Illustration or Text
class Element2D{
	protected:
		GLuint _texture; ///< texture of the element
		glm::vec2 _position; ///< position of the texture
		glm::vec2 _dimension; ///< dimension of the texture
	public:
		Element2D(){}
		/// \param: imageName : name of the image
		/// \param: posX, posY : position of the element
		/// \param: width, height : dimension of the element
		/// \param: Game applicationPath 
		Element2D(const std::string &imageName, const float &posX, const float &posY, const float &width, const float &height, const glimac::FilePath &applicationPath);
		~Element2D(){}

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
		void setPosX(const float &posX){
			_position.x = posX;
		}
};

#endif