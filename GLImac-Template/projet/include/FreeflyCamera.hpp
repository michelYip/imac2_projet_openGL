#ifndef _FREEFLYCAMERA_
#define _FREEFLYCAMERA_

#include <glimac/glm.hpp>
#include <iostream>

const float FREEFLY_ROTATION_SPEED = 0.5;

#include "Camera.hpp"

/// \class FreeflyCamera
/// \brief view from character's eyes 
class FreeflyCamera : public Camera{
	private:
		glm::vec3 _position;	
		float _fPhi;	
		float _fTheta;

		glm::vec3 _frontVector;
		glm::vec3 _leftVector;
		glm::vec3 _upVector;

		void computeDirectionVectors(){
			_frontVector = glm::vec3(glm::cos(_fTheta) * glm::sin(_fPhi), glm::sin(_fTheta), glm::cos(_fTheta) * glm::cos(_fPhi));
			_leftVector = glm::vec3(sin(_fPhi + glm::pi<float>() / 2), 0, glm::cos(_fPhi + glm::pi<float>() / 2));
			_upVector = glm::cross(_frontVector, _leftVector);
		};

	public:
		// CONSTRUCTORS(S)
		FreeflyCamera(): _position(glm::vec3(0, 1, 1.5)), _fPhi(0), _fTheta(0){
			this->computeDirectionVectors();
		};

		// METHODS
		void moveLeft(float t){
			this->_position += t * _leftVector;
		};
		void moveFront(float t){
			this->_position += t * _frontVector;
		};
		void rotateLeft(float degrees){
			float newPhi = _fPhi + glm::radians(degrees * FREEFLY_ROTATION_SPEED);
			if(newPhi <= glm::pi<float>() / 4.f && newPhi >= - glm::pi<float>() / 4.f)
				_fPhi = newPhi;
			computeDirectionVectors();
		};
		void rotateUp(float degrees){
			float newTheta = _fTheta + glm::radians(degrees * FREEFLY_ROTATION_SPEED);
			if(newTheta <= glm::pi<float>() / 4.f && newTheta >= - glm::pi<float>() / 4.f)
				_fTheta = newTheta;
			computeDirectionVectors();
		};

		glm::mat4 getViewMatrix() const{
			return glm::lookAt(this->_position, this->_position + this->_frontVector, _upVector);
		};

		void motion(const float &xrel, const float &yrel){
			if(!_locked){
				rotateLeft(xrel);
				rotateUp(yrel);				
			}

		}
		void updatePos(const glm::vec3 &position){
			_position = position + glm::vec3(0, 1, 1.5);
			computeDirectionVectors();
		}
};

#endif