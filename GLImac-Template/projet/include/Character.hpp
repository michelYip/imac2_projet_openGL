#ifndef _CHARACTER_ 
#define _CHARACTER_

#include <vector>
#include "MovingObject.hpp"
#include "Coin.hpp"

const float MAX_VELOCITY = 10;
const float ACCELERATION = 40;
const float DECELERATION = 40;

/// \class Character
/// \brief Character present on the Map controlled by the Player
class Character : public MovingObject
{
protected:
	virtual const std::string TEXTURE_FILE(){return _texture;}
	virtual const std::string OBJ_FILE(){return "character.obj";}

private: 
	std::vector<Coin> _collectedCoins;
	bool _movingLeft;
	bool _movingRight;
	bool _isGrounded;
	bool _isJumping;
	bool _isCrouching;
	std::string _texture;

public:
	Character();
	Character(std::string texture):_texture(texture){}
	Character(	const glm::vec3 & position,
				const glm::vec3 & lower,
				const glm::vec3 & upper);
	~Character() = default;

	inline bool isMovingLeft() const { return _movingLeft; }
	inline bool isMovingRight() const { return _movingRight; }

	inline void movingLeft() { _movingLeft = !_movingLeft; }
	inline void movingRight(){ _movingRight = !_movingRight; }

	std::string &texture(){return _texture;}
	
	//Decrease the velocity on X axis until it reach 0
	void decelerateX(const float & time_interval);

	//Increase the velocity on X axis until it reach max velocity
	void accelerateX(const float & time_interval, const bool & left);

	//Add coin value to the collected coin
	void collectCoin(Coin c);
};

#endif