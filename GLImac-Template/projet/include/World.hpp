#ifndef _WORLD_ 
#define _WORLD_

#include <iostream>

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
	World()
	{}
	
	~World() = default;

	//Make the world continue running
	bool next_frame();

	bool isFinished();
	
};

#endif