#include "World.hpp"

World::World()
: _worldSpeed(INITIAL_SPEED), 
_gameOverZone(0), 
_cameraPosition(glm::vec3(0,0,0)),
_backgroundTexture("No background yet"), 
_map() 
{}

bool World::coroutine(){
	// TODO
	_cameraPosition += _worldSpeed;
	//
	return !isFinished();
}

bool World::isFinished(){
	// TODO
	return true;
}