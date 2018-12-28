#include <glimac/glm.hpp>

using namespace glm;

class FreeflyCamera{
	private:
		vec3 _position;	// position caméra
		float _fPhi;	// coordonnées sphériques
		float _fTheta;

		vec3 _frontVector;
		vec3 _leftVector;
		vec3 _upVector;

		void computeDirectionVectors(){
			_frontVector = vec3(cos(_fTheta) * sin(_fPhi), sin(_fTheta), cos(_fTheta) * cos(_fPhi));
			_leftVector = vec3(sin(_fPhi + pi<float>() / 2), 0, cos(_fPhi + pi<float>() / 2));
			_upVector = cross(_frontVector, _leftVector);
		};

	public:
		// constructeur(s)
		FreeflyCamera(): _position(vec3(0, 0, 0)), _fPhi(pi<float>()), _fTheta(0){
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
			_fPhi += radians(degrees * 0.001);
			computeDirectionVectors();
		};
		void rotateUp(float degrees){
			// if(_fTheta+ degrees >= radians(-90.f) && _fTheta + degrees <= radians(90.f))
			 _fTheta += radians(degrees * 0.001);
			this->computeDirectionVectors();
		};

		mat4 getViewMatrix() const{
			return lookAt(this->_position, this->_position + this->_frontVector, _upVector);
		};

};