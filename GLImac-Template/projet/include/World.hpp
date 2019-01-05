#ifndef _WORLD_ 
#define _WORLD_

#include <iostream>
#include <vector>
#include "Physic.hpp"
#include "Map.hpp"

const float INITIAL_SPEED = 0.2f;
const int MAX_MAPS = 5;


/// \class World
/// \brief World of the Game that manage every element present in it
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

	//Create the character
	void initCharacter();

	//Set map with a reference
	void setMap(const Map & map);

	//Return the current map
	Map getMap() const;

	//Return a list of all object in the world
	const std::vector<Object> getAllPrintableObjects() const;

	//Make the world continue running
	bool coroutine(const bool & done, const float & time_interval);

	bool isFinished();
	
};

#endif