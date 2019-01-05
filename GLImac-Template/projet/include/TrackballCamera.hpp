#ifndef _TRACKBALLCAMERA_
#define _TRACKBALLCAMERA_


const float TRACKBALL_ROTATION_SPEED = 0.5;
#include "Camera.hpp"

/// \class TrackballCamera
/// \brief focuses on the character 
class TrackballCamera : public Camera{
	private:
		float _fDistance;	// distance par rapport au centre de la scène
		float _fAngleX;		// angle de la caméra autour de l'axe x
		float _fAngleY;		// de l'axe Y

	public:
		// constructeur(s)
		TrackballCamera():_fDistance(-10.f), _fAngleY(180.f),_fAngleX(20.f){}; 

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
			_fDistance += delta;
		};
		void rotateLeft(float degrees){
			float newAngleY = _fAngleY + degrees * TRACKBALL_ROTATION_SPEED;
			std::cout << newAngleY << std::endl;
			if(newAngleY >= 145.f && newAngleY <= 215.f)
				_fAngleY = newAngleY;
		};
		void rotateUp(float degrees){
			float newAngleX = _fAngleX + degrees * TRACKBALL_ROTATION_SPEED;
			if(newAngleX >= 0.f && newAngleX <= 45.f)
				_fAngleX =  newAngleX;
		};
		glm::mat4 getViewMatrix() const{
			glm::mat4 MVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, _fDistance));
			MVMatrix = glm::rotate(MVMatrix, -glm::radians(_fAngleY), glm::vec3(0, 1, 0));
			MVMatrix = glm::rotate(MVMatrix, -glm::radians(_fAngleX), glm::vec3(1, 0, 0));
			return MVMatrix;
		};
};

#endif