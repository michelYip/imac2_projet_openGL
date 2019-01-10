#include "Mesh.hpp"

std::map<std::string, VAO*> Mesh::_already_loaded_models = {};
std::map<std::string, Texture*> Mesh::_already_loaded_texture = {};

Mesh::Mesh(const std::string &obj_filename, const std::string &texture_filename){
	//vao
	//If already loaded
	std::map<std::string, VAO*>::const_iterator itVAO = Mesh::_already_loaded_models.find(obj_filename);
	if(itVAO != Mesh::_already_loaded_models.end()){
		_vao = itVAO->second;
	}else{
		_vao = new VAO(obj_filename);
		Mesh::_already_loaded_models[obj_filename] = _vao;
	}
	//Texture
	//If already loaded
	std::map<std::string,Texture*>::const_iterator itTEXTURE = Mesh::_already_loaded_texture.find(texture_filename);
	if(itTEXTURE != Mesh::_already_loaded_texture.end()){
		_texture = itTEXTURE->second;
	}else{
		_texture = new Texture(texture_filename);
		Mesh::_already_loaded_texture[texture_filename] = _texture;
	}
}


void Mesh::show(const GLint &uTexture) const{
	_vao->bind();    
	_texture->bind();
	glUniform1i(uTexture, 0);
	_vao->draw();
	_texture->unbind();
	_vao->unbind();    
}


void Mesh::clearAllLoadedMesh(){
	for(std::map<std::string, Texture*>::iterator itr = Mesh::_already_loaded_texture.begin(); itr != Mesh::_already_loaded_texture.end(); itr++){
		delete itr->second;
	}
	for(std::map<std::string, VAO*>::iterator itr = Mesh::_already_loaded_models.begin(); itr != Mesh::_already_loaded_models.end(); itr++)
    	delete itr->second;
}