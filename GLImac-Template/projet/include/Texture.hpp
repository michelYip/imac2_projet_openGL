#ifndef _TEXTURE_ 
#define _TEXTURE_

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <memory>
#include <glimac/Image.hpp>
#include "exceptions/Unreachable_file.hpp"



/// \class Texture
/// \brief Texture applied on a Mesh
class Texture
{
	private:
		static const std::string DEFAULT_TEXTURE; ///< Default texture file
		static const std::string TEXTURE_FOLDER; ///< Texture folder where texture files are saved
		GLuint _texture; ///< Texture of the Mesh
	
	public:
		/// \param filename: Filename of the texture
		Texture(const std::string &filename);
		
		~Texture();

		/// \brief bind the loaded texture to gl
		void bind();

		/// \brief unbind the loaded texture from gl
		void unbind();
};

#endif