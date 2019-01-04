#ifndef _MALUS_ 
#define _MALUS_

#include "TriggerObject.hpp"

class Malus : public TriggerObject
{
protected:
	// virtual const std::string TEXTURE_FILE(){return "white.png";}
	// virtual const std::string OBJ_FILE(){return "character.obj";}

public:
	Malus(){loadMesh();}
	~Malus() = default
	
};

#endif