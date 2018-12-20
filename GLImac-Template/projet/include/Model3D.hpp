#ifndef _MODEL3D_ 
#define _MODEL3D_

#include "Rendering.hpp"
#include <iostream>
#include <fstream>
#include "exceptions/Unreachable_file.hpp"
#include "Vertex3DUV.hpp"
#include <vector>
#include <map>


const std::string OBJ_FOLDER = "main/assets/models/";

class Model3D
{
	private:
		static std::map<std::string, Model3D> already_created_models;
		std::vector<Vertex3DUV> _vertices;
		std::vector<int> _indexes; //list of indexes in order to create faces
		
		
	
	public:
		Model3D() = default;

		Model3D(const std::vector<Vertex3DUV> &vertices, const std::vector<int> &indexes)
		:_vertices(vertices),_indexes(indexes)
		{} 
		
		Model3D(const Model3D &m)
		:_vertices(m._vertices), _indexes(m._indexes)
		{}

		~Model3D() = default;

		static Model3D loadObj(const std::string &filename);

		inline const std::vector<Vertex3DUV> &vertices() const{return _vertices;}
		inline const std::vector<int> &indexes() const{return _indexes;}
};

#endif