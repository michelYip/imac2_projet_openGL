#ifndef _MODEL3D_ 
#define _MODEL3D_

#include "Rendering.hpp"
#include "ObjLoader.hpp"

#include <iostream>
#include <fstream>
#include "exceptions/Unreachable_file.hpp"
#include "Vertex3DUV.hpp"
#include <vector>


const std::string OBJ_FOLDER = "main/assets/models/";

class Model3D
{
	private:
		std::vector<Vertex3DUV> _vertices;
		std::vector<int> _indexes;
		
		//Only created by callin loadObj()
		Model3D(const std::vector<Vertex3DUV> &vertices, const std::vector<int> &indexes)
		:_vertices(vertices),_indexes(indexes)
		{} 
	
	public:
		~Model3D() = default;

		static Model3D loadObj(const std::string &filename, std::vector<Vertex3DUV> &obj_list_vertice, std::vector<int> &obj_list_indices);

		inline const std::std::vector<Vertex3DUV> &vertices() const{return _vertices;}
		inline const std::std::vector<int> &indexes() const{return _indexes;}
};

#endif