#ifndef _COLLIDER_ 
#define _COLLIDER_

#include <iostream>
#include <glm/glm.hpp>

const unsigned int DIM = 3;

/// \class Collider
/// \brief Collider bouding box of an Object
class Collider
{
private: 
	glm::vec3 _lower; ///< Lower point of the bounding box
	glm::vec3 _upper; ///< Upper point of the bounding box

public:
	//CONSTRUCTOR & DESTRUCTOR

	Collider();

	/// \brief Reference constructor
	Collider(const Collider & other);
	
	/// \brief Parameters constructor
	Collider(const glm::vec3 & lower, const glm::vec3 & upper);
	
	~Collider() = default;

	//GETTER & SETTER
	inline glm::vec3 lower() const { return _lower; }
	inline glm::vec3 upper() const { return _upper; }
	
	//OPERATOR

	//Output stream
	friend std::ostream& operator<<(std::ostream &os, const Collider &c);

	//Comparison operator
	bool operator==(const Collider & other);

	//Equal operator
	Collider & operator=(const Collider & other);

	//Addition operator
	Collider operator+(const glm::vec3 & v);

	//PUBLIC METHODS

	/// \brief Compute the center of the bounding box
	/// \return: the center of the bounding box
	inline glm::vec3 getCenter() const;

	/// \brief Take the intersection of two collider to make another collider
	/// \param other: the collider to intersect
	/// \return: the intersection between two bounding boxes
	Collider intersect(const Collider & other) const;

	/// \brief Check if a bounding box is empty
	/// \return: True if the collider is empty, otherwise return False 
	bool empty() const;

	/// \brief Compute the size of a collider
	/// \return: the size of a collider
	glm::vec3 size() const;

	/// \brief Check the collision between two colliders
	/// \return: True if the colliders are collinding, otherwise return False
	bool isColliding(const Collider & other) const;

	/// \brief Move a Collider to the given direction
	/// \param direction: The direction in which the Collider is going to
	void moveCollider(const glm::vec3 & direction);
};

#endif