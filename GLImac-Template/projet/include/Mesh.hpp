#ifndef _MESH_ 
#define _MESH_

#include "VAO.hpp"
#include "Texture.hpp"
#include <iostream>
#include <map>
#include <GL/glew.h>

/// \class Mesh
/// \brief 3D Mesh of an object
class Mesh
{
	private:
		static std::map<std::string, Texture*> _already_loaded_texture; ///< Static map of all Textures that are already loaded, the string the name of the texture file 
		static std::map<std::string, VAO*> _already_loaded_models; ///< Static map of all VAO that are already loaded, the string is the name fo the .obj file
		Texture *_texture; ///< Texture of the Mesh
		VAO *_vao; ///< VAO (3D model) of the Mesh
	
	public:		
		Mesh() = default;
		
		/// \brief Load the the Mesh 
		/// \param obj_filename: .obj filename 
		/// \param texture_filename: texture filename 
		Mesh(const std::string &obj_filename, const std::string &texture_filename);

		
		/// \brief copy constructor
		Mesh(const Mesh &m)
		:_vao(m._vao), _texture(m._texture){}

		~Mesh(){}

		/// \brief Print the mesh in the GL environment 
		/// \param uTexture: uniform texture GLint of the GPUProgram3D
		void show(const GLint &uTexture) const;

		/// \brief free the static maps 
		static void clearAllLoadedMesh();
		
};

#endif