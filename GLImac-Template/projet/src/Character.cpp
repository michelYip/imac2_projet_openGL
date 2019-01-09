#include "Character.hpp"

Character::Character()
:MovingObject(),
_collectedCoins()
{loadMesh();}

Character::Character(const glm::vec3 & position,
					const glm::vec3 & lower,
					const glm::vec3 & upper)
:MovingObject(position, lower, upper),
_collectedCoins(),
_movingLeft(false),
_movingRight(false),
_isGrounded(false),
_isJumping(false),
_isCrouching(false)
{loadMesh();}

//Decrease the velocity on X axis until it reach O
void Character::decelerateX(const float & time_interval){
	const float deceleration_rate = DECELERATION * time_interval;
	if (abs(_xVelocity) - deceleration_rate <= 0) _xVelocity = 0;
	else _xVelocity += (_xVelocity < 0) ? deceleration_rate : -deceleration_rate;
}

//Increase the velocity on X axis until it reach max velocity
void Character::accelerateX(const float & time_interval, const bool & left){
	const float acceleration_rate = ACCELERATION * time_interval;
	if (!left) _xVelocity -= acceleration_rate;
	else _xVelocity += acceleration_rate; 
	if (abs(_xVelocity) > MAX_VELOCITY) _xVelocity = (_xVelocity < 0) ? -MAX_VELOCITY : MAX_VELOCITY;
}

//Increase the velocity on Y axis
void Character::jump(){
	_yVelocity = JUMP_POWER;
	_isGrounded = false;
}

//Decrease the velocity on Y axis until the player touch the ground
void Character::fall(const float & time_interval){
	const float fall_speed = GRAVITY * time_interval;
	_isGrounded = false;
	_yVelocity = (_yVelocity < -MAX_VELOCITY) ? -MAX_VELOCITY : _yVelocity - fall_speed; 
}

//Add coin value to the collected coin
void Character::collectCoin(Coin c){
	_collectedCoins.push_back(c);
}