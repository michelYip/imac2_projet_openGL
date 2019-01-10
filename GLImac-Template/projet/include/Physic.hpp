#ifndef _PHYSIC_ 
#define _PHYSIC_

#include <iostream>
#include <string>

#include "Collider.hpp"

const float KNOCKBACK_VALUE = 0.05;
const float RAYCAST_LENGTH = 0.1;

/// \class Physic
/// \brief Physic of the Game, a singleton, only one Physic can be instancied at a time
class Physic
{
private:
	static Physic * physic; ///< Instance of Physic
	Physic(); ///< Private constructor
public:
	Physic(const Physic&) = delete;
	Physic & operator=(const Physic&) = delete;
	~Physic();

	/// \brief Return the instance of Physic as a reference to physic
	static Physic * getInstance() noexcept;

	/// \brief Check if two Colliders are colliding or not
	/// \param a, b: Colliders to check if they collide
	/// \return: True if the colliders collide, otherwise return false
	bool checkCollision(const Collider & a, const Collider & b);

	/// \brief Check if the collider a is touching another collider from above
	/// \return: True if a is touching other from above, otherwise return False
	bool isGrounded(const Collider & a, const Collider & other);

};

#endif