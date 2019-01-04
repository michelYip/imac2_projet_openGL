#include "VAO.hpp"
#include <sstream>

const std::string VAO::OBJ_FOLDER = "main/assets/models/";
const GLuint VAO::POS_ATTRIB_IND = 0;
const GLuint VAO::NORM_ATTRIB_IND = 1;
const GLuint VAO::TEXT_ATTRIB_IND = 2;


VAO::VAO(const std::string &obj_filename){
//Load vertices & indexes
	loadObj(obj_filename);
	create_glvao();
}


void VAO::create_glvao(){
	GLenum glewInitError = glewInit();
	if(GLEW_OK != glewInitError)
		std::cerr << glewGetErrorString(glewInitError) << std::endl;

//VBO
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(
        GL_ARRAY_BUFFER,
        _vertices.size() * sizeof(Vertex3DUV),
        _vertices.data(),
        GL_STATIC_DRAW
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);


// IBO
    glGenBuffers(1, &_ibo);
    // => On bind sur GL_ELEMENT_ARRAY_BUFFER, cible reservée pour les IBOs
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
    // => On remplit l'IBO avec les indices:
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indexes.size() * sizeof(int), _indexes.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

// VAO
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);

    glEnableVertexAttribArray(POS_ATTRIB_IND);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glVertexAttribPointer(
        POS_ATTRIB_IND,
        3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex3DUV),
        (const GLvoid*)Vertex3DUV::offset_pos()
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnableVertexAttribArray(NORM_ATTRIB_IND);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glVertexAttribPointer(
        NORM_ATTRIB_IND,
        3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex3DUV),
        (const GLvoid*)Vertex3DUV::offset_norm()
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnableVertexAttribArray(TEXT_ATTRIB_IND);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glVertexAttribPointer(
        TEXT_ATTRIB_IND,
        2,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex3DUV),
        (const GLvoid*)Vertex3DUV::offset_tex()
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}


glm::vec3 getvec3(std::string str_line){
	std::istringstream split(str_line); 
	std::vector<std::string> vertice;
	for (std::string each; std::getline(split, each, ' '); vertice.push_back(each.substr(each.find_first_not_of(' '))));
	glm::vec3 point(
		std::stof(vertice.at(1)),
		std::stof(vertice.at(2)),
		std::stof(vertice.at(3))
		);
	return point;
}

glm::vec2 getvec2(std::string str_line){
	std::istringstream split(str_line); 
	std::vector<std::string> vertice;
	for (std::string each; std::getline(split, each, ' '); vertice.push_back(each.substr(each.find_first_not_of(' '))));
	glm::vec2 point(
		std::stof(vertice.at(1)),
		std::stof(vertice.at(2))
		);
	return point;
}


void VAO::loadObj(const std::string &obj_filename){
	std::ifstream objFile;
	objFile.open(OBJ_FOLDER+obj_filename, std::fstream::in);
	if(!objFile.is_open())
		throw UNREACHABLE_FILE(OBJ_FOLDER+obj_filename);
	
	std::vector<glm::vec3> v;
	std::vector<glm::vec3> vn;
	std::vector<glm::vec2> vt;
	std::vector<int> f;
	int point_count = 0;

	while(!objFile.eof()){
		char *tmp_line = new char[128];
		objFile.getline(tmp_line,128);
		std::string str_line(tmp_line);

		//remove extra space
		for(int i=str_line.size()-1; i >= 0; i-- )
	        if(str_line[i]==' '&&str_line[i]==str_line[i-1])
	            str_line.erase(str_line.begin()+i);
		

		if(str_line.size() != 0 && str_line.compare(0, 2, "v ") == 0){//vertice coords
			v.push_back(getvec3(str_line));
		}else if(str_line.size() != 0 && str_line.compare(0, 2, "vn") == 0){//normals
			vn.push_back(getvec3(str_line));
		}else if(str_line.size() != 0 && str_line.compare(0, 2, "vt") == 0){//textures
			vt.push_back(getvec2(str_line));
		}else if(str_line.size() != 0 && str_line.compare(0, 2, "f ") == 0){//faces
			std::map<std::string, int> point_saver; //To skip creating already existing point

			std::istringstream split(str_line); 
			std::vector<std::string> f;
			for (std::string each; std::getline(split, each, ' '); f.push_back(each));
			
			int nbPoint = f.size();

			//Creating points
			for (int i = 1; i < nbPoint; ++i){
				std::string original_str = f.at(i);
				std::map<std::string, int>::iterator it = point_saver.find(f.at(i));
				if(it == point_saver.end()){	
					int i_v, i_vt, i_vn;
					int pos_slash1, pos_slash2;

					//v
					pos_slash1 = f.at(i).find('/');
					i_v = std::stoi(f.at(i).substr(0,(pos_slash1 == -1) ? f.size() : pos_slash1));
					f.at(i).erase(0,pos_slash1+1);

					//vt
					pos_slash2 = f.at(i).find('/');
					i_vt = (pos_slash2 == 0) ? 0 : std::stoi(f.at(i).substr(0,(pos_slash2 == -1) ? f.size() : pos_slash2));
					f.at(i).erase(0,pos_slash2+1);
					
					//vn
					i_vn = (pos_slash2 == -1) ? 0 : (i < f.size() && f.at(i).size() == 0) ? 0 : std::stoi(f.at(i));
					
					glm::vec3 vertex_v  = (i_v  > 0) ? v.at(i_v-1)   : glm::vec3();
					glm::vec3 vertex_vn = (i_vn > 0) ? vn.at(i_vn-1) : glm::vec3();
					glm::vec2 vertex_vt = (i_vt > 0) ? vt.at(i_vt-1) : glm::vec2();
					_vertices.push_back(Vertex3DUV(vertex_v,vertex_vn,vertex_vt));
					point_saver[original_str] = point_count;
					_indexes.push_back(point_count++);

				}else{
					_indexes.push_back(point_saver[original_str]);
				}		

				//If too many point for a face we decompose in triangles
				if(nbPoint > 3){
					if(i > 3){
						_indexes.push_back(_indexes.at(_indexes.size()-4));
						_indexes.push_back(_indexes.at(_indexes.size()-3));
					}
				}
			}
		}
	}
}


void VAO::draw() const{
	glDrawElements(GL_TRIANGLES, _indexes.size(), GL_UNSIGNED_INT, 0);
}

void VAO::bind() const{
	glBindVertexArray(_vao);
}

void VAO::unbind() const{
	glBindVertexArray(0);
}