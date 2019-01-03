#include "Mesh.hpp"

std::map<std::string, VAO*> Mesh::_already_loaded_models = {};
std::map<std::string, GLuint*> Mesh::_already_loaded_texture = {};

Mesh::Mesh(const std::string &abs_project_path, const std::string &obj_filename, const std::string &texture_filename){
	//vao
	//If already loaded
	std::map<std::string, VAO*>::const_iterator itVAO = Mesh::_already_loaded_models.find(obj_filename);
	if(itVAO != Mesh::_already_loaded_models.end()){
		_vao = itVAO->second;
	}else{
		_vao = new VAO(abs_project_path,obj_filename);
		Mesh::_already_loaded_models[obj_filename] = _vao;
	}

	//Texture
	//If already loaded
	std::map<std::string,GLuint*>::const_iterator itTEXTURE = Mesh::_already_loaded_texture.find(texture_filename);
	if(itTEXTURE != Mesh::_already_loaded_texture.end()){
		_texture = itTEXTURE->second;
	}else{
		_texture = new GLuint;
		loadTexture(abs_project_path, (texture_filename.size() != 0) ? texture_filename : DEFAULT_TEXTURE);
		Mesh::_already_loaded_texture[texture_filename] = _texture;
	}
}

void Mesh::loadTexture(const std::string &abs_project_path, const std::string &filename){
	std::unique_ptr<glimac::Image> image = glimac::loadImage(abs_project_path + TEXTURE_FOLDER + filename);
	if (image == NULL)
		throw UNREACHABLE_FILE(abs_project_path + TEXTURE_FOLDER + filename);

	glGenTextures(1, _texture);
	glBindTexture(GL_TEXTURE_2D, *_texture);
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		image->getWidth(),
		image->getHeight(),
		0,
		GL_RGBA,
		GL_FLOAT,
		image->getPixels()
		);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	std::cout << "Texture [" << abs_project_path << TEXTURE_FOLDER + filename << "] loaded" << std::endl;
}



void Mesh::show(const GLint &uTexture){
	_vao->bind();    
	glBindTexture(GL_TEXTURE_2D, *_texture);
	glUniform1i(uTexture, 0);
	_vao->draw();
	glBindTexture(GL_TEXTURE_2D, 0);
	_vao->unbind();    
}


void Mesh::clearAllLoadedMesh(){
	for(std::map<std::string, GLuint*>::iterator itr = Mesh::_already_loaded_texture.begin(); itr != Mesh::_already_loaded_texture.end(); itr++){
		glDeleteTextures(1, itr->second);
    	delete itr->second;
	}
	for(std::map<std::string, VAO*>::iterator itr = Mesh::_already_loaded_models.begin(); itr != Mesh::_already_loaded_models.end(); itr++)
    	delete itr->second;
}