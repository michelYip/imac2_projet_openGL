#ifndef _COLLIDER_ 
#define _COLLIDER_

#include <iostream>
#include <glm/glm.hpp>

const unsigned int DIM = 3;

class Collider
{
private: 
	glm::vec3 _lower;
	glm::vec3 _upper;

public:
	Collider();

	Collider(const Collider & other);
	
	Collider(const glm::vec3 & lower, const glm::vec3 & upper);
	
	~Collider() = default;
	
	friend std::ostream& operator<<(std::ostream &os, const Collider &c);

	inline glm::vec3 getCenter() const;

	Collider intersect(const Collider & other);

	bool empty() const;

	glm::vec3 size() const;

	bool isColliding(const Collider & other);

	void moveCollider(const glm::vec3 & direction);

	bool operator==(const Collider & other);
};

#endif