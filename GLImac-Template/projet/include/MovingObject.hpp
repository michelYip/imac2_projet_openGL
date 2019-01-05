#ifndef _MOVINGOBJECT_ 
#define _MOVINGOBJECT_

#include "Object.hpp"

const float MOVE_SPEED = 5.0f;


/// \class MovingObject
/// \bried Abstract class of an object able to move 
class MovingObject : public Object
{
protected:
	float _xVelocity;
	float _yVelocity;

public:
	//CONSTRUCTOR

	//Default constructor
	MovingObject()
	:Object(),
	_xVelocity(0.f), 
	_yVelocity(0.f)
	{}
	
	//Parameter constructor
	MovingObject(	const glm::vec3 & position, 
					const glm::vec3 & lower, 
					const glm::vec3 & upper);

	//Default destructor
	~MovingObject() = default;

	//GETTERS & SETTERS
	inline float getXVelocity() const { return _xVelocity; }
	inline float getYVelocity() const { return _yVelocity; }

	//METHODS

	//Move the object to the direction
	void move(const glm::vec3 & direction);

};

#endif