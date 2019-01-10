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
		glm::vec3 _position; ///< Position of the camera
		float _fPhi; ///< Angle on axis Y
		float _fTheta; //< Angle on axis X

		glm::vec3 _frontVector; ///< points to the front of the camera
		glm::vec3 _leftVector; ///< points to the left of the camera
		glm::vec3 _upVector; ///< points above the camera

		/// \brief calculates vectors according to parameters
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
		/// \brief makes camera look to the left
		/// \brief makes camera look to the right if negative
		void rotateLeft(float degrees){
			float newPhi = _fPhi + glm::radians(degrees * FREEFLY_ROTATION_SPEED);
			if(newPhi <= glm::pi<float>() / 4.f && newPhi >= - glm::pi<float>() / 4.f)
				_fPhi = newPhi;
			computeDirectionVectors();
		};
		/// \brief makes camera look up
		/// \brief makes camera look down if negative
		void rotateUp(float degrees){
			float newTheta = _fTheta + glm::radians(degrees * FREEFLY_ROTATION_SPEED);
			if(newTheta <= glm::pi<float>() / 4.f && newTheta >= - glm::pi<float>() / 4.f)
				_fTheta = newTheta;
			computeDirectionVectors();
		};

		/// \brief returns matrix camera for view according to settings
		glm::mat4 getViewMatrix() const{
			return glm::lookAt(this->_position, this->_position + this->_frontVector, _upVector);
		};

		/// \brief executes methods to change parameters when motion of the camera is detected
		void motion(const float &xrel, const float &yrel){
			if(!_locked){
				rotateLeft(xrel);
				rotateUp(yrel);				
			}
		}

		/// \brief updates position of the camera
		void updatePos(const glm::vec3 &position){
			_position = position + glm::vec3(0, 1, 1.5);
			computeDirectionVectors();
		}
};

#endif