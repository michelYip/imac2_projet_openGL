
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



/// \class VAO
/// \brief Create a VAO that can be drawn on the window from an .obj file   
class VAO
{
	private:
		static const std::string OBJ_FOLDER;
		static const GLuint POS_ATTRIB_IND;
		static const GLuint NORM_ATTRIB_IND;
		static const GLuint TEXT_ATTRIB_IND;

		GLuint _vbo;
		GLuint _vao;
		GLuint _ibo;
		std::vector<Vertex3DUV> _vertices;
		std::vector<int> _indexes;

		
		void loadObj(const std::string &obj_filename);
		void create_glvao();
	public:
		
		// VAO() = default;
		VAO(const std::string &obj_filename);
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