#ifndef _WORLD_ 
#define _WORLD_

#include <iostream>
#include <vector>
#include "Physic.hpp"
#include "Map.hpp"
#include "Skybox.hpp"

const float INITIAL_SPEED = 10;
const int MAX_MAPS = 4;

/// \class World
/// \brief World of the Game that manages every element in it
class World
{
private:
	float _worldSpeed; ///< World traveling speed
	float _gameOverZone; ///< Distance to game over
	glm::vec3 _cameraPosition; 
	std::string _backgroundTexture; 
	Character _player; ///< Current character
	Map _map; ///< Current map
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

	/// \brief Check if the end of the current map is reached
	/// \return: True if the character reached the end on the map, otherwise return False
	bool endOfMapReached() const;

	/// \brief Change the current map to the next one depending on the character position
	void switchMap();

	/// \brief Initialize the character to the World
	void initCharacter();

	//Return the character
	inline Character &character() { return _player; }

	/// \brief Return a list of all object in the world
	/// \return: A list containing every Object of every Map in the world
	const std::vector<Object> getAllPrintableObjects() const;
	//Return the money of the player
	inline unsigned int earnedMoney() const{
		return _player.totalCoin();
	}

	/// \brief Make the world run
	/// \return: True if the game has ended, return false otherwise
	bool coroutine(const bool & done, const float & time_interval);

	/// \brief Check if the game has ended or not
	/// \return: True if the game has ended, return False otherwise
	bool isFinished();

	/// \brief reset score to 0
	void resetScore(){
		_player.resetCoins();
	}
	
};

#endif