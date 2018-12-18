#ifndef _COLLIDER_ 
#define _COLLIDER_

#include <iostream>
#include <glm/glm.hpp>

class Collider
{
private: 
	glm::vec3 _size;

public:
	Collider()
	:_size(glm::vec3())
	{}
	
	Collider(glm::vec3 size)
	:_size(size)
	{}
	
	~Collider() = default;
	
	friend std::ostream& operator<<(std::ostream &os, const Collider &c);
};

#endif