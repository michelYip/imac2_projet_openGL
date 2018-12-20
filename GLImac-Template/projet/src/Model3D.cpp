#include "Model3D.hpp"

#include <string> 
#include <vector>
#include <sstream>



Model3D Model3D::loadObj(const std::string &filename){
	std::ifstream objFile;
	objFile.open(OBJ_FOLDER+filename, std::fstream::in);
	if(!objFile.is_open())
		throw UNREACHABLE_FILE(OBJ_FOLDER+filename);
	
	std::vector<Vertex3DUV> obj_list_vertice;
	std::vector<int> obj_list_indices;

	while(!objFile.eof()){
		char *tmp_line = new char[128];
		objFile.getline(tmp_line,128);
		std::string str_line(tmp_line);
		
		std::cout << str_line << std::endl;
		if(str_line.size() != 0 && str_line.at(0) == 'v'){
			//Get vertices
			std::istringstream split(str_line); 
			std::vector<std::string> vertice;
			for (std::string each; std::getline(split, each, ' '); vertice.push_back(each));
				glm::vec3 point(
					std::stof(vertice.at(1)),
					std::stof(vertice.at(2)),
					std::stof(vertice.at(3))
					);
			obj_list_vertice.push_back(Vertex3DUV(point,glm::vec3()));
		}
		if(str_line.size() != 0 && str_line.at(0) == 'f'){
			//Get faces
			std::istringstream split(str_line); 
			std::vector<std::string> obj_list_indices_as_str;
			for (std::string each; std::getline(split, each, ' '); obj_list_indices_as_str.push_back(each));
			obj_list_indices.push_back(std::stoi(obj_list_indices_as_str.at(1))-1);
			obj_list_indices.push_back(std::stoi(obj_list_indices_as_str.at(2))-1);
			obj_list_indices.push_back(std::stoi(obj_list_indices_as_str.at(3))-1);
			obj_list_indices.push_back(std::stoi(obj_list_indices_as_str.at(4))-1);
		}
	}
	
	return Model3D(obj_list_vertice,obj_list_indices);

}


