#ifndef _WORLD_ 
#define _WORLD_

#include "Physic.hpp"
#include "Map.hpp"

class World
{
private: 
	float _speed;
	float _xPos;
	float _yPos;
	std::string _backgroundTexture;
	Physic _physicEngine;
	Map _map;
public:
	World();
	~World();
	
};

#endif