#ifndef _PHYSIC_ 
#define _PHYSIC_

#include <iostream>
#include <string>

#include "Collider.hpp"

const float KNOCKBACK_VALUE = 0.05;
const float RAYCAST_LENGTH = 0.1;

/// \class Physic
/// \bried Physic of the World
class Physic
{
private:
	static Physic * physic;
	Physic(); //Private constructor
public:
	Physic(const Physic&) = delete;
	Physic & operator=(const Physic&) = delete;
	~Physic();

	static Physic * getInstance() noexcept;

	bool checkCollision(const Collider & a, const Collider & b);

	bool isGrounded(const Collider & a, const Collider & other);

};

#endif