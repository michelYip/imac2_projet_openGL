#ifndef _PHYSIC_ 
#define _PHYSIC_

#include <iostream>
#include <string>

#include "Collider.hpp"
#include "Character.hpp"
#include "Object.hpp"

const float KNOCKBACK_VALUE = 0.05;
const float RAYCAST_LENGTH = 0.2;

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

	bool checkCollision(const Character & a, const Object & b);
	
	bool isGrounded(const Collider & a, const Collider & other);

};

#endif