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
	virtual const std::string TEXTURE_FILE(){ return (_texture.size() == 0) ? Object::TEXTURE_FILE() : _texture;} ///< Texture file
	virtual const std::string OBJ_FILE(){return "character.obj";} ///< Mesh file

private: 
	std::vector<Coin> _collectedCoins; ///< List of coins collected by the character
	
	bool _movingLeft; ///< Check if the character is moving to the left
	bool _movingRight; ///< Check if the character is moving to the right
	bool _isGrounded; ///< Check if the character is touching the ground
	bool _isJumping; ///< Check if the character is jumping
	bool _isCrouching; ///< Check if the character is crouching
	std::string _texture; ///< Texture name

public:
	Character();

	///param position: Position of the character
	///param lower: Lower point of the character bounding box
	///param upper: Upper poinr of the character bounding box
	Character(	const glm::vec3 & position,
				const glm::vec3 & lower,
				const glm::vec3 & upper);
	~Character() = default;

	//GETTERS & SETTERS
	inline bool isMovingLeft() const {  return _movingLeft; }
	inline bool isMovingRight() const { return _movingRight; }
	inline void movingLeft() { _movingLeft  = !_movingLeft;  }
	inline void movingRight(){ _movingRight = !_movingRight; }
	inline bool isGrounded()  const { return _isGrounded; }
	inline bool isJumping()   const { return _isJumping;  }
	inline bool isCrouching() const { return _isCrouching;}
	inline void grounded() { _isGrounded = true; _yVelocity = 0; }

	void texture(const std::string &texture){ 
		_texture = texture;
		loadMesh();
	}
	
	//PUBLICS FUNCTIONS
	/// \brief Decrease the horizontal velocity over time until it reach 0
	/// \param time_interval: time interval spent between iteration
	void decelerateX(const float & time_interval);

	// \brief Increase the horizontal velocity over time until it reach maximum velocity
	/// \param time_interval: time interval spent between iteration
	void accelerateX(const float & time_interval, const bool & left);

	/// \brief Increase the vertical velocity
	void jump();

	/// \brief Decrease the vertical velocity until the character touch the ground
	/// \param time_interval: time interval spent between iteration
	void fall(const float & time_interval);

	//Add coin value to the collected coin
	void collectCoin(Coin c);
	inline int totalCoin() const { return _collectedCoins.size() * COIN_VALUE;}
};

#endif