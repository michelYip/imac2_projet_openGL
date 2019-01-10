#ifndef _CHARACTER_ 
#define _CHARACTER_

#include <vector>
#include "MovingObject.hpp"
#include "Coin.hpp"

const float MAX_VELOCITY = 25;
const float ACCELERATION = 125;
const float DECELERATION = 125;

const float JUMP_POWER 	   = 90;
const float GRAVITY 	   = 10;

/// \class Character
/// \brief Character present on the Map controlled by the Player
class Character : public MovingObject
{
protected:
	virtual const std::string TEXTURE_FILE(){ return (_texture.size() == 0) ? Object::TEXTURE_FILE() : _texture;}
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
	Character(	const glm::vec3 & position,
				const glm::vec3 & lower,
				const glm::vec3 & upper);
	~Character() = default;

	inline bool isMovingLeft() const {  return _movingLeft; }
	inline bool isMovingRight() const { return _movingRight; }

	inline void movingLeft() { _movingLeft  = !_movingLeft;  }
	inline void movingRight(){ _movingRight = !_movingRight; }

	void texture(const std::string &texture){ 
		_texture = texture;
		loadMesh();
	}
	
	//Decrease the velocity on X axis until it reach 0
	void decelerateX(const float & time_interval);

	//Increase the velocity on X axis until it reach max velocity
	void accelerateX(const float & time_interval, const bool & left);


	inline bool isGrounded()  const { return _isGrounded; }
	inline bool isJumping()   const { return _isJumping;  }
	inline bool isCrouching() const { return _isCrouching;}

	inline void grounded() { _isGrounded = true; _yVelocity = 0; }

	//Increase the velocity on Y axis
	void jump();

	//Decrease the velocity on Y axis until the player touch the ground
	void fall(const float & time_interval);

	//Add coin value to the collected coin
	void collectCoin(Coin c);
};

#endif