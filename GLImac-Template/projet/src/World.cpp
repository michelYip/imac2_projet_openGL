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
	_map = Map(map, MAX_MAPS, glm::vec2(0,0));
}

void World::initCharacter(){
	glm::vec2 start = _map.getStartPoint();
	_player = Character(glm::vec3(start.x, 0.1, start.y),
						glm::vec3(start.x - 0.5, 0, start.y - 0.5),
						glm::vec3(start.x + 0.5, 1, start.y + 0.5));
}

//Set map with a reference
void World::setMap(const Map & map){
	_map = map;
}

//Return the current map
Map World::getMap() const{
	return _map;
}

//Return a list of all object in the world
const std::vector<Object> World::getAllPrintableObjects() const{
	std::vector<Object> list = _map.getAllObjects(MAX_MAPS);
	list.push_back(_player);
	list.push_back(Skybox(0, -20, 0, 10));
	return list; 
}

//Make the world continue running
bool World::coroutine(const bool & done, const float & time_interval){
	// TODO
	float distance = _worldSpeed * time_interval;

	_map.moveMap(-distance);

	if ((_player.isMovingLeft() && _player.isMovingRight()) ||
		(!_player.isMovingLeft() && !_player.isMovingRight()))
	{
		_player.decelerateX(time_interval);
	}
	else _player.accelerateX(time_interval, _player.isMovingLeft());
	_player.move(glm::vec3(_player.getXVelocity(), _player.getYVelocity(), 0) * glm::vec3(time_interval));

	return done && isFinished();
}

bool World::isFinished(){
	// TODO
	return true;
}

