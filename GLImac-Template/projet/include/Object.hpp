#ifndef _OBJECT_ 
#define _OBJECT_

#include <iostream>
#include <glm/glm.hpp>
#include "Collider.hpp"

class Object
{
protected: 
	Collider _boundingBox;
	glm::vec3 _position;
	glm::vec3 _size; 

public:
	Object()
	:Object(glm::vec3(),glm::vec3(), Collider())
	{}
	
	Object(glm::vec3 position, glm::vec3 size, Collider boundingBox)
	:_position(position),_size(size),_boundingBox(boundingBox)
	{}
	
	~Object() = default;


	//GETTERS & SETTERS
	const Collider boundingBox() const {return _boundingBox;} 
	const glm::vec3 position() const {return _position;} 
	const glm::vec3 size() const {return _size;} 

	//PUBLICS FUNCTIONS 


	//OPERATORS
	friend std::ostream& operator<<(std::ostream &os, const Object &p);	
};

#endif