#include "MovingObject.hpp"

//Parameter constructor
MovingObject::MovingObject(	const glm::vec3 & position, 
							const glm::vec3 & lower, 
							const glm::vec3 & upper)
:Object(position, lower, upper),
_xVelocity(0.f),
_yVelocity(0.f)
{}

//Move the object to the direction
void MovingObject::move(const glm::vec3 & direction){
	_position += direction;
	_boundingBox.moveCollider(direction);
}