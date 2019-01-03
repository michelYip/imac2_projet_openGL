
#ifndef _MESH_ 
#define _MESH_

#include "VAO.hpp"
#include <iostream>
#include <map>
#include <GL/glew.h>

const std::string DEFAULT_TEXTURE = "default.png";



class Mesh
{
	private:
		static std::map<std::string, GLuint*> _already_loaded_texture;
		static std::map<std::string, VAO*> _already_loaded_models;
		GLuint *_texture;
		VAO *_vao;

		void loadTexture(const std::string &abs_project_path, const std::string &filename);
	public:
		Mesh() = default;
		
		Mesh(const std::string &abs_project_path, const std::string &obj_filename, const std::string &texture_filename);

		
		Mesh(const Mesh &m)
		:_vao(m._vao), _texture(m._texture){}

		~Mesh(){}

		void show(const GLint &uTexture);

		static void clearAllLoadedMesh();
		
};

#endif