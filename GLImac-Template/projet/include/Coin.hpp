#ifndef _COIN_ 
#define _COIN_


#include "StaticObject.hpp"

const int COIN_GROUNDED_THRESHOLD = 10;
const int COIN_AIRBORN_THRESHOLD  = 20;
const float COIN_FLOAT_HEIGHT = 1.5;
const int COIN_HEIGHT_MARGIN = 5;

/// \class Coin
/// \brief Coin present on the Map that add money to the Player at the end of every Game try
class Coin : public StaticObject
{
protected:
	virtual const std::string TEXTURE_FILE(){return "green.png";}
	// virtual const std::string OBJ_FILE(){return "character.obj";}

public:
	Coin();
	Coin(const int & x, const int & y, const int & altitude);
	Coin(const Coin &coin);
	~Coin() = default;
	
};

#endif