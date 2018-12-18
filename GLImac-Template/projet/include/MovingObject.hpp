#ifndef _MOVINGOBJECT_ 
#define _MOVINGOBJECT_

#include "Object.hpp"

class MovingObject : public Object
{
private: 
	float _speed;

public:
	MovingObject()
	:Object(), _speed(0.f)
	{}
	
	MovingObject(glm::vec3 position, glm::vec3 size, float speed)
	:Object(position, size, Collider(size)), _speed(speed)
	{}

	~MovingObject();
	

	//GETTERS & SETTERS 
	const float speed() const {return _speed;}


	void move(glm::vec3 position);
};

#endif