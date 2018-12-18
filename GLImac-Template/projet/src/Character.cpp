#include "Character.hpp"

Character::Character()
:MovingObject(),
_collectedCoins()
{}

Character::Character(const glm::vec3 & position,
					const glm::vec3 & lower,
					const glm::vec3 & upper)
:MovingObject(position, lower, upper),
_collectedCoins()
{}

void Character::collectCoin(Coin c){
	_collectedCoins.push_back(c);
}