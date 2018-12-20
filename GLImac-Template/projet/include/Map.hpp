#ifndef _MAP_ 
#define _MAP_

#include <vector>
#include "Object.hpp"
#include "Character.hpp"

class Map
{
private: 
	Character _player;
	std::vector<Object> _objectList;

public:
	Map();
	~Map() = default;

	//Add an object to the object list
	void addObject(const Object & obj);

	//Remove an object from the object list
	void removeObject(const Object & obj);
	

	
};

#endif