#include <algorithm>

#include "Map.hpp"

Map::Map()
: _player(), _objectList()
{}

//Add an object to the object list
void Map::addObject(const Object & obj){
    _objectList.push_back(obj);
}

//Remove an object from the object list
void Map::removeObject(const Object & obj){
    _objectList.erase(std::remove(_objectList.begin(), _objectList.end(), obj), _objectList.end());
}