#ifndef _WORLD_ 
#define _WORLD_

#include <iostream>
#include "Physic.hpp"
#include "Map.hpp"

const float INITIAL_SPEED = 5.0f;

class World
{
private: 
	float _worldSpeed;
	float _gameOverZone;
	glm::vec3 _cameraPosition;
	std::string _backgroundTexture;
	Map _map;
public:
	World();
	
	~World() = default;

	//Make the world continue running
	bool coroutine();

	bool isFinished();
	
};

#endif