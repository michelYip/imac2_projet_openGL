#ifndef _COIN_ 
#define _COIN_


#include "StaticObject.hpp"

/// \class Coin
/// \brief Coin present on the Map that add money to the Player at the end of every Game try
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