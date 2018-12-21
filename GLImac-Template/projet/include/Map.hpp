#ifndef _MAP_ 
#define _MAP_

#include <vector>
#include <string>
#include <fstream>
#include "Object.hpp"
#include "Obstacle.hpp"
#include "Character.hpp"
#include "exceptions/Incorrect_saving_file.hpp"
#include "exceptions/Unreachable_saving_file.hpp"

//PPM file const
const int MAP_SIZE = 15;
const std::string MAP_SAVING_FOLDER = "main/maps/";
const float HEIGHT_RATIO_PPM = 10;
const int PIXEL_COMP = 3;
const float START_MIN = 24.5;
const float START_MAX = 25.5;
const float END_MIN = 23.5;
const float END_MAX = 24.5;

class Map
{
private: 
	std::vector<Object> _objectList;
	float _altitude[MAP_SIZE][MAP_SIZE];
	glm::vec2 _startPoint;
	std::vector<glm::vec2> _endPoints;
	std::vector<Map> _nextMaps;

public:
	//CONSTRUCTORS & DESTRUCTORS
	
	//Default constructor
	Map();

	//Parameter constructor
	Map(const std::string & mapFile, const int & flag);

	//Default destructor
	~Map() = default;

	//Create an object from a pixel
	void createObject(const int & col, const int & row, const float & r, const float & g, const float & b);

	//Add an object to the object list
	void addObject(const Object & obj);

	//Remove an object from the object list
	void removeObject(const Object & obj);
	
	//Add a block in the altitude list
	void addBlock(const int & col, const int & row, const float & altitude);

	//DEBUG

	//Print the altitude map
	void printAltitude() const;

	//Print the starting point and the end point of the map
	void printExtremity();

	//Print the object list with their position and bounding box
	void printObjectList();
};

#endif