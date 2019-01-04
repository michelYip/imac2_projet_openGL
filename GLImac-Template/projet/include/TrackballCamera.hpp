#ifndef _TRACKBALLCAMERA_
#define _TRACKBALLCAMERA_

using namespace glm;
#include <glimac/glm.hpp>



class TrackballCamera{

	private:
		float _fDistance;	// distance par rapport au centre de la scène
		float _fAngleX;		// angle de la caméra autour de l'axe x
		float _fAngleY;		// de l'axe Y

	public:
		// constructeur(s)
		TrackballCamera():_fDistance(-10.f), _fAngleY(0.f),_fAngleX(0.f){}; 

		// getters
		inline const float getDistance() const{
			return _fDistance;
		};
		inline const float getAngleX() const{
			return _fAngleX;
		};
		inline const float getAngleY() const{
			return _fAngleY;
		};

		// méthodes
		void moveFront(float delta){
			this->_fDistance += delta;
		};
		void rotateLeft(float degrees){
			this->_fAngleY += degrees * 0.005;
		};
		void rotateUp(float degrees){
			this->_fAngleX += degrees * 0.005;
		};
		glm::mat4 getViewMatrix() const{
			glm::mat4 MVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, _fDistance));
			MVMatrix = glm::rotate(MVMatrix, -glm::radians(_fAngleY), glm::vec3(0, 1, 0));
			MVMatrix = glm::rotate(MVMatrix, -glm::radians(_fAngleX), glm::vec3(1, 0, 0));
			return MVMatrix;
		};
};

#endif