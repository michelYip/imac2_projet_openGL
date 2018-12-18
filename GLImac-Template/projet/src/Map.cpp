#include <algorithm>

#include "Map.hpp"

Map::Map()
: _player(), _objectList()
{}

void Map::addObject(const Object & obj){
    _objectList.push_back(obj);
}

void Map::removeObject(const Object & obj){
    _objectList.erase(std::remove(_objectList.begin(), _objectList.end(), obj), _objectList.end());
}