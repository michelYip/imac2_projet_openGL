#ifndef _TRACKBALLCAMERA_
#define _TRACKBALLCAMERA_


const float TRACKBALL_ROTATION_SPEED = 0.5;
#include "Camera.hpp"

/// \class TrackballCamera
/// \brief focuses on the character 
class TrackballCamera : public Camera{
	private:
		float _fDistance;	///< distance with the center of the scene
		float _fAngleX;		///< angle around x-axis
		float _fAngleY;		///< angle around y-axis

	public:
		// constructeur(s)
		TrackballCamera():_fDistance(-7.f), _fAngleY(180.f),_fAngleX(15.f){}; 

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

		/// \brief zooms in or out
		void moveFront(float delta){
			float newDistance = _fDistance + delta;
			if(newDistance < -3.f && newDistance > -15.f)
				_fDistance = newDistance;
		};
		/// \brief makes the camera rotate to left
		/// \brief to the right if negative
		void rotateLeft(float degrees){
			float newAngleY = _fAngleY + degrees * TRACKBALL_ROTATION_SPEED;
			if(newAngleY >= 145.f && newAngleY <= 215.f)
				_fAngleY = newAngleY;
		};
		/// \brief makes the camera rotate up
		/// \brief down if negative
		void rotateUp(float degrees){
			float newAngleX = _fAngleX + degrees * TRACKBALL_ROTATION_SPEED;
			if(newAngleX >= 0.f && newAngleX <= 45.f)
				_fAngleX =  newAngleX;
		};
		/// \brief returns matrix camera for view according to settings
		glm::mat4 getViewMatrix() const{
			glm::mat4 MVMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, _fDistance));
			MVMatrix = glm::rotate(MVMatrix, -glm::radians(_fAngleY), glm::vec3(0, 1, 0));
			MVMatrix = glm::rotate(MVMatrix, -glm::radians(_fAngleX), glm::vec3(1, 0, 0));
			return MVMatrix;
		};
		/// \brief executes methods to change parameters when motion of the camera is detected
		void motion(const float &xrel, const float &yrel){
			if(!_locked){
				rotateLeft(xrel);
				rotateUp(yrel);	
			}
		}
		/// \brief makes camera zoom in
		void zoomIn(){
			if(!_locked)
				moveFront(ZOOM_SPEED);
		}
		/// \brief makes camera zoom out
		void zoomOut(){
			if(!_locked)
				moveFront(-ZOOM_SPEED);
		}
};

#endif