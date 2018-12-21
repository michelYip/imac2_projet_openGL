#ifndef _WORLD_ 
#define _WORLD_

#include <iostream>
#include "Physic.hpp"
#include "Map.hpp"

const float INITIAL_SPEED = 5.0f;
const int MAP_NUMBER = 2;

class World
{
private: 
	float _worldSpeed;
	float _gameOverZone;
	glm::vec3 _cameraPosition;
	std::string _backgroundTexture;
	Character _player;
	Map _map;
public:
	//CONSTRUCTORS & DESTRUCTORS
	//Default constructor
	World();
	
	//Default destructor
	~World() = default;

	//GETTERS & SETTERS
	//Set map with a file name
	void createMap(const std::string & map);

	//Set map with a reference
	void setMap(const Map & map);

	//Return the current map
	Map getMap() const;

	//Make the world continue running
	bool coroutine();

	bool isFinished();
	
};

#endif