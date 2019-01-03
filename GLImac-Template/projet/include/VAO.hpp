
#ifndef _VAO_ 
#define _VAO_

#include "Rendering.hpp"
#include <iostream>
#include <fstream>
#include "exceptions/Unreachable_file.hpp"
#include "Vertex3DUV.hpp"
#include <vector>
#include <map>
#include <GL/glew.h>


#include <glimac/Sphere.hpp>


const GLuint POS_ATTRIB_IND = 0;
const GLuint NORM_ATTRIB_IND = 1;
const GLuint TEXT_ATTRIB_IND = 2;


const std::string OBJ_FOLDER = "main/assets/models/";
const std::string TEXTURE_FOLDER = "/assets/textures/obj/";

class VAO
{
	private:
		GLuint _vbo;
		GLuint _vao;
		GLuint _ibo;
		std::vector<Vertex3DUV> _vertices;
		std::vector<int> _indexes;

		
		void loadObj(const std::string &abs_project_path, const std::string &obj_filename);
		void create_glvao();
	public:
		
		// VAO() = default;
		VAO(const std::string &abs_project_path, const std::string &obj_filename);
		VAO(const VAO &m)
		:_vbo(m._vbo), _vao(m._vao), _ibo(m._ibo), _vertices(m._vertices), _indexes(m._indexes) 
		{}

		~VAO(){
			glDeleteBuffers(1, &_vbo);
		    glDeleteVertexArrays(1, &_vao);
		}

		void bind() const;
		void unbind() const;
		void draw() const;
		
		
};

#endif