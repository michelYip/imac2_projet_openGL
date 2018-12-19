#include "MovingObject.hpp"

//Parameter constructor
MovingObject::MovingObject(	const glm::vec3 & position, 
							const glm::vec3 & lower, 
							const glm::vec3 & upper)
:Object(position, lower, upper), _travelingSpeed(MOVE_SPEED),
_sideVelocity(0.f), _sideAcceleration(0.f),
_verticalVelocity(0.f), _verticalAcceleration(0.f)
{}

//Return the direction of the movement
glm::vec3 MovingObject::direction() const{
	return glm::vec3(_sideVelocity, _verticalAcceleration, _travelingSpeed);
}

//Move the object to the direction
void MovingObject::move(const glm::vec3 & direction){
	_position += direction;
}