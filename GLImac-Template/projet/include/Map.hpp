#ifndef _MAP_ 
#define _MAP_

#include <vector>
#include <string>
#include <fstream>
#include "Object.hpp"
#include "Obstacle.hpp"
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
/// \brief The structure of the Map where the game takes place
class Map
{
private: 
	std::vector<Object> _objectList; ///< The vector of object in the map
	glm::vec2 _startPoint; ///< The starting point of a map, used as a node to connect to the previous map
	std::vector<glm::vec2> _endPoints; ///< The vector of endings of a map, used as a node to connect to the next map(s)
	std::vector<Map> _nextMaps; ///< The vector of incomming maps

public:
	//CONSTRUCTORS & DESTRUCTORS
	
	Map();

	/// \brief Reference constructor
	Map(const Map & other);

	/// \brief Parameter constructor
	/// \param mapFile: The map file in ppm format to create from
	/// \param flag: Check if other maps should be appended to the end of the vector
	/// \param start: Starting point used to connect two maps together 
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

	//Return a list of the object of the map
	const std::vector<Object> objectList() const{ return _objectList; }

	/// \brief Create a random map at the end of the track
	void appendMaps();

	/// \brief Create an object from a pixel in the ppm
	/// \param col: x index in the game 
	/// \param row: z index in the game
	/// \param g: green component of the pixel, used to create Obstacle
	/// \param b: blue component of the pixel, used to create Coins
	void createObject(const int & col, const int & row, const float & g, const float & b);

	/// \brief Add an object to the object list
	/// \param obj: Object to add to the list
	void addObject(const Object & obj);

	/// \brief Remove an object from the object list
	/// \param obj: Object to remove from the list
	void removeObject(const Object & obj);

	/// \brief Progress in the map
	/// \param distance: The distance used to move all object of the map
	void moveMap(const float & distance);

	inline std::vector<Object> getObjectList(){ return _objectList; }

	/// \brief Return the list of object until the i-th Map
	/// \param i: Number of map to look for object
	/// \return: The list of all object to the i-th Map
	std::vector<Object> getAllObjects(const int & i) const;

	/// \brief Return a random map name
	std::string randomMap() const;

	//DEBUG

	//Print the starting point and the end point of the map
	void printExtremity();

	//Print the object list with their position and bounding box
	void printObjectList();
};

#endif