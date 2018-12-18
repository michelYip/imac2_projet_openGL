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
	~Character();


	void collectCoin(Coin c);
	
};

#endif