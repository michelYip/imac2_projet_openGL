#ifndef _CHARACTER_ 
#define _CHARACTER_

#include <vector>
#include "MovingObject.hpp"
#include "Coin.hpp"

class Character : public MovingObject
{
private: 
	std::vector<Coin> _collectedCoins;
public:
	Character();
	Character(	const glm::vec3 & position,
				const glm::vec3 & lower,
				const glm::vec3 & upper);
	~Character() = default;

	//Add coin value to the collected coin
	void collectCoin(Coin c);
	
};

#endif