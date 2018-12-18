#include "MovingObject.hpp"

void MovingObject::move(glm::vec3 position){
	_position += position;
}