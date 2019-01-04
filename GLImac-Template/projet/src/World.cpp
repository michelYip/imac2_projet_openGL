#include "World.hpp"

World::World()
: _worldSpeed(INITIAL_SPEED), 
_gameOverZone(0), 
_cameraPosition(glm::vec3(0,0,0)),
_backgroundTexture("No background yet"),
_player(),
_map()
{}

//Set map with a file name
void World::createMap(const std::string & map){
	_map = Map(map, MAP_NUMBER);
}

//Set map with a reference
void World::setMap(const Map & map){
	_map = map;
}

//Return the current map
Map World::getMap() const{
	return _map;
}

//Make the world continue running
bool World::coroutine(const bool done){
	// TODO
	_cameraPosition += _worldSpeed;
	//
	return done && isFinished();
}

bool World::isFinished(){
	// TODO
	return true;
}

const std::vector<Object> World::getAllPrintableObjects() const{
	std::vector<Object> list = _map.objectList();
	// list.push_back(_player);
	return list; 
}