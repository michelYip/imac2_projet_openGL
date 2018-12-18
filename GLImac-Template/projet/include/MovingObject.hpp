#ifndef _MOVINGOBJECT_ 
#define _MOVINGOBJECT_

#include "Object.hpp"

const float MOVE_SPEED = 5.0f;

class MovingObject : public Object
{
protected: 
	float _travelingSpeed;
	float _sideVelocity;
	float _sideAcceleration;
	float _verticalVelocity;
	float _verticalAcceleration;

public:
	MovingObject()
	:Object(), _travelingSpeed(0.f),
	_sideVelocity(0.f), _sideAcceleration(0.f),
	_verticalVelocity(0.f), _verticalAcceleration(0.f)
	{}
	
	MovingObject(	const glm::vec3 & position, 
					const glm::vec3 & lower, 
					const glm::vec3 & upper);

	~MovingObject() = default;
	

	//GETTERS & SETTERS 
	const float speed() const {return _travelingSpeed;}


	//METHODS
	glm::vec3 direction() const;

	void move(const glm::vec3 & direction);

};

#endif