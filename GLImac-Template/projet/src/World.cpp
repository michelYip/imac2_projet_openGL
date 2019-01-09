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
	_player = Character(glm::vec3(start.x, 5,start.y),
						glm::vec3(start.x - 0.5, 5.1, start.y - 0.5),
						glm::vec3(start.x + 0.5, 6, start.y + 0.5));
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
	

	for(std::vector<Object>::iterator it = _map.getObjectList().begin(); it != _map.getObjectList().end(); it++){
		if (Physic::getInstance()->checkCollision(_player.boundingBox(), it->boundingBox())){
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
	
	return done && isFinished();
}

bool World::isFinished(){
	// TODO
	return true;
}

