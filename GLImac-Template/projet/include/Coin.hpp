#ifndef _COIN_ 
#define _COIN_


#include "StaticObject.hpp"

class Coin : public StaticObject
{
protected:
	// virtual const std::string TEXTURE_FILE(){return "white.png";}
	// virtual const std::string OBJ_FILE(){return "character.obj";}

public:
	Coin(){loadMesh();}
	~Coin() = default;
	
};

#endif