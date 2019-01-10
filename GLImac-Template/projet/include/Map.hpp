#ifndef _MAP_ 
#define _MAP_

#include <vector>
#include <string>
#include <fstream>
#include "Object.hpp"
#include "Obstacle.hpp"
#include "Coin.hpp"
#include "Character.hpp"
#include "exceptions/Incorrect_map_file.hpp"
#include "exceptions/Unreachable_map_file.hpp"

//PPM file const
const int MAP_SIZE = 15;
const std::string MAP_SAVING_FOLDER = "main/maps/";
const float HEIGHT_RATIO_PPM = 10;
const int PIXEL_COMP = 3;
const float START_MIN = 24.5;
const float START_MAX = 25.5;
const float END_MIN = 23.5;
const float END_MAX = 24.5;
const int INIT_X = 8;
const int INIT_Z = 3;

const int MAP_NUMBER = 6;

/// \class Map
/// \bried [DESCRIPTION TO FILL] 
class Map
{
private: 
	std::vector<Object> _objectList;
	std::vector<Coin> _coinList;
	glm::vec2 _startPoint;
	std::vector<glm::vec2> _endPoints;
	std::vector<Map> _nextMaps;

public:
	//CONSTRUCTORS & DESTRUCTORS
	
	//Default constructor
	Map();

	//Reference constructor
	Map(const Map & other);

	//Parameter constructor
	Map(const std::string & mapFile, const int & flag, const glm::vec2 & start);

	//Default destructor
	~Map() = default;

	//Return the starting point
	inline glm::vec2 getStartPoint() const{
		return _startPoint;
	}

	//Return a list of the ends point
	inline std::vector<glm::vec2> getEndPoints() const{
		return _endPoints;
	}

	//Return the list of the next maps
	inline const std::vector<Map> getNextMaps() const { return _nextMaps; }

	//Create a random map at the end of the track
	void appendMaps();

	//Create an object from a pixel
	void createObject(const int & col, const int & row, const float & g, const float & b);

	//Add an object to the object list
	void addObject(const Object & obj);
	//Add a coin to the coin list
	void addCoin(const Coin & coin);

	//Remove an object from the object list
	void removeObject(const Object & obj);
	//Remove a coin from the coin list
	void removeCoin(const Coin & coin);

	//Progress in the map
	void moveMap(const float & distance);

	//Return the list of the map object
	inline std::vector<Object> objectList(){ return _objectList; }
	//Return the list of the map object
	inline std::vector<Coin> coinList(){ return _coinList; }

	//Return the list of object of all maps
	std::vector<Object> getAllObjects(const int & i) const;

	//Return a random map name
	std::string randomMap() const;

	//DEBUG

	//Print the starting point and the end point of the map
	void printExtremity();

	//Print the object list with their position and bounding box
	void printObjectList();
};

#endif