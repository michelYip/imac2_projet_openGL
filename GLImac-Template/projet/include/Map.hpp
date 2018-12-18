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

	void addObject(const Object & obj);

	void removeObject(const Object & obj);
	
};

#endif