#ifndef _OBJECT_ 
#define _OBJECT_

#include <iostream>
#include <glimac/BBox.hpp>
#include <glm/glm.hpp>
#include "Collider.hpp"

class Object
{
protected: 
	Collider _boundingBox;
	glm::vec3 _position;

public:
	Object()
	:Object(glm::vec3(), Collider())
	{}
	
	Object(const glm::vec3 & position, const Collider & boundingBox);

	Object(const glm::vec3 & position, const glm::vec3 & _lower, const glm::vec3 & _upper);
	
	~Object() = default;


	//GETTERS & SETTERS
	const Collider boundingBox() const {return _boundingBox;} 
	const glm::vec3 position() const {return _position;}

	//PUBLICS FUNCTIONS 

	//OPERATORS
	friend std::ostream& operator<<(std::ostream &os, const Object &o);

	bool operator==(const Object & other);
};

#endif