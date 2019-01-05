#ifndef _COLLIDER_ 
#define _COLLIDER_

#include <iostream>
#include <glm/glm.hpp>

const unsigned int DIM = 3;

/// \class Collider
/// \bried Collider bouding box of an Object
class Collider
{
private: 
	glm::vec3 _lower;
	glm::vec3 _upper;

public:
	//CONSTRUCTOR & DESTRUCTOR

	//Default constructor
	Collider();

	//Reference constructor
	Collider(const Collider & other);
	
	//Parameters constructor
	Collider(const glm::vec3 & lower, const glm::vec3 & upper);
	
	//Default constructor
	~Collider() = default;
	
	//OPERATOR

	//Output stream
	friend std::ostream& operator<<(std::ostream &os, const Collider &c);

	//Comparison operator
	bool operator==(const Collider & other);

	//PUBLIC METHODS

	//Compute the center of the bounding box
	inline glm::vec3 getCenter() const;

	//Return the intersection between two bounding boxes
	Collider intersect(const Collider & other);

	//Check if a bounding box is empty
	bool empty() const;

	//Return the size of a bounding box
	glm::vec3 size() const;

	//Check the collision between two bounding boxes
	bool isColliding(const Collider & other);

	//Move a bounding box
	void moveCollider(const glm::vec3 & direction);
};

#endif