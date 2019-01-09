#ifndef _SKYBOX_ 
#define _SKYBOX_

#include "StaticObject.hpp"

class Skybox : public StaticObject{
protected:
	virtual const std::string TEXTURE_FILE(){return "gameboy.png";}
	virtual const std::string OBJ_FILE(){return "skybox.obj";}
public:
	Skybox(){}
	~Skybox(){}
	//Parameter constructor
	Skybox(const int & x, const int & y, const float & altitude, const float & height)
	:StaticObject(  glm::vec3(x,altitude,y),
	                glm::vec3(x,altitude,y),
	                glm::vec3(x+1,altitude+height,y+1))
	{loadMesh();}
};

#endif