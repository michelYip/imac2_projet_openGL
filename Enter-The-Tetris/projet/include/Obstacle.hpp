#ifndef _OBSTACLE_ 
#define _OBSTACLE_

#include "StaticObject.hpp"

const int OBSTACLE_GROUNDED_THRESHOLD = 10;
const int OBSTACLE_AIRBORN_THRESHOLD  = 20;
const float OBSTACLE_FLOAT_HEIGHT = 1.5;
const int OBSTACLE_HEIGHT_MARGIN = 5;


/// \class Obstacle
/// \bried Obstacle present on the Map
class Obstacle : public StaticObject
{
protected:
	virtual const std::string TEXTURE_FILE(){return "floor.png";}
	// virtual const std::string OBJ_FILE(){return "character.obj";}

public:
	//CONSTRUCTORS & DESTRUCTORS
	//Default constructor
	Obstacle();

	//Parameter constructor
	Obstacle(const int & x, const int & y, const int & altitude);

	//Default destructor
	~Obstacle() = default;
	
};

#endif