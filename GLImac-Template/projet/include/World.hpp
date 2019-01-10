#ifndef _WORLD_ 
#define _WORLD_

#include <iostream>
#include <vector>
#include "Physic.hpp"
#include "Map.hpp"
#include "Skybox.hpp"

const float INITIAL_SPEED = 3;
const int MAX_MAPS = 4;

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

	//Set map with a reference
	void setMap(const Map & map);

	//Return the current map
	Map getMap() const;

	//Check if the end of the map is reached
	bool endOfMapReached() const;

	//Change the current map to the next one
	void switchMap();

	//Create the character
	void initCharacter();

	//Return the character
	inline Character &character() { return _player; }

	//Return a list of all object in the world
	const std::vector<Object> getAllPrintableObjects() const;

	//Make the world continue running
	bool coroutine(const bool & done, const float & time_interval);

	bool isFinished();
	
};

#endif