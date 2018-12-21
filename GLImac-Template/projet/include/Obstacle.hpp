#ifndef _OBSTACLE_ 
#define _OBSTACLE_

#include "StaticObject.hpp"

const int OBSTACLE_GROUNDED_THRESHOLD = 100;
const int OBSTACLE_AIRBORN_THRESHOLD  = 200;
const int OBSTACLE_FLOAT_HEIGHT = 3;
const int OBSTACLE_HEIGHT_MARGIN = 50;

class Obstacle : public StaticObject
{
public:
	//CONSTRUCTORS & DESTRUCTORS
	//Default constructor
	Obstacle();

	//Parameter constructor
	Obstacle(const int & x, const int & y, const float & altitude, const float & height);

	//Default destructor
	~Obstacle() = default;
	
};

#endif