
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
		static const std::string OBJ_FOLDER; ///< Path to .obj folder
		static const GLuint POS_ATTRIB_IND; ///< Shader position location
		static const GLuint NORM_ATTRIB_IND; ///< Shader normal location
		static const GLuint TEXT_ATTRIB_IND; ///< Shader texture position location

		GLuint _vbo;
		GLuint _vao;
		GLuint _ibo;
		std::vector<Vertex3DUV> _vertices; ///< Vertices list
		std::vector<int> _indexes; ///< Index of vertice list for ibo

		///\ brief Load the .obj to the vao  
		///\ param obj_filename: Filename of the .obj  
		void loadObj(const std::string &obj_filename);
		void create_glvao();
	public:
		
		// VAO() = default;

		///\ param obj_filename: Filename of the .obj  
		VAO(const std::string &obj_filename);
		
		VAO(const VAO &m)
		:_vbo(m._vbo), _vao(m._vao), _ibo(m._ibo), _vertices(m._vertices), _indexes(m._indexes) 
		{}

		~VAO(){
			glDeleteBuffers(1, &_vbo);
		    glDeleteVertexArrays(1, &_vao);
		}

		///\ brief Bind the vao  
		void bind() const;
		///\ brief undind the vao  
		void unbind() const;
		///\ brief undind the vao  
		void draw() const;
		
		
};

#endif