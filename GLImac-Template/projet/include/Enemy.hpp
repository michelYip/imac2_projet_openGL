#ifndef _ENEMY_ 
#define _ENEMY_


#include "MovingObject.hpp"

/// \class Enemy
/// \brief Enemy present on the Map
class Enemy : public MovingObject
{
protected:
	// virtual const std::string TEXTURE_FILE(){return "white.png";}
	// virtual const std::string OBJ_FILE(){return "character.obj";}

public:
	Enemy(){loadMesh();}
	~Enemy() = default;
	
};

#endif