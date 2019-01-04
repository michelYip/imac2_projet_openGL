#ifndef _FREEFLYCAMERA_
#define _FREEFLYCAMERA_

#include <glimac/glm.hpp>

class FreeflyCamera{
	private:
		glm::vec3 _position;	// position caméra
		float _fPhi;	// coordonnées sphériques
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
		// constructeur(s)
		FreeflyCamera(): _position(glm::vec3(0, 0, 1)), _fPhi(0), _fTheta(0){
			this->computeDirectionVectors();
		};

		// méthodes
		void moveLeft(float t){
			this->_position += t * _leftVector;
		};
		void moveFront(float t){
			this->_position += t * _frontVector;
		};
		void rotateLeft(float degrees){
			// if(_fPhi + degrees >= radians(90.f) && _fPhi + degrees <= radians(270.f)) 
			_fPhi += glm::radians(degrees * 0.001);
			computeDirectionVectors();
		};
		void rotateUp(float degrees){
			// if(_fTheta+ degrees >= radians(-90.f) && _fTheta + degrees <= radians(90.f))
			 _fTheta += glm::radians(degrees * 0.001);
			this->computeDirectionVectors();
		};

		glm::mat4 getViewMatrix() const{
			return glm::lookAt(this->_position, this->_position + this->_frontVector, _upVector);
		};

};

#endif