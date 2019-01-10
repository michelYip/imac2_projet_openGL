#include "World.hpp"

#include <algorithm>

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
	_player = Character(glm::vec3(start.x		, 5		, start.y),
						glm::vec3(start.x - 0.5	, 5.1	, start.y - 0.5),
						glm::vec3(start.x + 0.5	, 6		, start.y + 0.5));
}

//Set map with a reference
void World::setMap(const Map & map){
	_map = map;
}

//Return the current map
Map World::getMap() const{
	return _map;
}

//Check if the end of the map is reached
bool World::endOfMapReached() const{
	std::vector<glm::vec2> v = _map.getEndPoints();
	for (int i = 0; i < v.size(); i++){
		if (v[i].y < _player.position().z) return true;
	}
	return false;
}

//Change the current map to the next one
void World::switchMap(){
	std::vector<float> distToEnd;
	std::vector<glm::vec2> v = _map.getEndPoints();
	
	for (int i = 0; i < v.size(); i++)
		distToEnd.push_back(abs(glm::length(_player.position() - glm::vec3(v[i].x, 0, v[i].y))));
	
	std::vector<float>::iterator it = std::min_element(std::begin(distToEnd), std::end(distToEnd));
    int nextMapIndex = std::distance(std::begin(distToEnd), it);

	_map = _map.getNextMaps()[nextMapIndex];

	_map.appendMaps();

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
	float distance = _worldSpeed * time_interval;

	_map.moveMap(-distance);

	if ((_player.isMovingLeft() && _player.isMovingRight()) ||
		(!_player.isMovingLeft() && !_player.isMovingRight()))
	{
		_player.decelerateX(time_interval);
	}
	else _player.accelerateX(time_interval, _player.isMovingLeft());

	_player.move(glm::vec3(_player.getXVelocity(), _player.getYVelocity(), 0) * glm::vec3(time_interval));
	
	for(std::vector<Object>::iterator it = _map.objectList().begin(); it != _map.objectList().end(); it++){
		if (Physic::getInstance()->checkCollision(_player, *it)){
			glm::vec3 dir = _player.position() - it->position();
			glm::vec3 xzDir = glm::vec3(dir.x, 0, dir.z) * glm::vec3(KNOCKBACK_VALUE);
			_player.move(xzDir);
		}
		if (Physic::getInstance()->isGrounded(_player.boundingBox(), it->boundingBox())){
			_player.grounded();
			break;
		} else {
			_player.fall(time_interval);
		}
	}
	for(int i = 0; i < _map.coinList().size(); i++){
		if (Physic::getInstance()->checkCollision(_player, _map.coinList()[i])){
			_player.collectCoin(_map.coinList().at(i));
			_map.removeCoin(_map.coinList().at(i));
		}
	}

	if (endOfMapReached()){
		switchMap();
	}
	return done && isFinished();
}

bool World::isFinished(){
	// TODO
	return true;
}

